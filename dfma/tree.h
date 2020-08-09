#include <TTree.h>
#include <TFile.h>
#include <vector>
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

typedef struct DFMAEVENT
{
  unsigned short int      flag;//探测器标记 1 Si Front   2 Si Back   3 Si box   4 FP   5 MWPC  6 DE
  double                  e;//刻度能量
  int                     ch;//原始能量
  short int               id;// Si 0-159  box 0-55   FP 0/1   MWPC 0/1/2/3
  unsigned short int      tpe;
  unsigned short int      tid;

  unsigned long long int  ts;//时间戳
  unsigned long long int  prets;
  int wheel;

  // 如果要分析波形，则需要使用 基线采样/波形长度/波形 三个变量
  
}DFMAEVENT;


class tree {
 public:
  vector<DFMAEVENT>* br_dfma;
 
  tree(){ipt = NULL; opt = NULL;}
  tree(TTree *ipt_){
    ipt = ipt_;
    Init();
  }
  void Init();
  void Loop(TTree *opt_);
  void BranchOpt();

  TTree *ipt;
  TTree *opt;

  dssd x,y,box,pa,mw;
  double xesum,yesum,desum,mesum;
  vector<dssd> xvec,yvec,bvec,pvec,mvec;

  int strip[160];
};
