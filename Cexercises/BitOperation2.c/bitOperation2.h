#ifndef DA_T
#define DA_T

struct LRchar{
 unsigned int right :4;
 unsigned int left :4;
};
typedef struct LRchar LRchar;

union un{
  LRchar lr;
  char c;
};
typedef union un un;


int compress2(char* c);
int compress1(char* c);



#endif
