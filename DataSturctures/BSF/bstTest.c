#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

void printWalk(int val);


int main(){
  
 bTree * tree;
 elementWalk func=printWalk;
 int i,error;
 tree=createTree();
insertTree(tree,10);
insertTree(tree,2);
insertTree(tree,14);
insertTree(tree,12);
insertTree(tree,6);
insertTree(tree,0);
insertTree(tree,18);
insertTree(tree,11);
printf("inOrder:\n");
walkTree(tree,func,1);
printf("\npreOrder:\n");
walkTree(tree,func,2);
printf("\npostOrder:\n");
walkTree(tree,func,3);
deleteTree(tree,0);
deleteTree(tree,2);
deleteTree(tree,10);
deleteTree(tree,18);
printf("\ninOrder after remove 0,2,10,18\n");
walkTree(tree,func,1);
printf("\nsearch 6 in the tree\n");
error=searchTree(tree,6);
if(error==0){
    printf("it is here\n");
}



destroyTree(tree);
}


void printWalk(int val){
    printf("%d ",val);

}