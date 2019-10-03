#pragma once
# include <iostream>
# include <string>
#include <vector>
#include "street_t.h"
using namespace std;
template <class TIDC,class TIDS,class TIDB>
class city_t{
    
    public:
        ~city_t(){};
        city_t();
        city_t(const city_t & b);
        city_t<TIDC,TIDS,TIDB>& operator= (const  city_t& b);
        TIDC getId()const; 
        void  setId(const TIDC id);
        street_t<TIDS,TIDB> getStreet(const TIDS id)const;
        void addStreet(const street_t<TIDS,TIDB> & b);

    
    private:
        vector<street_t<TIDS,TIDB> > v;
        TIDC m_id;

};

template <class TIDC,class TIDS,class TIDB>
city_t<TIDC,TIDS,TIDB>::city_t(){

}

template <class TIDC,class TIDS,class TIDB>
city_t<TIDC,TIDS,TIDB>::city_t(const city_t<TIDC,TIDS,TIDB> & b){
        this->m_id=b.m_id;
        this->v=b.v;
  
}
template <class TIDC,class TIDS,class TIDB>
city_t<TIDC,TIDS,TIDB>& city_t<TIDC,TIDS,TIDB>::operator= (const  city_t<TIDC,TIDS,TIDB>& b){
    if(this!=&b)
    {
        this->m_id=b.m_id;
        this->v=b.v;
    }
    return *this;
}

template <class TIDC,class TIDS,class TIDB>
TIDC city_t<TIDC,TIDS,TIDB>::getId()const{
    return this->m_id;

}

template <class TIDC,class TIDS,class TIDB>
void  city_t<TIDC,TIDS,TIDB>::setId(const TIDC id)
{
    this->m_id=id;
}
template <class TIDC,class TIDS,class TIDB>
street_t<TIDS,TIDB> city_t<TIDC,TIDS,TIDB>::getStreet(const TIDS id)const{
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
template <class TIDC,class TIDS,class TIDB>
 void city_t<TIDC,TIDS,TIDB>::addStreet(const street_t<TIDS,TIDB>& s){
    v.insert(v.end(),s);
 }



