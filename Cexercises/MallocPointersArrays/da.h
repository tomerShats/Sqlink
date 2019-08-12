#ifndef DA_T

#define DA_T

typedef struct{

int capacity;
int count;
int ** arr;

}Da_t;


Da_t * create(int capacity);
int insert(Da_t* da,int * num);
void print(Da_t* da);
void destroy(Da_t* da);


#endif
