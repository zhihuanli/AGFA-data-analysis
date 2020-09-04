#include "tree.h"
using namespace std;

void tree::Init()
{
  if (ipt == NULL)
    return;

  br_gs = 0;
  br_mw = 0;
  br_x = 0;
  br_y = 0;
  br_box = 0;
  br_xa = 0;
  br_de = 0;

  ipt->SetBranchAddress("gs", &br_gs);
  ipt->SetBranchAddress("mw", &br_mw);
  ipt->SetBranchAddress("de", &br_de);
  ipt->SetBranchAddress("x", &br_x);
  ipt->SetBranchAddress("y", &br_y);
  ipt->SetBranchAddress("box", &br_box);
  ipt->SetBranchAddress("xa", &br_xa);
  ipt->SetBranchAddress("xesum", &xesum);
  ipt->SetBranchAddress("yesum", &yesum);
  ipt->SetBranchAddress("desum", &desum);
  ipt->SetBranchAddress("mesum", &mesum);
}

void tree::GetEvent()
{
  mr.clear();
  md.clear();

  Int_t rx = -1;
  Int_t ry = -1;
  ULong64_t rts = 0;

  Long64_t nentries = ipt->GetEntriesFast();
  for (Long64_t jentry = 0; jentry < nentries; jentry++)
  {
    ipt->GetEntry(jentry);
    if ((*br_x).size() == 0)
      continue;
    //front-back correlation
    if (xesum < 14000 && abs(xesum - yesum) > 200)
      continue;
    if (xesum > 14000 && abs(xesum - yesum) > 500)
      continue;
    Double_t de = 0;
    if ((*br_de).size() > 0)
      de = (*br_de)[0].e;
    //calculate x,y positions
    double x, y;
    double xeid = 0;
    double xse = 0;
    for (int i = 0; i < (*br_x).size(); i++)
    {
      xeid += (*br_x)[i].id * (*br_x)[i].e;
      xse += (*br_x)[i].e;
    }
    x = xeid / xse;
    double yeid = 0;
    double yse = 0;
    for (int i = 0; i < (*br_y).size(); i++)
    {
      yeid += (*br_y)[i].id * (*br_y)[i].e;
      yse += (*br_y)[i].e;
    }
    y = yeid / yse;
    if ((mesum > 10 || de > 4000) && xesum > 10000 && xesum < 50000)
    { //recoil
      Recoil r;
      r.e = xesum;
      r.x = x;
      r.y = y;
      r.ts = (*br_x)[0].ts;
      for (int i = 0; i < (*br_gs).size(); i++)
      {
        r.ge.push_back((*br_gs)[i].e);
        r.gid.push_back((*br_gs)[i].id);
        r.gts.push_back((*br_gs)[i].ts);
      }
      mr[r.ts] = r;
    }
    if (mesum < 10 && de < 1000 && xesum < 10000)
    { //decay
      Decay d;
      d.e = xesum;
      d.x = x;
      d.y = y;
      d.ts = (*br_x)[0].ts;
      d.boxe = 0;
      if ((*br_box).size() > 0)
        d.boxe = (*br_box)[0].e;
      for (int i = 0; i < (*br_xa).size(); i++)
      {
        d.ge.push_back((*br_xa)[i].e);
        d.gid.push_back((*br_xa)[i].id);
        d.gts.push_back((*br_xa)[i].ts);
      }
      md[d.ts] = d;
    }

    if (jentry % 1000 == 0)
    {
      printf("Process %.2f %, %dk / %dk\r", Double_t(jentry) / nentries * 100.,
             jentry / 1000, nentries / 1000);
      fflush(stdout);
    }
  }
  cout << "The number of recoil/decay : " << mr.size() << "  " << md.size() << endl;
}

Int_t tree::GetPid(Double_t e)
{
  for (int i = 0; i < 13; i++)
  {
    if (e > peak[i] - 30 && e < peak[i] + 30)
      return i + 1;
  }
  return 0;
}

