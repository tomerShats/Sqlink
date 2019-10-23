#pragma once
# include <iostream>
# include <string>
# include <string.h>
#include <stdio.h>
#include "virtIO_t.h"


using namespace std;

class binIO_t: public virtIO_t{
    public:
      virtual ~binIO_t(){};
      binIO_t(){};
      binIO_t(const string & name,const string & mode): virtIO_t(name,mode){
          int i=5;
          if(getMode()!="rb" && getMode()!="rb+" && getMode()!="wb" && getMode()!="wb+"){
              setStatus(bad_access_e);
              throw i;
          }

      }
      virtual binIO_t & operator <<(int temp){return funcOut<int>(temp);};
      virtual binIO_t& operator>>(int & temp){return funcIn<int>(temp);};
      virtual binIO_t & operator <<(float temp){return funcOut<float>(temp);};
      virtual binIO_t& operator>>(float & temp){return funcIn<float>(temp);};
      virtual binIO_t & operator <<(short temp){return funcOut<short>(temp);};
      virtual binIO_t& operator>>(short & temp){return funcIn<short>(temp);};
      virtual binIO_t & operator <<(long temp){return funcOut<long>(temp);};
      virtual binIO_t& operator>>(long & temp){return funcIn<long>(temp);};
      virtual binIO_t & operator <<(char temp){return funcOut<char>(temp);};
      virtual binIO_t& operator>>(char & temp){return funcIn<char>(temp);};
      virtual binIO_t & operator <<(double temp){return funcOut<double>(temp);};
      virtual binIO_t& operator>>(double & temp){return funcIn<double>(temp);};

      virtual binIO_t & operator <<(unsigned int temp){return funcOut<unsigned int>(temp);};
      virtual binIO_t& operator>>(unsigned int & temp){return funcIn<unsigned int>(temp);};
      virtual binIO_t & operator <<(unsigned short temp){return funcOut<unsigned short>(temp);};
      virtual binIO_t& operator>>(unsigned short & temp){return funcIn<unsigned short>(temp);};
      virtual binIO_t & operator <<(unsigned long temp){return funcOut<unsigned long>(temp);};
      virtual binIO_t& operator>>(unsigned long & temp){return funcIn<unsigned long>(temp);};
      virtual binIO_t & operator <<(unsigned char temp){return funcOut<unsigned char>(temp);};
      virtual binIO_t& operator>>(unsigned char & temp){return funcIn<unsigned char>(temp);};

        binIO_t& operator>>(void* buf)
       {int i=5;
            if(getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="wb" ){
               this->setStatus(writeErr_e);
               throw i;
           }
           m_writable = false;
           m_buf = buf;     
            return *this;
       }        
       binIO_t& operator<<(const void* _buf)
       {  int i=5;
            if(getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="rb" ){
               this->setStatus(writeErr_e);
               throw i;
           }
           m_writable = true;
           m_buf = (void*)_buf;            
           return *this;
       }   
       void operator,(int length)
       { int i=5;
           if (m_writable)
           {
               int res = fwrite(m_buf, 1, length, m_fp);
               if (length != res)
               {
                   setStatus(writeErr_e);
                   throw i;
               }
           }
           else
           {
               int res = fread(m_buf, 1, length, m_fp);
               if (length != res)
               {
                   setStatus(readErr_e);
                   throw i;
               }
           }    
       }
      



    private:
       bool  m_writable;
       void * m_buf;
       binIO_t(const binIO_t & asc);
       binIO_t& operator= (const  binIO_t& asc);
       template <class T> binIO_t & funcOut(T & obj){
           int i=5;
           if(getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="rb" ){
               this->setStatus(writeErr_e);
               throw i;
           }
           fwrite(&obj, sizeof(T), 1, this->m_fp);
           return *this;

       } 
        template <class T> binIO_t & funcIn(T & obj){
           int i=5;
           if(getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="wb" ){
               this->setStatus(readErr_e);
               throw i;
           }
           fread(&obj,sizeof(T),1,this->m_fp);
           return *this;

       } 
  
};