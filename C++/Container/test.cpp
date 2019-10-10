# include <iostream>
# include <string>
# include <string.h>
# include <vector>
# include <list>
# include <iterator>
# include "Equal_t.h"
# include "container_t.h"
template <class T,class C >
  void func(tContainer_t<T ,C> * c){
         T choose=0;
         while(choose!=-1){
          cout<<"enter 1 : insert number "<<endl;
          cout<<"enter 2 : remove number "<<endl;
          cout<<"enter 3 : delete number "<<endl;
          cout<<"enter 4 : number of elements "<<endl;
          cout<<"enter 5 : first number "<<endl;
          cout<<"enter 6 : last number "<<endl;
          cout<<"enter 7 : is empty?  "<<endl;
          cout<<"enter 8 : find number "<<endl;
          cout<<"enter 9 : get the i number   "<<endl;
          cout<<"enter 10 : remove all "<<endl;
          cout<<"enter 11 : delete all "<<endl;
          cout<<"enter other num for exit "<<endl;
          cin>>choose;
          switch(choose){
              case 1: {
                   T num;
                T * n;
                cout<<"enter a num "<<endl;
                 cin>>num;
                n=new int(num);
                c->insertEnd(n);
                break;
              
              }
                case 2: {
                   T num;
                   T * n;
                cout<<"enter a num to remove"<<endl;
                cin>>num;
                n=c->removeElem(num);
                if(n==0){
                  cout<<"not found "<<endl;
                }else{
                    cout<<"your number that remove : "<<*n<<endl;
                }
                break;
                }
                case 3: {
                   T num;
                cout<<"enter a num to remove"<<endl;
                cin>>num;
                if(c->deleteElem(num)==false){
                  cout<<"not found "<<endl;
                }else{
                    cout<<"your number that delete "<<endl;
                }
                break;
                }
                 case 4: {
                  cout<<"number of elemnts : "<<c->numOfElem()<<endl;
                break;
                }
                 case 5: {
                cout<<"the first element is: "<<*(c->firstElem())<<endl;
                break;
                }
                 case 6: {
                  cout<<"the last element is: "<<*(c->lastElem())<<endl;
                
                break;
                }
                 case 7: {
                if(c->isEmpty()==false){
                  cout<<"not empty "<<endl;
                }else{
                    cout<<"empty "<<endl;
                }
                break;
                }
                 case 8: {
                   T num;
                   T * n;
                cout<<"enter a num to find "<<endl;
                cin>>num;
                n=c->findElem(num);
                if(n==0){
                  cout<<"not found "<<endl;
                }else{
                    cout<<"your number founded "<<*n<<endl;
                }
                break;
                }
                case 9: {
                   
                   unsigned int i;
                   T * n;
                   int flag=0;
                cout<<"enter an index to get "<<endl;
                cin>>i;
                try{
                  cout<<"the middle number is: "<<*((*c)[i])<<endl;
                }catch(unsigned int){
                  cout<<"you are in list "<<endl;
                }
         
                break;
                }
                 case 10: {

                  c->removeAll();

                break;
                }
                 case 11: {
                   c->deleteAll();
                break;
                }
                
                
              default: {choose=-1; 
              break;}
          }
          
          
      }
      cout<<"num of element "<<c->numOfElem()<<endl;
    
      }
    
int main()
{     int choose=0;
          cout<<"enter 1 : build a vector or 2 : for list "<<endl;
          cout<<"enter other num for exit "<<endl;
          cin>>choose;
          switch(choose){
              case 1:{
                 
                tContainer_t<int ,vector < int *> > *c=new tContainer_t<int ,vector< int *> >();
                func<int , vector <int *> >(c);
                break;
              
              }
                case 2:{ 
                 
                 tContainer_t<int ,list <int *>  > *c=new tContainer_t<int ,list <int *>  >();
                 func<int , list <int *> >(c);
                break;
              
                }
                default: {choose=-1; 
                break;}
          }
          
         return 0;

    
}
