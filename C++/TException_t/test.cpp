
# include <iostream>
# include <string>
# include <string.h>
#include "TException.h"
void foo();
int main()
{
  try{
    foo();

  }catch(TException_t<int> & ex)
   {
       cout<<"the object is: "<<ex.getOb()<<endl;
       cout<<"from file: "<<ex.getFile()<<endl;
       cout<<"from line: "<<ex.getLine()<<endl;
       cout<<"the text: "<<ex.getText()<<endl;
   
   
   }
  

}

void foo(){
    int i=5;
    string t(__FILE__);
    TException_t<int> s(i,t,__LINE__,"you throw int");
    throw s;
}