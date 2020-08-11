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

typedef struct DGSEVENT
{
  short int               id;//探测器编号 0-109
  double		  ch;//原始能量道址
  double		  e_nodop;//未修正多普勒刻度能量
  double		  e;//多普勒修正能量
  
  unsigned short int      tpe;//探测器类型
  unsigned short int      tid;//探测器编号 1-110
  unsigned short int      flag;//反康标记     addback标记

  unsigned long long int  ts;//event_timestamp
  
  unsigned long long int  tscorr;//time walk corr
  int                     dtlast;//当前触发与上个触发的时间差
  int                     dtpeak;//peak_timestamp 未完成，可能参考程序中的数据解码存在问题
  int                     dt;//Ge与BGO的时间差       addback两个晶体的时间差
  
  bool	                  timestamp_match_flag;
  bool	                  cfd_valid_flag;
  bool	                  peak_valid_flag;
  bool	                  pileup_flag;
  double                  cfd;

} DGSEVENT;


class tree {
 public:
  vector<DFMAEVENT>* br_dfma;
  vector<DGSEVENT>* br_xa;
  vector<DGSEVENT>* br_dgs;
 
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
  dssd xa,xaa,gs;
  double xesum,yesum,desum,mesum;
  vector<dssd> xvec,yvec,bvec,pvec,mvec;
  vector<dssd> xavec,xaavec,gsvec;

  int strip[160];
};
