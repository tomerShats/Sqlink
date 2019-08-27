#include <stdlib.h>
#include <stdio.h>
#include "hashTable.h"



struct node
{
   void * key;
   void * value;
   struct node * next;

};

struct  hashtable_t
{
    struct node ** items;
    size_t size;
    hashFunction funcHash;
    elemCompare funcCompare;

};


typedef struct node node;

static node *ht_newpair( void *key, void *value ) {
	node *newpair;

	if((newpair = malloc(sizeof(node))) == NULL) {
		return NULL;
	}
	 newpair->key =key;
	 newpair->value =value;
	 newpair->next = NULL;

	return newpair;
}

hashtable_t * createHash(size_t size,hashFunction funcHash,elemCompare funcCompare){
   hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;
	
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}
	
	if( ( hashtable->items = malloc( sizeof( node* ) * size*(1.3) ) ) == NULL ) {
        free(hashtable);
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->items[i] = NULL;
	}
	hashtable->size = size*1.3;
    hashtable->funcHash=funcHash;
    hashtable->funcCompare=funcCompare;

	return hashtable;	
}    


AdtStatus  destroyHash(hashtable_t * hash,destroyElem funcDestroyKey,destroyElem funcDestroyValue, void * context){
    int i=0;
    node *next;
    node * after;
    if(hash==NULL){
        return AllocationError;
    }
    for(i=0;i<hash->size;i++){
         next=hash->items[i];
         while((next != NULL) && (next->key != NULL)){
           after=next->next;
           deleteHash(hash,next->key,funcDestroyKey,funcDestroyValue,context);
           next=after;
         }
        
    }
    /*for(i=0;i<hash->size;i++){
        funcDestroyKey(hash->items[i]->key,context);
        funcDestroyValue(hash->items[i]->value,context);
    }*/
    free(hash->items);
    free(hash);
    return OK;
}

AdtStatus   insertHash(hashtable_t * hash,void * key,void * value){
    
    int bin = 0;
	node *newpair = NULL;
	node *next = NULL;
	node *last = NULL;

     if(hash==NULL){
        return AllocationError;
    }

	bin =(hash->funcHash(key))%(hash->size);

	next = hash->items[ bin ];

	while( (next != NULL) && (next->key != NULL) && ((hash->funcCompare(key, next->key)) > 0 )) {
		last = next;
		next = next->next;
	}
	/* There's already a pair.*/
	if( next != NULL && next->key != NULL && hash->funcCompare(key, next->key) == 0 ) {
		return itemIsInHash;
	/* Nope, could't find it.  Time to add a pair. */
	} else {
		newpair = ht_newpair(key, value);

		/* We're at the start of the linked list in this bin. */
		if(next == hash->items[ bin ]) {
			newpair->next = next;
			hash->items[ bin ]= newpair;
            
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
    return OK;
    
}

AdtStatus   findHash(hashtable_t * hash, void * key,void ** value){
    int bin=0;
    node * next;
     if(hash==NULL){
        return AllocationError;
    }
    bin=(hash->funcHash(key))%(hash->size);
    next = hash->items[ bin ];
    while((next != NULL) && (next->key != NULL) && ((hash->funcCompare(key, next->key))!=0)){
        next=next->next;
    }
    if(next!=NULL) {
       *value=next->value;
       return OK;
    }else{
        
        return notInHash;
    }
   
}

AdtStatus   deleteHash(hashtable_t * hash, void * key,destroyElem funcDestroyKey,destroyElem funcDestroyValue,void * context){
     int bin=0;
    node * next;
    node * last=NULL;
     if(hash==NULL){
        return AllocationError;
    }
    bin=(hash->funcHash(key))%(hash->size);
    next = hash->items[ bin ];
    while((next != NULL) && (next->key != NULL) && ((hash->funcCompare(key, next->key))!=0)){
        last=next;
        next=next->next;
    }
    if(next!=NULL) {
        if(last==NULL){
            if(next->next!=NULL){
                hash->items[bin]=next->next;
                funcDestroyKey(next->key,context);
                funcDestroyValue(next->value,context);
            }else{
                hash->items[bin]=NULL;
                funcDestroyKey(next->key,context);
                funcDestroyValue(next->value,context);
            }
              
        }else if(next->next!=NULL){
            last->next=next->next;
            funcDestroyKey(next->key,context);
            funcDestroyValue(next->value,context);
            

        }else{
            last->next=NULL;
            funcDestroyKey(next->key,context);
            funcDestroyValue(next->value,context);
        }
       return OK;
    }else{
        return notInHash;
    }
   
}

AdtStatus   hashForEach(hashtable_t * hash,  printElem funcPrint){
    int i;
    node * next;
    if(hash==NULL){
        return AllocationError;
    }
    for(i=0;i<hash->size;i++){
         next=hash->items[i];
         while((next != NULL) && (next->key != NULL)){
         funcPrint(next->value);
         next=next->next;
         }
        
    }

    return OK;

}




