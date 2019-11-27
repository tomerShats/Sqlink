#ifndef MQ_H
#define MQ_H


#define MQ_SEND_MSG 100
#define MQ_RECV_MSG 101

#pragma pack(push,1)
struct mq_reg 
{
    char * data;
    int size;
};

#pragma pack(pop)

#endif

