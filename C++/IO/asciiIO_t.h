#pragma once
# include <iostream>
# include <string>
# include <string.h>
#include <stdio.h>
#include "virtIO_t.h"


using namespace std;

class asciiIO_t: public virtIO_t{
    public:
      virtual ~asciiIO_t(){};
      asciiIO_t(){};
      asciiIO_t(const string & name,const string & mode): virtIO_t(name,mode){
          int i=5;
          if(getMode()!="r" && getMode()!="r+" && getMode()!="w" && getMode()!="w+"){
              setStatus(bad_access_e);
              throw i;
          }

      }
      virtual asciiIO_t & operator <<(int temp){return funcOut<int>(temp,"%d");};
      virtual asciiIO_t& operator>>(int & temp){return funcIn<int>(temp,"%d");};
      virtual asciiIO_t & operator <<(float temp){return funcOut<float>(temp,"%f");};
      virtual asciiIO_t& operator>>(float & temp){return funcIn<float>(temp,"%f");};
      virtual asciiIO_t & operator <<(short temp){return funcOut<short>(temp,"%i");};
      virtual asciiIO_t& operator>>(short & temp){return funcIn<short>(temp,"%i");};
      virtual asciiIO_t & operator <<(long temp){return funcOut<long>(temp,"%ld");};
      virtual asciiIO_t& operator>>(long & temp){return funcIn<long>(temp,"%ld");};
      virtual asciiIO_t & operator <<(char temp){return funcOut<char>(temp,"%c");};
      virtual asciiIO_t& operator>>(char & temp){return funcIn<char>(temp,"%c");};
      virtual asciiIO_t & operator <<(double temp){return funcOut<double>(temp,"%lf");};
      virtual asciiIO_t& operator>>(double & temp){return funcIn<double>(temp,"%lf");};

      virtual asciiIO_t & operator <<(unsigned int temp){return funcOut<unsigned int>(temp,"%u");};
      virtual asciiIO_t& operator>>(unsigned int & temp){return funcIn<unsigned int>(temp,"%u");};
      virtual asciiIO_t & operator <<(unsigned short temp){return funcOut<unsigned short>(temp,"%u");};
      virtual asciiIO_t& operator>>(unsigned short & temp){return funcIn<unsigned short>(temp,"%u");};
      virtual asciiIO_t & operator <<(unsigned long temp){return funcOut<unsigned long>(temp,"%lu");};
      virtual asciiIO_t& operator>>(unsigned long & temp){return funcIn<unsigned long>(temp,"%lu");};
      virtual asciiIO_t & operator <<(unsigned char temp){return funcOut<unsigned char>(temp,"%c");};
      virtual asciiIO_t& operator>>(unsigned char & temp){return funcIn<unsigned char>(temp,"%c");};
      



    private:
       asciiIO_t(const asciiIO_t & asc);
       asciiIO_t& operator= (const  asciiIO_t& asc);
       template <class T> asciiIO_t & funcOut(T & obj,string s){
           int i=5;
           if(getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="r" ){
               this->setStatus(writeErr_e);
               throw i;
           }
           fprintf(this->m_fp,s.c_str(),obj);
           return *this;

       } 
        template <class T> asciiIO_t & funcIn(T & obj,string s){
           int i=5;
           if(getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="w" ){
               this->setStatus(readErr_e);
               throw i;
           }
           fscanf(this->m_fp,s.c_str(),&obj);
           return *this;

       } 

};