void tree::Loop1(TTree *opt_, Int_t run_)
{
  if (opt_ == NULL)
    return;
  opt = opt_;
  run = run_;
  BranchOpt();
  cout << "making recoil/decay evnts..." << endl;
  GetEvent();

  ULong64_t us = 100;
  ULong64_t ms = 1000 * us;
  ULong64_t sec = 1000 * ms;
  ULong64_t twindow1 = 0 * sec;   //100s
  ULong64_t twindow2 = 200 * sec; //100s
  int i = 0;
  irecoil = 0;
  cout << "recoil-decay correlation using Method A ..." << endl;
  printf("Decay Time Window = %.1f ms ~ %.1f ms\n", Long64_t(twindow1) / (1.0e5), Long64_t(twindow2) / (1.0e5));

  for (auto ia = mr.begin(); ia != mr.end(); ia++)
  {
    //recoil
    rx = ia->second.x;
    ry = ia->second.y;
    re = ia->second.e;
    rts = ia->second.ts;
    vge.clear();
    vgid.clear();
    vgts.clear();
    vge.swap(ia->second.ge);
    vgid.swap(ia->second.gid);
    vgts.clear();
    for (int i = 0; i < vge.size(); i++)
    {
      Long64_t tts = Long64_t(ia->second.gts[i] - rts) - 100 / sqrt(vge[i]) - 200;
      vgts.push_back(tts);
    }
    //recoil-decay correlation
    idecay = 0;
    auto ib = md.lower_bound(ia->first + twindow1);
    for (auto ic = ib; ic != md.end(); ic++)
    {
      if (ic->first >= ia->first + twindow2)
        break;
      double delx = abs(ic->second.x - ia->second.x);
      double dely = abs(ic->second.y - ia->second.y);
      if (delx > 0.95 || dely > 0.95)
        continue;
      //decay
      e = ic->second.e;
      pid = GetPid(e);
      if (pid == 0)
      {
        sprintf(spid, "other");
        tdecay = 100000;
      }
      else
      {
        tdecay = halflife[pid - 1];
        sprintf(spid, isotope[pid - 1]);
      }
      boxe = ic->second.boxe;
      x = ic->second.x;
      y = ic->second.y;
      ts = ic->second.ts;
      dt = Long64_t(ic->first - ia->first) / (1.0e5); //ms
      vce.clear();
      vcid.clear();
      vcts.clear();
      vce.swap(ic->second.ge);
      for (int i = 0; i < vce.size(); i++)
      {
        Long64_t tts = Long64_t(ic->second.gts[i] - ts) - 70 / sqrt(vce[i]) - 226;
        vcts.push_back(tts);
      }
      vcid.swap(ic->second.gid);
      opt->Fill();
      idecay++;
    }
    irecoil++;

    if (i % 500 == 0)
    {
      printf("Process %.2f %, %d / %d\r", Double_t(i) / mr.size() * 100.,
             i, mr.size());
      fflush(stdout);
    }
    i++;
  }
  cout << endl;
}

void tree::Loop2(TTree *opt_, Int_t run_)
{
  if (opt_ == NULL)
    return;
  opt = opt_;
  run = run_;
  BranchOpt();
  cout << "making recoil/decay evnts..." << endl;
  GetEvent();

  int i = 0;
  irecoil=0;
  cout << "recoil-decay correlation using Method B ..." << endl;
  cout<<mr.size()<<endl;
  for (auto ir = mr.begin(); ir != mr.end(); ir++)
  {
    //recoil
    rx = ir->second.x;
    ry = ir->second.y;
    rts = ir->second.ts;
    vge.clear();
    vgid.clear();
    vgts.clear();
    vge.swap(ir->second.ge);
    vgid.swap(ir->second.gid);
    vgts.clear();
    for (int i = 0; i < vge.size(); i++)
    {
      Long64_t tts = Long64_t(ir->second.gts[i] - rts) - 100 / sqrt(vge[i]) - 200;
      vgts.push_back(tts);
    }
    //recoil events
    idecay = 0;
    auto ir1 = mr.upper_bound(ir->first);
    while (ir1 != mr.end())
    {
      if (ir1->second.x == ir->second.x && ir1->second.y == ir->second.y)
      {
        break;
      }
      ir1++;
    }
    //decay events
    auto id = md.upper_bound(ir->first);
    while (id != md.end())
    {
      if (id->first > ir1->first)
      break;
      double delx = abs(id->second.x - ir->second.x);
      double dely = abs(id->second.y - ir->second.y);
      if (delx > 0.95 || dely > 0.95){
	id++;
        continue;}
      //decay
      e = id->second.e;
      pid = GetPid(e);
      if (pid == 0)
      {
        sprintf(spid, "other");
        tdecay = 100000;
      }
      else
      {
        tdecay = halflife[pid - 1];
        sprintf(spid, isotope[pid - 1]);
      }
      boxe = id->second.boxe;
      x = id->second.x;
      y = id->second.y;
      ts = id->second.ts;
      dt = Long64_t(id->first - ir->first) / (1.0e5); //ms
      vce.clear();
      vcid.clear();
      vcts.clear();
      vce.swap(id->second.ge);
      for (int i = 0; i < vce.size(); i++)
      {
        Long64_t tts = Long64_t(id->second.gts[i] - ts) - 70 / sqrt(vce[i]) - 226;
        vcts.push_back(tts);
      }
      vcid.swap(id->second.gid);
      opt->Fill();
      idecay++;
      id++;
    }
    irecoil++;
    if (i % 500 == 0)
    {
      printf("Process %.2f %, %d / %d\r", Double_t(i) / mr.size() * 100.,
             i, mr.size());
      fflush(stdout);
    }
    i++;
  }
  cout << endl;
}

void tree::BranchOpt()
{
  opt->Branch("run", &run, "run/I");

  opt->Branch("irecoil", &irecoil, "irecoil/I");
  opt->Branch("rx", &rx, "rx/D");
  opt->Branch("ry", &ry, "ry/D");
  opt->Branch("rts", &rts, "rts/L");
  opt->Branch("ge", &vge);
  opt->Branch("gts", &vgts);
  opt->Branch("gid", &vgid);

  opt->Branch("idecay", &idecay, "idecay/I");
  opt->Branch("pid", &pid, "pid/I");
  opt->Branch("spid", &spid, "spid[256]/C");
  opt->Branch("tdecay", &tdecay, "tdecay/D");
  opt->Branch("e", &e, "e/D");
  opt->Branch("x", &x, "x/D");
  opt->Branch("y", &y, "y/D");
  opt->Branch("ts", &ts, "ts/L");
  opt->Branch("boxe", &boxe, "boxe/D");
  opt->Branch("dt", &dt, "dt/D");

  opt->Branch("ce", &vce);
  opt->Branch("cts", &vcts);
  opt->Branch("cid", &vcid);
}
