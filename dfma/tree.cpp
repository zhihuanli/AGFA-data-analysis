#include "tree.h"
using namespace std;

bool SortDS(dssd &ds1,dssd &ds2)
{
  return ds1.e > ds2.e;
}

void tree::Init()
{
  if(ipt==NULL) return;
  ipt->SetBranchAddress("dfma",&br_dfma);
  ifstream readtxt;
  
  int tmp1,tmp2;
  readtxt.open("dssd.map");//re-maping for y-side
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

void tree::Loop(TTree *opt_)
{
  if(opt_==NULL) return;
  opt = opt_;    
  BranchOpt();
  Long64_t nentries = ipt->GetEntriesFast();
   
  vector<ULong64_t> vxts,vyts,vbts;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      ipt->GetEntry(jentry);  
      xvec.clear();
      yvec.clear();
      bvec.clear();
      mvec.clear();
      pvec.clear();

      vxts.clear();
      vyts.clear();
      vbts.clear();

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
	    //remove identical evets
	    auto ivxts=find(vxts.begin(),vxts.end(),ts);  
            bool bts=!(ivxts!=vxts.end());
	    if( bts) {//x-side time cut
	      xvec.push_back(x);
	      vxts.push_back(ts);
	    }
	  }
	if(flag==2 && e>250) {//dssd-y
	    y.e=e;
	    y.id=strip[id];
	    y.ts=ts;;
	    //remove identical evnts
	    auto ivyts=find(vyts.begin(),vyts.end(),ts);  
            bool bts=!(ivyts!=vyts.end());
	    if(bts){//y-side time cut
	      yvec.push_back(y);
	      vyts.push_back(ts);
	    }
	  }
	if(flag==3 && e>10){//si-box
	  box.e=e;
	  box.id=id;
	  box.ts=ts;
	  //remove identical evets
	  auto ivbts=find(vbts.begin(),vbts.end(),ts);  
	  bool bts=!(ivbts!=vbts.end());
	  if(bts && box.ts){//y-side time cut
	    bvec.push_back(box);
	    vbts.push_back(ts);
	  }
	}
	if(flag==4) {//fp 
	  pa.e=ch;
	  pa.id=id;
	  pa.ts=ts;
	  pvec.push_back(pa);
	}

	if(flag==5) {//mwpc
	  mw.e=ch;
	  mw.id=id;
	  mw.ts=ts;
	  mvec.push_back(mw);
	}
      }


   //sort vectors in descending order of energy	 
   sort(xvec.begin(),xvec.end(),SortDS);
   sort(yvec.begin(),yvec.end(),SortDS);
   sort(bvec.begin(),bvec.end(),SortDS);

   //remove noisy strips in dssd
   for(auto it=xvec.begin();it!=xvec.end() ; ) {
     if(TMath::Abs(it->id-xvec[0].id)>1) 
       it=xvec.erase(it);
     else 
       ++it;
   }

   
   for(auto it=yvec.begin();it!=yvec.end() ; ) {
     if(TMath::Abs(it->id-yvec[0].id)>1) 
       it=yvec.erase(it);
     else 
       ++it;
   }
   
   if(xvec.size()==0) continue; //no dssd evnts;

   //time walk correction x.ts-320/sqrt(x.e)
   //remove the events outside of timewindow
   
   for(auto it=xvec.begin();it!=xvec.end() ; ) {
     if(TMath::Abs(int(it->ts-xvec[0].ts))>20) 
       it=xvec.erase(it);
     else
       ++it;
   }
   
   for(auto it=yvec.begin();it!=yvec.end() ; ) {
     if(TMath::Abs(int(it->ts-xvec[0].ts))>20) 
       it=yvec.erase(it++);
     else
       ++it;
     }
   
   for(auto it=bvec.begin();it!=bvec.end() ; ) {
     if(TMath::Abs(int(it->ts-xvec[0].ts))>30) 
       it=bvec.erase(it);
     else
       ++it;
   }

   for(auto it=mvec.begin();it!=mvec.end() ; ) {
     if(TMath::Abs(int(it->ts-xvec[0].ts-25))>20) 
       it=mvec.erase(it);
     else
       ++it;
   }
     
   xesum=0;
   for(int i=0;i<xvec.size();i++)xesum+=xvec[i].e;
   yesum=0;
   for(int i=0;i<yvec.size();i++)yesum+=yvec[i].e;
   desum=min(xesum,yesum);//dssd energy

   mesum=0;
   for(int i=0;i<mvec.size();i++)mesum+=mvec[i].e;

   bool bDSSD=0;
   if(xvec.size()>0 && yvec.size()>0) bDSSD=1; 

   if(bDSSD) opt->Fill();
   if(jentry%100000==0) std::cout<<jentry/10000<<"0k"<<endl;
  }
}

void tree::BranchOpt()
{
  br_dfma = 0;
  opt->Branch("xesum",&xesum,"xesum/D");
  opt->Branch("yesum",&yesum,"yesum/D");
  opt->Branch("desum",&desum,"desum/D");
  opt->Branch("mesum",&mesum,"mesum/D");
  opt->Branch("x",&xvec);
  opt->Branch("y",&yvec);
  opt->Branch("box",&bvec);
  opt->Branch("pa",&pvec);
  opt->Branch("mw",&mvec);


}
