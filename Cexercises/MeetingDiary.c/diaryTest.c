#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diary.h"




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
        printf("press 1 for createMeeting \n");
        printf("press 2 for insert \n");
        printf("press 3 for remove \n");
        printf("press 4 for find \n");
        printf("press 5 for printf \n");
        printf("press -1 for printf \n");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                  me=createMeeting();
                  break;
            case 2:
                  error=insert(ca,me);
                  if(error==0){
                    printf("cant insert ");
                  }
                  break;
            case 3:
                  printf(" remove your meeting, enter a begin hour ");
                  scanf(" %f",&begin);
                  error=Remove(ca,begin);
                  if(error==0){
                    printf("cant remove ");
                  }
                  break;
            case 4:
                  printf(" find your meeting, enter a begin hour ");
                  scanf(" %f",&begin);
                  me=Find(ca,begin);
                  if(me==NULL){
                    printf("cant find ");
                  }else{
                      printf("your meeting is %f - %f in room %d ",me->begin, me->end , me->room);
                  }
                  break;
            case 5:
                  print(ca);
             
                  break;
            default: 
                    break;
          }
            
     }
     
     
    
	
    
     
     destroy(ca);
   
        
      return 0; 



}
