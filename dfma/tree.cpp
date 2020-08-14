#include "tree.h"
using namespace std;

bool SortDS(dssd &a,dssd &b)
{
  return a.e > b.e;
}

bool Equal(dssd &a, dssd &b)
{
  return Long64_t(a.ts- b.ts)==0 && a.id==b.id;
}

void Unique(vector<dssd> &a) 
{
  a.erase(unique(a.begin(),a.end(),Equal),a.end());
}

void StripCut(vector<dssd> &a)
{
   for(auto it=a.begin();it!=a.end() ; ) {
     if(TMath::Abs(it->id-a[0].id)>1) 
       it=a.erase(it);
     else 
       ++it;
   }
}

void TsCut(vector<dssd> &a, vector<dssd> &b, int dts1,int dts2)
{
   if(b.size()>0) {   
     for(auto it=a.begin();it!=a.end() ; ) {
       int dts=Long64_t(it->ts-b[0].ts);
       if(dts<dts1 || dts>dts2) 
	 it=a.erase(it);
       else
	 ++it;
     }
   }
}

void tree::Init()
{
  if(ipt==NULL) return;
  br_dfma = 0;
  br_xa = 0;
  br_dgs = 0;
  ipt->SetBranchAddress("dfma",&br_dfma);
  ipt->SetBranchAddress("xa",&br_xa);
  ipt->SetBranchAddress("dgs",&br_dgs);

  ifstream readtxt;  
  int tmp1,tmp2;
  readtxt.open("dssd.map");//ramaping
  if(!readtxt.is_open())
    {
      std::cout<<"can't open file - dssd.map"<<std::endl;
    }
  while(!readtxt.eof())
    {
      readtxt>>tmp1>>tmp2;
      if(readtxt.eof()) break;//避免最后一个重复读取
      strip[tmp1] = tmp2-1;
    }
  readtxt.close();

}

