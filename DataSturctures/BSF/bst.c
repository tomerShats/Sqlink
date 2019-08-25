#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


struct node
{
   int value;
   struct node*right;
   struct node*left;
};

struct bTree
{
   
  struct node* root;
};

typedef struct node node;

static void destroy_Rec(node * root){
    if(root!=NULL){
        destroy_Rec(root->left);
        destroy_Rec(root->right);
        free(root);
        
    }
}

static void inOrder(node * root,elementWalk func){
    if(root!=NULL){
        inOrder(root->left,func);
        func(root->value);
        inOrder(root->right,func);
    }

}

static void preOrder(node * root,elementWalk func){
     if(root!=NULL){
        func(root->value);
        inOrder(root->left,func);
        inOrder(root->right,func);
        
    }
}

static void postOrder(node * root,elementWalk func){
   if(root!=NULL){
        inOrder(root->left,func);
        inOrder(root->right,func);
        func(root->value);
    }

}

bTree * createTree(){     
     bTree * tree;
     tree=malloc(sizeof(bTree));
     if(tree==NULL){
        
         return NULL;
     }
     tree->root=NULL;
   return tree;
}


AdtStatus  insertTree(bTree * tree,  int _item){
    
    node * x;
    node * y=NULL;
    if(tree==NULL){
        return AllocationError;
    }
    
    x=tree->root;
   while(x!=NULL){
       y=x;
       if(_item< x->value){
           x=x->left;
       }else{
           x=x->right;
       }
   }
   if(y==NULL){
       y=malloc(sizeof(node));
       if(y!=NULL){
           y->value=_item;
           tree->root=y;
           return OK;
       }
       return AllocationError;
   }else if(_item<y->value){
          y->left=malloc(sizeof(node));
          if(y->left!=NULL){
           y=y->left;   
           y->value=_item;
           return OK;
       }
       return AllocationError;

   }else{
     y->right=malloc(sizeof(node));
          if(y->right!=NULL){
           y=y->right;   
           y->value=_item;
           return OK;
       }
       return AllocationError;
   }

    return OK;
    
}

AdtStatus   searchTree(bTree * tree,  int  _item){
    node * x;
    
    if(tree==NULL){
        return AllocationError;
    }
    if(tree->root==NULL){
        return AllocationError;
    }
    x=tree->root;
    while(x!=NULL){
        if(x->value==_item){
            return OK;
        }else if(x->value<_item){
            x=x->right;
        }else{
            x=x->left;
        }
    }
    return notInTree;
}


AdtStatus   deleteTree(bTree * tree,  int _item){
    int flag=0;
    node * x;
    node * deleteNode;
    node * y=NULL;
    if(tree==NULL){
        return AllocationError;
    }
    x=tree->root;
    while(x!=NULL){
        flag=1;
       if(x->value==_item){
           break;
       }
       y=x;
       if(_item< x->value){
           x=x->left;
       }else{
           x=x->right;
       }
    }
    
    if((x==NULL)||((y==NULL)&&(flag==0))){
        return notInTree;
    }else if((x->left==NULL)&&(x->right==NULL)){
           if(y->left==x){
               y->left=NULL;
           }else{
               y->right=NULL;
           } 
           free(x);
           return OK;
    }else if((x->left!=NULL)&&(x->right!=NULL)){
          deleteNode=x;
          x=x->right;
          
          while(x->left!=NULL){
              y=x;
              x=x->left;
              
          }
          deleteNode->value=x->value;
          if(x->right!=NULL){
              y->left=x->right;
              free(x);
              return OK;

          }else{
              y->left=NULL;
              free(x);
              return OK;
          }

    }else{
        if(x->left==NULL){
            if(y->right==x){
                y->right=x->right;
                free(x);
                return OK;
            }else{
                y->left=x->right;
                free(x);
                return OK;
            }
        }else{
            if(y->right==x){
                y->right=x->left;
                free(x);
                return OK;
            }else{
                y->left=x->left;
                free(x);
                return OK;
            }
        }
    }
    
}

AdtStatus    destroyTree(bTree * tree){
    if(tree->root=NULL){
       return AllocationError;
    }

    destroy_Rec(tree->root);
    return OK;

    
}

void walkTree(bTree * tree,elementWalk func,int order){
   switch(order){
       case 1:
         inOrder(tree->root,func);
         break;
       case 2:
         preOrder(tree->root,func);
         break;
       case 3:
         postOrder(tree->root,func);
         break;
       default: break;
   }
}

