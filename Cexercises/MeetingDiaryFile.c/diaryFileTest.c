#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diaryFile.h"




int main(){
     int capacity=0,choose=0,error=1;
     float begin;
     Celander_t1 * ca;
     Meeting_t * me;
     printf("enter a capacity ");
     scanf("%d",&capacity);
     ca=createAD(capacity);
   
     while(choose!=-1){
        printf("\n");
        printf("press 1 for loadFromFile \n");
        printf("press 2 for createMeeting \n");
        printf("press 3 for insert \n");
        printf("press 4 for remove \n");
        printf("press 5 for find \n");
        printf("press 6 for printf \n");
        printf("press 7 for savePrintf \n");
        printf("press -1 for exit \n");

        scanf("%d",&choose);
        switch(choose){
            
            case 1:
                  loadFromFile(ca);
                 
                  break;
            
            case 2:
                  me=createMeeting();
                  break;
            case 3:
                  error=insert(ca,me);
                  if(error==0){
                    printf("cant insert ");
                  }
                  break;
            case 4:
                  printf(" remove your meeting, enter a begin hour ");
                  scanf(" %f",&begin);
                  error=Remove(ca,begin);
                  if(error==0){
                    printf("cant remove ");
                  }
                  break;
            case 5:
                  printf(" find your meeting, enter a begin hour ");
                  scanf(" %f",&begin);
                  me=Find(ca,begin);
                  if(me==NULL){
                    printf("cant find ");
                  }else{
                      printf("your meeting is %f - %f in room %d ",me->begin, me->end , me->room);
                  }
                  break;
            case 6:
                  print(ca);
             
                  break;
            case 7:
                   savePrintf(ca);
             
                  break;
           
            default: 
                    break;
          }
            
     }
     
     
    
	
    
     
     destroy(ca);
   
        
      return 0; 



}
