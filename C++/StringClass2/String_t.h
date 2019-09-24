#pragma once
# include <iostream>
# include <string.h>
using namespace std;
class String_t{
    public:
         ~String_t();
        String_t();
        String_t(const char * nm);
        String_t(const String_t & st);
        String_t& operator= (const  String_t& st);
        
        int length()const;
        void setString(const char * nm);
        const char* getString() const;
        int compare (const  String_t& st);
        void print() const;
        void upCase();
        void lowCase();
        void prepend(const char* nm);
        void prepend(const  String_t& st);
        String_t& operator+= (const  String_t& st);
        String_t& operator+= (const  char* nm);
        char * operator() (const  unsigned int start,const unsigned int count)const;
        int operator< (const  String_t& st);
        int operator<= (const  String_t& st);
        int operator> (const  String_t& st);
        int operator>= (const  String_t& st);
        int operator== (const  String_t& st);
        int operator!= (const  String_t& st);
        int contains (const char* nm);
        char& operator[] (unsigned int i);
        char operator[] (unsigned int i) const;
        static int getSensFlag() {return caseSens;};
        static int setSensFlag(const int sens);
        static size_t getCap() {return defCapacity;};
        static size_t setDefCapcFlag(size_t capacity);
        int firstOcc(char c)const;
        int lastOcc(char c)const;
        static int getNumItems(){return numOfStrings;};
        
        

        
    
    private:
        char* str;
        size_t  myCapcity;
        static size_t defCapacity;
        static int numOfStrings;
        static int caseSens;
        static size_t nextPowerOf2(size_t n);
        int comp(char * st){
            int res;
            if(caseSens==1){
                 res=strcmp(this->str,st);
           }else{
                 res=strcasecmp(this->str,st);
           }
           return res;
        };
        

};
ostream& operator<<( ostream& os ,const String_t& st);
istream& operator>>( istream& is , String_t& st);
        