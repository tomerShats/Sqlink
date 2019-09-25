# include <iostream>
# include <string.h>
#include "String_t.h"
using namespace std;
size_t String_t::defCapacity=8;
int String_t::numOfStrings=0;
int String_t::caseSens=0;
String_t::String_t(const char * nm)

{   if(nm==NULL)
    {
       this->str=new char [defCapacity];
       str[0]='\0';  
       this->myCapcity=defCapacity;
       this->numOfStrings++;
    }
    else
    {    this->myCapcity=nextPowerOf2(strlen(nm)+1);
        this->str=new char [this->myCapcity];
        strcpy(this->str,nm);
         this->numOfStrings++;
    }
    
}


String_t::String_t()
{   
    this->str=new char [defCapacity];
    str[0]='\0';
    this->myCapcity=defCapacity;
    this->numOfStrings++;
}

String_t::~String_t()
{   
    delete[](this->str);
   
}

String_t::String_t(const String_t & st)
{  
    this->myCapcity=nextPowerOf2(strlen(st.str)+1);
    this->str=new char [this->myCapcity];
     this->str=st.str;
      
      this->numOfStrings++;
}

String_t& String_t:: operator= (const  String_t& st)
{
    if(this!=&st)
    {
        delete[] str;
        if(this->myCapcity<st.length()){
            this->myCapcity=nextPowerOf2(strlen(st.str)+1);
        }
        this->str=new char [this->myCapcity];
        strcpy(this->str,st.str);


    }
    return *this;
}

 int  String_t::length() const 
 {
     return strlen(this->str);
 }

 void String_t::setString(const char * nm)
 {     
     delete[] str; 
     if(nm==NULL)
    { 

       this->str=new char [defCapacity];
       str[0]='\0';  
    }
    else
    {    if(this->myCapcity<strlen(nm)){
            this->myCapcity=nextPowerOf2(strlen(nm)+1);
        }
        this->str=new char [this->myCapcity];
        strcpy(this->str,nm);
    }
 }
  const char* String_t::getString() const
  {
      return this->str;
  }
   int String_t::compare (const  String_t& st) 
   {
       int res;
      res=comp(st.str);
       
       if(res>0)
            res=1;
       else if (res<0)
            res=2;
       return res;
   }
    void String_t::print() const
    {
        cout<<"the str:"<<this->str<<endl;
    }
    void String_t::upCase()
    {   int i=0;
        for(i=0;i<strlen(this->str);i++)
        {
         this->str[i]=toupper(this->str[i]);  
        }
       
    }
    void String_t::lowCase()
    {
        int i=0;
        for(i=0;i<strlen(this->str);i++)
        {
         this->str[i]= tolower(this->str[i]);  
        }
       
    }
    void String_t::prepend(const char* nm)
    {   char temp[254];
        strcpy(temp,this->str);
        this->setString(nm);
        strcat(this->str,temp);
    }
    void String_t::prepend(const  String_t& st)
    {   char temp[254];
         strcpy(temp,this->str);
        this->setString(st.str);
        strcat(this->str,temp);
         
    }
    String_t& String_t:: operator+= (const  String_t& st)
{       char temp[254];
        strcpy(temp,this->str);
        strcat(temp,st.str);
        delete[] str;
        if(this->myCapcity<strlen(temp)){
            this->myCapcity=nextPowerOf2(strlen(temp)+1);
        }
        this->str=new char [this->myCapcity];
        strcpy(this->str,temp);

    return *this;
}
  String_t& String_t:: operator+= (const  char* nm)
{        char temp[254];
        strcpy(temp,this->str);
        strcat(temp,nm);
        delete[] str;
         if(this->myCapcity<strlen(temp)){
            this->myCapcity=nextPowerOf2(strlen(temp)+1);
        }
        this->str=new char [this->myCapcity];
        strcpy(this->str,temp);

    return *this;
}

int String_t::operator< (const  String_t& st)
{   
    int res;

    res=comp(st.str);   
    if(res<0){
        return 1;
    }else{
        return 0;
    }
}

int String_t::operator> (const  String_t& st)
{
    int res;
     res=comp(st.str);
    if(res>0){
        return 1;
    }else{
        return 0;
    }
}
int String_t::operator>=(const  String_t& st)
{
    int res=comp(st.str);
    if(res>=0){
        return 1;
    }else{
        return 0;
    }
}

int String_t::operator<= (const  String_t& st)
{
    int res=comp(st.str);
    if(res<=0){
        return 1;
    }else{
        return 0;
    }
}

int String_t::operator== (const  String_t& st)
{
    int res=comp(st.str);
    if(res==0){
        return 1;
    }else{
        return 0;
    }
}
int String_t::operator!= (const  String_t& st)
{
    int res=comp(st.str);
    if(res!=0){
        return 1;
    }else{
        return 0;
    }
}
int String_t::contains ( const char* nm)  
{
    int i=0;
   char *temp=new char[nextPowerOf2(strlen(nm)+1)];
   strcpy(temp,nm);


    if(caseSens==1){
       return strstr(this->str,nm)!=NULL?1:0;
    }else{
        upCase();
        for(i=0;i<strlen(nm);i++)
        {
         temp[i]= toupper(temp[i]);  
        }
        temp[i]='\0';
        return strstr(this->str,temp)!=NULL?1:0;
        

    }
    
}

ostream& operator<<( ostream& os ,const String_t& st)
{
    os <<st.getString()<<endl;
    return os;
}

istream& operator>>( istream& is , String_t& st)
{   char str1[128];
    is >>str1;
    st.setString(str1);
    return is;
}

 char & String_t::operator[] (unsigned int i) {
     
     return this->str[i]; 
 }
 char String_t::operator[] (unsigned int i) const {
     
     return this->str[i]; 
 }

 int String_t:: setSensFlag (const int sens)
 {
    int flag=caseSens;
    caseSens=sens;
    return flag;
 }

 size_t String_t:: setDefCapcFlag(size_t capacity)
 {   
     size_t prev=defCapacity;
     defCapacity=nextPowerOf2(capacity);
     return prev;
 }

 size_t String_t::nextPowerOf2(size_t n)  
{  
    size_t count = 0;  
      
    // First n in the below condition  
    // is for the case where n is 0  
    if (n && !(n & (n - 1)))  
        return n;  
      
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }  
      
    return 1 << count;  
}

int String_t::firstOcc(char c)const{
    int i=0;
    if(caseSens==1){
        for(i=0;i<strlen(this->str);i++){
            if(this->str[i]==c){
                return i;
            }
        }
    }else{
         for(i=0;i<strlen(this->str);i++){
            if((this->str[i]==toupper(c))||(this->str[i]==tolower(c))){
                return i;
            }
        }
    }

}

int String_t::lastOcc(char c)const{
    int i=0;
    if(caseSens==1){
        for(i=strlen(this->str);i>0;i--){
            if(this->str[i]==c){
                return i;
            }
        }
    }else{
         for(i=strlen(this->str);i>0;i--){
            if((this->str[i]==toupper(c))||(this->str[i]==tolower(c))){
                return i;
            }
        }
    }
}

char * String_t::operator() (const unsigned int start,const unsigned int count)const{
    int i,j=0;
   char * temp;
   if(count==0||start+count>strlen(this->str)){
       return NULL;
   }
   temp=new char[count+1];
   for(i=start;i<start+count;i++){
       temp[j]=this->str[i];
       j++;
   }
   temp[j]='\0';

 return temp;
    
}
