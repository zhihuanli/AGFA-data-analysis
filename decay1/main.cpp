
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
      std::cout<< "eg. ./xxx  [run number]" <<std::endl;
      exit(1);
    }
  
  int run = atoi(argv[1]);
  char wloop='a';
  // char wloop='b';
  cout<<"input:"<<Form("dssd%d.root",run)<<endl;
  auto ipf = new TFile(Form("../dssd/dssd%d.root",run),"READ");
  auto ipt = (TTree*)ipf->Get("opt");

  auto opf = new TFile(Form("decay%d%c.root",run,wloop),"RECREATE");
  auto opt = new TTree("opt","opt");
  cout<<"output:"<<Form("decay%d%c.root",run,wloop)<<endl;;
  auto it = new tree(ipt);
  if(wloop=='a') it->Loop1(opt,run);
  if(wloop=='b') it->Loop2(opt,run);
  opt->Write();
  opf->Close();
  
  return 0;
}

