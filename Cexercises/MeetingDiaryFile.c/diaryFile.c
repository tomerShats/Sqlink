#include <stdio.h>
#include <stdlib.h>
#include "diaryFile.h"



Celander_t1 * createAD(int capacity){

	   Celander_t1 * ca;
           ca=malloc(sizeof(Celander_t1));
           if(ca==NULL){
              return NULL;
           }

           ca->capacity=capacity;
	   ca->count=0;
           ca->day=malloc(sizeof(Meeting_t*)*capacity);
           if(ca->day==NULL){
            free(ca);
            return NULL;
           }
	   

    return ca;
}

void loadFromFile(Celander_t1 *  ca){
  FILE * fp;
  float begin,end;
  int room,error=0;
  Meeting_t * me;
  if((fp=fopen("Meetings.txt","r"))!=NULL){   
        
         while(!feof(fp)){
            fscanf(fp,"%f%f%d",&begin,&end,&room);
            me=createMeetingFile(begin,end,room);
            insert(ca,me);
       
         }     
       fclose(fp);
             
       
  }    
  
}

Meeting_t * createMeetingFile(float begin,float end,int room){
 Meeting_t * me;
    me=malloc(sizeof(Meeting_t));
    if(me==NULL){
            return NULL;
    }
    me->begin=begin;
    me->end=end;
    me->room=room;

 return me;


}

Meeting_t * createMeeting(){
    float begin,end;
    int room;
    Meeting_t * me;
    me=malloc(sizeof(Meeting_t));
    if(me==NULL){
            return NULL;
    }
    do{
    printf("enter a begin time ");
    scanf(" %f",&begin);
    printf("enter aa end time ");
    scanf(" %f",&end);
    }while((begin>=end)||(begin>24)||(end>24)||(begin<0)||(end<0));
    printf("enter a room number ");
    scanf(" %d",&room);
    me->begin=begin;
    me->end=end;
    me->room=room;

 return me;


}



int insert(Celander_t1 *  ca,Meeting_t * me){
  int i,lastIndex,j,ans=0;
  Meeting_t ** temp;
  if((ca!=NULL)&&(me!=NULL)){

       temp=ca->day;
       if(ca->count==0){
           if((ca->count)==(ca->capacity)){
                temp=(Meeting_t **)realloc(ca->day, sizeof(Meeting_t *)*((ca->capacity)*2)); 
                if(temp==NULL){
                    return 0;
                }
               ca->day=temp;
               (ca->capacity)*=2;
            }
          ca->day[0]=me;
          ca->count++;
          ans=1;
           
       }
       else if((ca->day[0]->begin) >= (me->end)){
         if((ca->count)==(ca->capacity)){
                temp=(Meeting_t **)realloc(ca->day, sizeof(Meeting_t *)*((ca->capacity)*2)); 
                if(temp==NULL){
                    return 0;
                }
               ca->day=temp;
               (ca->capacity)*=2;
            }
          for(i=ca->count;i>0;i--){
              ca->day[i]=ca->day[i-1];
              
          }
            ca->day[0]=me; 
            ca->count++;
            ans=1;
   
          
       }else if((ca->day[ca->count-1]->end) <= (me->begin)){
            if((ca->count)==(ca->capacity)){
                temp=(Meeting_t **)realloc(ca->day, sizeof(Meeting_t *)*((ca->capacity)*2)); 
                if(temp==NULL){
                    return 0;
                }
               ca->day=temp;
               (ca->capacity)*=2;
            }
            ca->day[ca->count]=me; 
            ca->count++;
            ans=1;

       }else{
            
            for(i=1;i<ca->count;i++)
            {  
              if(((me->begin)>=(ca->day[i-1]->end))&&((me->end)<=(ca->day[i]->begin))){
                     if((ca->count)==(ca->capacity)){
                         temp=(Meeting_t **)realloc(ca->day, sizeof(Meeting_t *)*((ca->capacity)*2)); 
                          if(temp==NULL){
                             return 0;
                          }
                        ca->day=temp;
                       (ca->capacity)*=2;
                     }
                lastIndex=i;
                    for(j=ca->count;j>lastIndex;j--){
                        ca->day[j]=ca->day[j-1];
                    }
                ca->day[lastIndex]=me; 
                ca->count++;
                ans=1;
   
               }
          }

           
       }
      
       
       
      
    
  }
  return ans;
}

int Remove(Celander_t1 *  ca,float begin){
   int i=0,j=0;
      
      if(ca!=NULL){
	  for(i=0;i<ca->count;i++){
	     if(ca->day[i]->begin==begin){
		 free(ca->day[i]);
                 for(j=i;j<ca->count;j++){
                     ca->day[j]=ca->day[j+1];
                 }
               ca->count--;
               return 1;
	     }
            
	  }
	 
      }
  
    return 0;
}

Meeting_t *  Find(Celander_t1 *  ca,float begin){
  int i=0;
      
      if(ca!=NULL){
	  for(i=0;i<ca->count;i++){
	     if(ca->day[i]->begin==begin){
		 return ca->day[i];
	     }
	  }
	 
      }
  
    return NULL;
}

void print(Celander_t1 *  ca){
   int i=0;
  if(ca!=NULL){
    for(i=0;i<ca->count;i++){
       printf("begin hour= %f ",ca->day[i]->begin);
       printf("end hour= %f ",ca->day[i]->end);
       printf("room number= %d ",ca->day[i]->room);
    }
  }

}

void savePrintf(Celander_t1 *  ca){
   int i=0;
   FILE * fp;
  if(ca!=NULL){
      if((fp=fopen("Meetings.txt","w"))!=NULL){

          for(i=0;i<ca->count;i++){
             fprintf(fp,"%f  ",ca->day[i]->begin);
             fprintf(fp,"%f  ",ca->day[i]->end);
             fprintf(fp,"%d\n",ca->day[i]->room);
          }
       fclose(fp);
      }
  }

}



void destroy(Celander_t1 *  ca){
  int i=0;
  if(ca!=NULL){
         for(i=0;i<ca->count;i++){
              if(ca->day[i]!=NULL){
                  free(ca->day[i]);
              }
    }

         free(ca->day);
         free(ca);
   }
  

}




















