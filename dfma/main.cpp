
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
  if(argc!=2) {
    cout<<"./"<<argv[0]<<"run_number"<<endl;
    return 0;
  }
  int run=atoi(argv[1]);
  cout<<"input:"<<Form("data%d.root",run)<<endl;
  auto ipf = new TFile(Form("data%d.root",run),"READ");
  auto ipt = (TTree*)ipf->Get("opt");

  auto opf = new TFile(Form("dssd%d.root",run),"RECREATE");
  auto opt = new TTree("opt","opt");
  cout<<"output:"<<Form("dssd%d.root",run)<<endl;;
  auto it = new tree(ipt);
  it->Loop(opt);

  opt->Write();
  opf->Close();
  
  return 0;
}

