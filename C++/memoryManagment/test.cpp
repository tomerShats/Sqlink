#include <iostream>
#include <string.h>
#include "memPage.h"
#include "memoryMan.h"
#include "memPool.h"


void memTest(memManager_t * mm){

 
  int k=6;
  int z=4;
  int w=8;
  long test;
   cout<<"the size actual :"<<mm->getActualSize()<<endl;
  mm->writeM(&k,sizeof(int));
  mm->readM(&w,sizeof(int),0);
  cout<<"the number:"<<w<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
  mm->writeM(&z,sizeof(int));
  mm->readM(&test,8,0);
  cout<<"the number"<<test<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
   mm->readM(&z,4,0);
  cout<<"the number:"<<z<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
  mm->writeM(&k,sizeof(int));
  mm->readM(&w,sizeof(int),1);
  cout<<"the number:"<<w<<endl;
  cout<<"the index:"<<mm->getCurrent()<<endl;
  cout<<"the actual capacity:"<<mm->getActualSize()<<endl;
  /*try{
    mm->setCurrent(15);
  }catch(int i){
    cout<<"your size not good"<<endl;
  }*/
  

}   

int main(){
  memManager_t * mm;
  int ans;
  cout<<"enter 1 for page or 2 for pool "<<endl;
  cin>>ans;
  if(ans==2){
    mm=new memPool_t;
  }else if(ans==1){
    mm=new memPage_t;
  }else{
    cout<<"error"<<endl;
  }
  try{
     memTest(mm);

  }catch(std::bad_alloc)
    {
      cout<<"bad allocation"<<endl;
    }
  
}