#pragma once
# include <iostream>
# include <string>
using namespace std;
template <class TIDB>
class building_t{
    
    public:
        ~building_t(){};
        building_t();
        building_t(const building_t & b);
        building_t<TIDB> & operator= (const  building_t& b);
        TIDB getId()const; 
        void  setId(const TIDB id);

    
    private:
         TIDB m_id;

};

template <class TIDB>
building_t<TIDB>::building_t(){

}

template <class TIDB>
building_t<TIDB>::building_t(const building_t<TIDB> & b){
        this->m_id=b.m_id;
  
}
template <class TIDB>
building_t<TIDB>& building_t<TIDB> ::operator= (const  building_t<TIDB>& b){
    if(this!=&b)
    {
        this->m_id=b.m_id;
    }
    return *this;
}

template <class TIDB>
TIDB building_t<TIDB>::getId()const{
    return this->m_id;

}

template <class TIDB>
void  building_t<TIDB>::setId(const TIDB id)
{
    this->m_id=id;
}



