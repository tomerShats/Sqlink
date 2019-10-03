# include <iostream>
# include <string>
#include "city_t.h"
#include "street_t.h"
#include "building_t.h"
using namespace std;


int main()
{
building_t<int> b;
int flag=0;
building_t<int> temp;
street_t<string,int> s;
street_t<string,int> s2;
city_t<string,string,int> c;
building_t<int> b2;

b.setId(2);
s.setId("london");
s.addBuild(b);
b2.setId(6);
s.addBuild(b2);
try{
    temp=s.getBuild(2);
}catch(int){
    cout<<"your id is not good "<<endl;
    flag=1;
}

if(flag==0)
{
    cout<<temp.getId()<<endl;
}
try{
    temp=s.getBuild(6);
}catch(int){
    cout<<"your id is not good "<<endl;
    flag=1;
}

if(flag==0)
{
    cout<<temp.getId()<<endl;
}
int tr=8;
try{
    temp=s.getBuild(tr);
}catch(int){
    cout<<"your id is not good "<<endl;
    flag=1;
}

if(flag==0)
{
    cout<<temp.getId()<<endl;
}

flag=0;
c.setId("england");
c.addStreet(s);
try{
    s2=c.getStreet("london");
}catch(int){
    cout<<"your id is not good "<<endl;
    flag=1;
}
if(flag==0)
{
    cout<<s2.getId()<<endl;
}



 return 0;
}
    