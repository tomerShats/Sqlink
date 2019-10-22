#pragma once
# include <iostream>
# include <string>
#include <stdio.h>


using namespace std;

class virtIO_t{
    public: 
     virtual ~virtIO_t(){this->closeF();}
     virtIO_t(){
         m_path='\0';
         m_mode='\0';
         m_s=ok_e;
     }
     virtIO_t(const string & name,const string & mode){
        m_fp=fopen(name,mode);
        int i=5;
        if(m_fp==NULL){
            m_s=cant_open_file_e;
            throw i;
        }
        m_path=name;
        m_mode=mode;
        m_s=ok_e;

     }
     state open(const string & name,const string & mode){
         
         m_fp=fopen(name,mode);
          if(m_fp==NULL){
            m_s=cant_open_file_e;

        }
         m_path=name;
         m_mode=mode;
         return m_s
     }
     void closeF(){
         if(m_s!=cant_open_file_e){
             fclose(m_fp);
         }
     }
     const string & getPath()const{return m_path;}
     const string & getMode()const{return m_mode;}
     long getLength()const{
         long sz;
         fseek(m_fp, 0L, SEEK_END);
         sz = ftell(m_fp); 
         return sz;
        }
        void setPos(size_t pos){
            fseek(m_fp, pos, SEEK_SET);
        }
        long getPos()const{
            return ftell(m_fp);
        }
        state getStatus()const {return m_s;}
        void setStatus(state s){
            m_s=s;
        }
      virtual virtIO_t & operator <<(int temp)=0;
      virtual virtIO_t& operator>>(const int & temp)=0;
      virtual virtIO_t & operator <<(float temp)=0;
      virtual virtIO_t& operator>>(const float & temp)=0;
      virtual virtIO_t & operator <<(short temp)=0;
      virtual virtIO_t& operator>>(const short & temp)=0;
      virtual virtIO_t & operator <<(long temp)=0;
      virtual virtIO_t& operator>>(const long & temp)=0;
      virtual virtIO_t & operator <<(char temp)=0;
      virtual virtIO_t& operator>>(const char & temp)=0;
      virtual virtIO_t & operator <<(double temp)=0;
      virtual virtIO_t& operator>>(const double & temp)=0;

      virtual virtIO_t & operator <<(unsigned int temp)=0;
      virtual virtIO_t& operator>>(const unsigned int & temp)=0;
      virtual virtIO_t & operator <<(unsigned short temp)=0;
      virtual virtIO_t& operator>>(const unsigned short & temp)=0;
      virtual virtIO_t & operator <<(unsigned long temp)=0;
      virtual virtIO_t& operator>>(const unsigned long & temp)=0;
      virtual virtIO_t & operator <<(unsigned char temp)=0;
      virtual virtIO_t& operator>>(const unsigned char & temp)=0;
      
  
     
   protected: 
       FILE *m_fp;
       string m_path;
       string m_mode;
       typedef enum state{ok_e,cant_open_file_e,bad_access_e,writeErr_e,readErr_e} state;

    private:
       state m_s;
       virtIO_t(const virtIO_t & vir);
       virtIO_t& operator= (const  virtIO_t& vir);
       
};