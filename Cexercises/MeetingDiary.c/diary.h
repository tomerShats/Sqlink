#ifndef DA_T

#define DA_T
typedef struct Celander_t Celander_t1
typedef struct{

float begin;
float end;
int room;

}Meeting_t;


struct Celander_t{
Meeting_t ** day;
int capacity;
int index;

};

Celander_t1 * createAD(int capacity);
Meeting_t * meeting();
int Insert(Celander_t1 *  ca,Meeting_t * ma);
int Remove(Celander_t1 *  ca,float begin);
Meeting_t *  Find(Celander_t1 *  ca,float begin);
void print(Celander_t1 *  ca);
void destroy(Celander_t1 *  ca);


#endif
