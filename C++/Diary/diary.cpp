# include <iostream>
# include <string>
# include <iterator>
# include <map>
# include <algorithm>
# include "meeting.h"
# include "diary.h"
bool diary_t::insert (meeting_t * meet){
     it=m.begin(); 
         meeting_t * n;
         meeting_t * n2;
         

        if(it==m.end()){
            m[meet->getBegin()]=meet;
            return true;
        }
        n=it->second;
        if(meet->getEnd() < n->getBegin()){
             m[meet->getBegin()]=meet;
            return true;
        }
        it=m.end();
        it--;
        n=it->second;
         if(meet->getBegin() > n->getEnd()){
             m[meet->getBegin()]=meet;
            return true;
        }
        if(m.size()==1){
            return false;
        }
        it=m.begin();
        n=it->second;
        it++;
        n2=it->second;
        while(it!=m.end())
        {   
           if(meet->getBegin() > n->getEnd() && meet->getEnd() < n2->getBegin()){
                m[meet->getBegin()]=meet;
                return true;
           }
           n=it->second;
           it++;
           n2=it->second;
         
        }
       
        return false;
     }
     