void tree::Loop(TTree *opt_,Long64_t entryStart,Long64_t entryStop)
{
  if(opt_==NULL) return;
  opt = opt_;    
  BranchOpt();
  Long64_t TotalEntry = ipt->GetEntries();

  if(entryStart<0 || entryStop<0 || entryStop<=entryStart) {
    entryStart=0;
    entryStop=0;
  }
  if(entryStop==0 || entryStop >TotalEntry) entryStop=TotalEntry; 
     
  for(Long64_t jentry = entryStart ; jentry  < entryStop; jentry++){
      ipt->GetEntry(jentry);  

      //XA
      xavec.clear();
      xaavec.clear();

      for(int i=0;i<br_xa->size();i++) {
	Double_t e=(*br_xa)[i].e;
        ULong64_t ts=(*br_xa)[i].ts;//offset
        Int_t id=(*br_xa)[i].id;
        xa.e=e;
        xa.id=id;
        xa.ts=ts;
	if(e>20) xavec.push_back(xa);
      }

      //DGS
      gsvec.clear();
      for(int i=0;i<br_dgs->size();i++) {
	Double_t e=(*br_dgs)[i].e;
        ULong64_t ts=(*br_dgs)[i].ts;//offset
        Int_t id=(*br_dgs)[i].id;
        Int_t flag=(*br_dgs)[i].flag;//BGO
        gs.e=e;
        gs.id=id;
        gs.ts=ts;
	if(e>20 && flag==0) gsvec.push_back(gs);//no BGO
      }

      //DFMA
      xvec.clear();
      yvec.clear();
      bvec.clear();
      mvec.clear();
      pvec.clear();

      for(int i=0;i<br_dfma->size();i++) {

	Double_t e=(*br_dfma)[i].e;
        Double_t ch=(*br_dfma)[i].ch;
        ULong64_t ts=(*br_dfma)[i].ts;
        Int_t id=(*br_dfma)[i].id;
        Int_t flag=(*br_dfma)[i].flag;
  
	if(flag==1 && e>250) {//dssd-x
	    x.e=e;
	    x.id=id;
	    x.ts=ts;
	    xvec.push_back(x);
	  }
	if(flag==2 && e>250) {//dssd-y
	    y.e=e;
	    y.id=strip[id];
	    y.ts=ts;;
	    yvec.push_back(y);
	  }
	if(flag==3 && e>10){//si-box
	  box.e=e;
	  box.id=id;
	  box.ts=ts;
	  bvec.push_back(box);
	}
	if(flag==4 && ch>0) {//fp
	  pa.e=ch;
	  pa.id=id;
	  pa.ts=ts;
	  pvec.push_back(pa);
	}

	if(flag==5 && ch>0) {//mwpc
	  mw.e=ch;
	  mw.id=id;
	  mw.ts=ts;
	  mvec.push_back(mw);
	}
      }


   //remove identical events, which perhaps caused by bugs in Digital modules
      Unique(xvec);
      Unique(yvec);
      Unique(bvec);
      Unique(mvec);
      Unique(xavec);
      Unique(gsvec);
    
   //clover-addback
   double ge[5]={0,0,0,0,0};
   ULong64_t gts[5]={0,0,0,0,0};
   for(int i=0;i<xavec.size();i++) {
     int idet=xavec[i].id/4;
     if(gts[idet]==0) {
       ge[idet]=xavec[i].e;
       gts[idet]=xavec[i].ts;
     }
     else if(xavec[i].e>20 && TMath::Abs(Long64_t(gts[idet]-xavec[i].ts))<20) {
       ge[idet]+=xavec[i].e;
       gts[idet]=TMath::Min(gts[idet],xavec[i].ts);
     }
   }
   for(int i=0;i<5;i++){
     if(ge[i]<20) continue;
     xa.e=ge[i];
     xa.ts=gts[i];
     xa.id=i;
     xaavec.push_back(xa);
   }

   //sort vectors in descending order of energy	 
   sort(xvec.begin(),xvec.end(),SortDS);
   sort(yvec.begin(),yvec.end(),SortDS);
   sort(bvec.begin(),bvec.end(),SortDS);

   //remove noisy strips in dssd
   StripCut(xvec);
   StripCut(yvec);

   //time walk correction x.ts-320/sqrt(x.e)
   //remove the events outside of timewindow
   TsCut(xvec,xvec,-20,20);
   TsCut(yvec,xvec,-20,20);
   TsCut(bvec,xvec,-30,30);
   TsCut(mvec,xvec,5,45);
   TsCut(gsvec,xvec,180,250);
   TsCut(xavec,xvec,210,300);  
   TsCut(xaavec,xvec,210,300);  
   xesum=0;
   for(int i=0;i<xvec.size();i++)xesum+=xvec[i].e;
   yesum=0;
   for(int i=0;i<yvec.size();i++)yesum+=yvec[i].e;
   desum=min(xesum,yesum);//check resolution

   mesum=0;
   for(int i=0;i<mvec.size();i++)mesum+=mvec[i].e;

   bool bDSSD=0;
   if(xvec.size()>0 && yvec.size()>0) bDSSD=1; 

   bool bXA=0;
   if(xavec.size()>0) bXA=1; 

   bool bDGS=0;
   if(gsvec.size()>0) bDGS=1; 

   if(bDSSD || bXA || bDGS) opt->Fill();

   if((jentry-entryStart) % 1000 == 0) {

     printf("Process %.2f %, %dk / %dk\r",Double_t(jentry-entryStart)/(entryStop-entryStart)*100.,
	    (jentry-entryStart)/1000,(entryStop-entryStart)/1000);
     fflush(stdout);
   }

  }
}

void tree::BranchOpt()
{
  opt->Branch("xesum",&xesum,"xesum/D");
  opt->Branch("yesum",&yesum,"yesum/D");
  opt->Branch("desum",&desum,"desum/D");
  opt->Branch("mesum",&mesum,"mesum/D");
  opt->Branch("x",&xvec);
  opt->Branch("y",&yvec);
  opt->Branch("box",&bvec);//sibox
  //  opt->Branch("pa",&pvec);
  opt->Branch("mw",&mvec);//mwpc
  // opt->Branch("xa",&xavec);
  opt->Branch("xa",&xaavec);//clover-addback
  opt->Branch("gs",&gsvec);//gammasphere

}
