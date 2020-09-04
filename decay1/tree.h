#include <TTree.h>
#include <TFile.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct dssd
{
  Double_t e;
  Int_t id;
  ULong64_t ts;
} dssd;

typedef struct Recoil
{
  Double_t e;
  Int_t x,y;
  ULong64_t ts;
  vector<Double_t> ge;
  vector<ULong64_t> gts;
  vector<Int_t> gid;
} recoil;

typedef struct Decay
{
  Double_t e,boxe;
  Double_t dt;//decay time(ms);
  Double_t x,y;
  ULong64_t ts;
  
  vector<Double_t> ge;
  vector<ULong64_t> gts;
  vector<Int_t> gid;
} decay;


class tree {
 public:
  vector<dssd> *br_x,*br_y,*br_box,*br_mw,*br_de,*br_xa,*br_gs;
  Double_t xesum,yesum,desum,mesum;
 
  tree(){ipt = NULL; opt = NULL;}
  tree(TTree *ipt_){
    ipt = ipt_;
    Init();
  }
  void Init();
  void Loop1(TTree *opt_,Int_t run_);
  void Loop2(TTree *opt_,Int_t run_);
  Int_t GetPid(Double_t e);
  void BranchOpt();
  void GetEvent();

  TTree *ipt;
  TTree *opt;
  char  isotope[13][256]={"184Hg","185Hg","182Hg","183Hg",//1-4
			"188Pb_187mPb","187mPb","unknown1","186Pb",//5-8
			"unknown2","189gBi","188Bi10","188Bi3",//9-12
			"unknown3"};//13
  Double_t peak[13]={5541,5652,5866,5905,
		     5988,6080,6263,6329,
		     6390,6672,6815,6991,
		     7280};
  Double_t halflife[13]={30900,49100,10830,9400,
			 24200,18300,100000,4820,
			 100000,674,265,60,
			 100000};

  map<ULong64_t,Recoil> mr;//recoil
  map<ULong64_t,Decay> md;//decay

  ///tree branches
  Int_t run;

  //recoil-dgs
  Int_t irecoil;
  Double_t re;
  Double_t rx,ry;
  Long64_t rts;
  vector<Double_t> vge;
  vector<Long64_t> vgts;
  vector<Int_t> vgid;
 
  //decay-dssd
  Int_t idecay;
  Int_t pid;
  char spid[256];
  Double_t tdecay;
  Double_t e,boxe;
  Double_t x,y;
  Long64_t ts;
  Double_t dt;//decay time(ms);
  

  //decay-Clover(XA)
  vector<Double_t> vce;
  vector<Long64_t> vcts;
  vector<Int_t> vcid;

};
