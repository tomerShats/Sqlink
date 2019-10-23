# include <iostream>
# include <string>
#include <stdio.h>
# include <typeinfo>
#include "virtIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

using namespace std;
template <class T>
void func(T * t){
    int choose=0;
    while(choose!=-1){
        cout<<"enter 1 : to open file "<<endl;
        cout<<"enter 2 : to close file "<<endl;
        cout<<"enter 3 : write to file  "<<endl;
        cout<<"enter 4 : read from file "<<endl;
        cout<<"enter 5 : get the file name "<<endl;
        cout<<"enter 6 : get the mode "<<endl;
        cout<<"enter 7 : get the size "<<endl;
        cout<<"enter 8 : get the location "<<endl;
        cout<<"enter 9 : set the location "<<endl;
        cout<<"enter other number : for exit "<<endl;
        cin>>choose;
        switch(choose){
            case 1:{
                 string name,mode;
                 cout<<"enter name file "<<endl;
                 cin>>name;
                 cout<<"enter the mode "<<endl;  
                 cin>>mode;
                   try{
                     t=new T(name,mode);
    
                   }catch(int){
                    cout<<"error"<<endl;
                   }

               break;
                 
            }
            case 2:{
                 t->closeF();
                break;
            }
            case 3:{
                int c;
                int num1;
                float num2;
                 asciiIO_t * v;
                

                cout<<"enter 1 for int num or 2 for float num to write "<<endl;
                cin>>c;
                if(typeid(v)==typeid(t)){
                         if(c==1){
                     cout<<"enter int number  "<<endl;
                    cin>>num1;
                    try{
                        (*t)<<num1<<' ';
                   }catch(int){
                     cout<<"error"<<endl;
                   }
                }else{
                    cout<<"enter float number  "<<endl;
                    cin>>num2;
                    try{
                       (*t)<<num2<<' ';
                    }catch(int){
                      cout<<"error"<<endl;
                    }
                }

                }else{
                        if(c==1){
                     cout<<"enter int number  "<<endl;
                    cin>>num1;
                    try{
                        (*t)<<num1;
                   }catch(int){
                     cout<<"error"<<endl;
                   }
                }else{
                    cout<<"enter float number  "<<endl;
                    cin>>num2;
                    try{
                       (*t)<<num2;
                    }catch(int){
                      cout<<"error"<<endl;
                    }
                }

                }
                                
             break;    
            }
            case 4:{
                int c;
                int num1;
                float num2;

                cout<<"enter 1 for int num or 2 for float num to write "<<endl;
                cin>>c;
                if(c==1){
                     try{
                        (*t)>>num1;
                     }catch(int){
                       cout<<"error"<<endl;
                       break;
                     }
                     cout<<"the number is "<<num1<<endl;
                 }else{
                    try{
                        (*t)>>num2;
                     }catch(int){
                       cout<<"error"<<endl;
                       break;
                     }
                     cout<<"the number is "<<num2<<endl;
                }

               
                break;
            }
            case 5:{
                 cout<<t->getPath()<<endl;
                break;
            }
            case 6:{
                 cout<<t->getMode()<<endl;
                break;
            }
            case 7:{
                 cout<<t->getLength()<<endl;
                break;
            }
            case 8:{
                 cout<<t->getPos()<<endl;
                break;
            }
            case 9:{
                int p;
                cout<<"enter the location "<<endl;
                cin>>p;
                t->setPos(p);
                 
                break;
            }
            default:{
               choose=-1;
               break;
            }
        }
    }

}

int main(){
    int choose=0;
    asciiIO_t * t;
    binIO_t * b;
    cout<<"enter 1 for asci or 2 for binary file "<<endl;
    cin>>choose;
    if(choose==1){
        func<asciiIO_t>(t);
    }else{
        func<binIO_t>(b);
    }
    
     
   
   
    return 0;
}