
#include "tree.h"
#include <TTree.h>
#include <TFile.h>
#include <TMath.h>
#include <TString.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2)
    {
      std::cout<< "eg. ./xxx  [run number] [evtnum1] [evtnum2]" <<std::endl;
      exit(1);
    }
  
  int run = atoi(argv[1]);

  int ievt1=0;
  int ievt2=0;
  if(argc == 4) {
    ievt1=atoi(argv[2]);
    ievt2=atoi(argv[3]);
  }
 
  cout<<"input:"<<Form("data%d.root",run)<<endl;
  auto ipf = new TFile(Form("../gsort/data%d.root",run),"READ");
  auto ipt = (TTree*)ipf->Get("opt");

  auto opf = new TFile(Form("dssd%d.root",run),"RECREATE");
  auto opt = new TTree("opt","opt");
  cout<<"output:"<<Form("dssd%d.root",run)<<endl;;
  auto it = new tree(ipt);
  it->Loop(opt,Long64_t(ievt1),Long64_t(ievt2));

  opt->Write();
  opf->Close();
  
  return 0;
}

