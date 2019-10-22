#pragma once
# include <iostream>
# include <string>
#include <stdio.h>


using namespace std;

class asciiIO_t: public virtIO_t{
    public:
      virtual ~asciiIO_t(){};
      asciiIO_t(){};
      asciiIO_t(const string & name,const string & mode): virtIO_t(name,mode){
          int i=5;
          if(getMode()!="r" ||getMode()!="r+" ||getMode()!="w" ||getMode()!="w+"){
              setStatus(bad_access_e);
              throw i;
          }

      };


    private:
       asciiIO_t(const asciiIO_t & asc);
       asciiIO_t& operator= (const  asciiIO_t& asc);
       template <class T> void funcOut(const T & obj,string s){
           int i=5;
           if(this->getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="r" ){
               this->setStatus(writeErr_e);
               throw i;
           }
           fprintf(this->m_fp,s,obj);

       } 
        template <class T> void funcIn(T & obj,string s){
           int i=5;
           if(this->getStatus()==cant_open_file_e){
               throw i;
           }else if( this->getMode()=="w" ){
               this->setStatus(readErr_e);
               throw i;
           }
           fscanf(this->m_fp,s,&obj);

       } 

};