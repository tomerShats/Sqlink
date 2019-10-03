#pragma once
# include <iostream>
# include <string>
# include <string.h>

using namespace std;
template <class T>
class TException_t{
    
    public:
        ~TException_t(){};
        TException_t(T obj,string fileN,int line,string txt){
            m_ob=obj;
            m_FileN=fileN;
            m_line=line;
            m_txt=txt;

        };
        const T & getOb()const{return m_ob;}; 
        const string & getFile()const{return m_FileN;};
        const string & getText()const{return m_txt;};
        const int & getLine()const{return m_line;};
    private:
         T m_ob;
         string m_FileN;
         int m_line;
         string m_txt;

};

