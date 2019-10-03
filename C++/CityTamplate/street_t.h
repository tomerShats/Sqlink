#pragma once
# include <iostream>
# include <string>
#include <vector>
#include "building_t.h"
using namespace std;
template <class TIDS,class TIDB>
class street_t{
    
    public:
        ~street_t(){};
        street_t();
        street_t(const street_t & b);
        street_t<TIDS,TIDB>& operator= (const  street_t& b);
        TIDS getId()const; 
        void  setId(const TIDS id);
        building_t<TIDB> getBuild(const TIDB id)const;
        void addBuild(const building_t<TIDB>& b);

    
    private:
        vector<building_t<TIDB> > v;
        TIDS m_id;

};

template <class TIDS,class TIDB>
street_t<TIDS,TIDB>::street_t(){

}

template <class TIDS,class TIDB>
street_t<TIDS,TIDB>::street_t(const street_t<TIDS,TIDB>& b){
        this->m_id=b.m_id;
        this->v=b.v;
  
}
template <class TIDS,class TIDB>
street_t<TIDS,TIDB>& street_t<TIDS,TIDB>::operator= (const  street_t<TIDS,TIDB>& b){
    if(this!=&b)
    {
        this->m_id=b.m_id;
        this->v=b.v;
    }
    return *this;
}

template <class TIDS,class TIDB>
TIDS street_t<TIDS,TIDB>::getId()const{
    return this->m_id;

}

template <class TIDS,class TIDB>
void  street_t<TIDS,TIDB>::setId(const TIDS id)
{
    this->m_id=id;
}
template <class TIDS,class TIDB>
building_t<TIDB> street_t<TIDS,TIDB>::getBuild(const TIDB id)const{
    int i;
    for(i=0;i<v.size();i++)
    {
        if(v[i].getId()==id)
        {
            return v[i];
        }
    }
    throw i;
}
template <class TIDS,class TIDB>
 void street_t<TIDS,TIDB>::addBuild(const building_t<TIDB>& b){
    v.insert(v.end(),b);
 }



