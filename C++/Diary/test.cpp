
# include <iostream>
# include <string>
# include <iterator>
# include <map>
# include <algorithm>
# include "meeting.h"
# include "diary.h"
using namespace std;



int main(){

   int choose=0,flag=0;
   diary_t d;
   meeting_t * m;
   float begin,end;
   string subject;
    
    while(choose!=-1){
        cout<<"enter 1 : insert a meeting "<<endl;
        cout<<"enter 2 : remove a meeting "<<endl;
        cout<<"enter 3 : find a meeting "<<endl;
        cout<<"enter 4 : clean your diary "<<endl;
        cout<<"enter other number : for exit "<<endl;
        cin>>choose;
        switch(choose){
            case 1:{
                 cout<<"enter a begin hour "<<endl;
                 cin>>begin;
                 cout<<"enter an end hour "<<endl;
                 cin>>end;
                 cout<<"enter the subject of the meeting "<<endl;
                 cin>>subject;
                 try{
                       m=new meeting_t(begin,end,subject);
                      
                 }catch(int){
                     cout<<"your details are not good";
                     flag=1;
                 }
                 if(flag==0){
                      if(d.insert(m)==false){
                          cout<<"your meeting cant insert into the diary "<<endl;
                          delete m;
                      }
                 }
                 flag=0;
                 break;
                 
            }
            case 2:{
                cout<<"enter the begin hour of the meeting you want to remove "<<endl;
                cin>>begin;
                if(d.remove(begin)==false){
                      cout<<"your meeting is not there "<<endl;
                }
                break;
            }
            case 3:{
                cout<<"enter the begin hour of the meeting you want to find "<<endl;
                cin>>begin;
                meeting_t * n=d.findM(begin);
                if(n==NULL){
                      cout<<"your meeting is not there "<<endl;
                }else{
                      cout<<"the begin hour: "<<n->getBegin()<<endl;
                      cout<<"the end hour: "<<n->getEnd()<<endl;
                      cout<<"the subject : "<<n->getSub()<<endl;
    
                }
             break;    
            }
            case 4:{
                d.clean();
                break;
            }
            default:{
               choose=-1;
               break;
            }
        }
    }
    /*
    meeting_t * m=new meeting_t(2,3,"tomer");
    meeting_t * n;
    diary_t d;
    d.insert(m);
    n=d.findM(2);
    cout<<"the begin hour: "<<n->getBegin()<<endl;
    cout<<"the end hour: "<<n->getEnd()<<endl;
    cout<<"the subject : "<<n->getSub()<<endl;
    m=new meeting_t(7,8,"ravit");
    d.insert(m);
    n=d.findM(7);
    cout<<"the begin hour: "<<n->getBegin()<<endl;
    cout<<"the end hour: "<<n->getEnd()<<endl;
    cout<<"the subject : "<<n->getSub()<<endl;*/
    
    return 0;

}