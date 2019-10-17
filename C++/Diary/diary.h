#pragma once
# include <iostream>
# include <string>
# include <iterator>
# include <map>
# include <algorithm>
# include "meeting.h"
using namespace std;

class diary_t{
    public: 
     virtual ~diary_t(){
        it=m.begin(); 
        meeting_t * n;   
        while(it!=m.end())
        {   n=it->second;
            m.erase(it);
            it++;
            delete n;
        }
     }
     diary_t(){
            
     }
    bool insert (meeting_t * meet);  
          
     
     meeting_t * findM(const float & begin){
         it=m.find(begin);
         if(it==m.end()){
             return NULL;
         }

         return it->second;
     }
     void clean(){
         m.clear();
     }

     bool remove( const float & begin )
     {   it=m.find(begin);
         if(it==m.end()){
             return false;
         }
         m.erase(it);
         return true;
     }
  
     

    private:
       map <float ,meeting_t *> m;
       typedef map<float ,meeting_t *>::iterator iter;
       iter it;
       diary_t(const diary_t & diar){};
       diary_t& operator= (const  diary_t& diar){};
};