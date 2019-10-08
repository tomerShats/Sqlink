#pragma once
# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <list>
# include <iterator>
# include <algorithm>
# include <typeinfo>
# include "Equal_t.h"
using namespace std;
template <class T,class C >
class tContainer_t{
    public:
    virtual ~tContainer_t(){};
    tContainer_t(){};
    bool isEmpty()const{return cont.empty();};
    size_t numOfElem()const{return cont.size();};
    void insertEnd(T * x){ cont.push_back(x);}
    T * firstElem()const{return cont.front();} 
    T * lastElem()const{return cont.back();}
    T * findElem(const T & x ){
          it=find_if(cont.begin(),cont.end(),Equal_t<T>(x));
          if(it==cont.end())
          {
              return 0;
          }
          else{
              return *it;
          }

    }
    T * removeElem(const T & x)
    {
          it=find_if(cont.begin(),cont.end(),Equal_t<T>(x));
          T * n=*it;
          if(it==cont.end())
          {
              return 0;
          }
          else{
              cont.erase(it);
              return n;
          }

    }
    bool deleteElem(const T & x)
    {
          it=find_if(cont.begin(),cont.end(),Equal_t<T>(x));
          T * n=*it;
          if(it==cont.end())
          {
              return false;
          }
          else{
              cont.erase(it);
              delete n;
              return true;
              
          }

    }
    
    void removeAll() 
    {
        it=cont.begin();    
        while(it!=cont.end())
        {
            it=cont.erase(it);
        }
    }

    void deleteAll() 
    {
        it=cont.begin(); 
        int * n;   
        while(it!=cont.end())
        {   n=*it;
            it=cont.erase(it);
            delete n;
        }
    }

    T * operator[] (unsigned int i){
            vector<T *> v;
           if(typeid(v)==typeid(cont)) {
                  return cont[i];
           }else{
               throw i;
           }

           
          
    }


    


    private:
      typedef typename C::iterator iter;
      typedef typename C::const_iterator citer;
      C cont;
      iter it;
      citer cit;
      tContainer_t(const tContainer_t & con){};
      tContainer_t& operator= (const  tContainer_t& con){};


};