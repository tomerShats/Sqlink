#pragma once
# include <iostream>
# include <string>
using namespace std;
class meeting_t{
    public: 
     virtual ~meeting_t(){};
     meeting_t(const float & begin,const float & end, const string & subject){
         int i=1;
         if(begin>=0 && begin<end && end <= 24){
            m_begin=begin;
            m_end=end;
            m_subject=subject;
         }else{
             throw i;
         }   
     }
     const float & getBegin()const{return m_begin;}
     const float & getEnd()const{return m_end;}
     const string & getSub()const{return m_subject;}
     

    private:
       string m_subject;
       float m_begin;
       float m_end;
       meeting_t(const meeting_t & meet){};
       meeting_t& operator= (const  meeting_t& meet){};
};