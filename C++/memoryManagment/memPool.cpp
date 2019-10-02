#include <iostream>
#include <string.h>
#include "memPage.h"
#include "memPool.h"

size_t memPool_t::readM(void *k,size_t nOfByte){
      size_t s=0;
      char * temp=(char *)k;
      int i=this->getCurrent();
      while(s!=nOfByte){
          if(i>this->v.size()-1){
              break;
          }

        s+=v[i]->readM(temp+s,nOfByte-s,0);
        i++;
      }

      return s;
  
}

size_t memPool_t::readM(void *k,size_t nOfByte,size_t pos)
  {
    
if(pos>this->v.size()-1){
  return 0;
}
  size_t s=0;
      char * temp=(char *)k;
      int i=pos;
      while(s!=nOfByte){
          if(i>this->v.size()-1){
              break;
          }

        s+=v[i]->readM(temp+s,nOfByte-s,0);
        i++;
      }

      return s;
   
}

size_t memPool_t::writeM(const void * k,size_t nOfByte)
{
   
  size_t s=0;
      char * temp=(char *)k;
      int i=this->getCurrent();
      while(s!=nOfByte){
          if(i>this->v.size()-1){
              memPage_t * page=new memPage_t;
              v.insert(v.end(), page);	
          }
        if(v[i]->getCurrent()==0){
            s+=v[i]->writeM(temp+s,nOfByte-s,0);
        }else{
            s+=v[i]->writeM(temp+s,nOfByte-s,v[i]->getCurrent()+1);
        }
         
        i++;
      }
     if(v.size()!=1){
         this->setActualSize((v.size()-1)*v[0]->getCapacity()+v[v.size()-1]->getActualSize());
     }else{
          this->setActualSize(v[0]->getActualSize());
     }
      this->setCurrent(--i);
      return s;
   

}

size_t memPool_t::writeM(const void * k,size_t nOfByte,size_t pos){
 if(pos>this->v.size()-1){
   return 0;
 } 

    size_t s=0;
   char * temp=(char *)k;
      int i=pos;
      while(s!=nOfByte){
          if(i>this->v.size()-1){
              memPage_t * page=new memPage_t;
              v.insert(v.end(), page);	
          }
        if(v[i]->getCurrent()==0){
            s+=v[i]->writeM(temp+s,nOfByte-s,0);
        }else{
          s+=v[i]->writeM(temp+s,nOfByte-s,v[i]->getCurrent()+1);
        
        }
        i++;
      }
       if(v.size()!=1){
         this->setActualSize((v.size()-1)*v[0]->getCapacity()+v[v.size()-1]->getActualSize());
     }else{
          this->setActualSize(v[0]->getActualSize());
     }

     this->setCurrent(--i);


      return s;


}


    
   

  

 