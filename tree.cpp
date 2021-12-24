#include <stdio.h>
#include <malloc.h>
typedef int DataType;
struct Node{
   int Data;
   struct Node *Left, *Right;
};
typedef struct Node* Tree;
Tree initTree(){
    Tree t;
    t=NULL;
    return t;
}
Tree createTree(int x, Tree l, Tree r){
    Tree t;
    t=(Tree)malloc(sizeof(struct Node));
    t->Data=x;
    t->Left=l;
    t->Right=r;
    return t;
}
int isEmpty(Tree t){
    return t==NULL;
}
void inOrder(Tree t){
    if(t==NULL)return;
    else{
        inOrder(t->Left);
        printf("%d ",t->Data);
        inOrder(t->Right);
    }
}
void  insertNode(int x, Tree* t){
    if((*t)==NULL){
        Tree p;
        p=(struct Node*)malloc(sizeof(struct Node));
        p->Data=x;
        p->Left=NULL;
        p->Right=NULL;
        (*t)=p;
    }
    else{
        if(x==(*t)->Data)return;
        if(x>(*t)->Data)insertNode(x,&(*t)->Right);
        else insertNode(x,&(*t)->Left);
    }
}
Tree findElement(DataType x, Tree t){
    if(t==NULL)return NULL;
    else{
        if(x==t->Data)return t;
        else{
            if(findElement(x,t->Left)!=NULL)return findElement(x,t->Left);
            return findElement(x,t->Right);
        }
    }
}

Tree minLeft(Tree t){
    if(t==NULL)return NULL;
    else {
        if(t->Left==NULL)return t;
        return minLeft(t->Left);
    }
}
Tree minRight(Tree t){
    if(t==NULL)return NULL;
    else {
        if(t->Right==NULL)return t;
        return minRight(t->Right);
    }
}


Tree findMaxLeft(Tree t){
    if(t->Left==NULL)return t;
    return findMaxLeft(t->Left);
}
void deleteNode(int x, Tree* t){
    if(t==NULL)return;
    else{
        if(x>(*t)->Data)deleteNode(x,&(*t)->Right);
        else if(x<(*t)->Data)deleteNode(x,&(*t)->Left);
        else{
            if((*t)->Right!=NULL){
                Tree t1=(*t)->Right,t2=(*t)->Left;
                (*t)=NULL;
                Tree tmp=findMaxLeft(t1);
                tmp->Left=t2;
                (*t)=t1;
            }
            else if((*t)->Left!=NULL)(*t)=(*t)->Left;
            else (*t)=NULL;
        }
    }
}
Tree getPrevious(int x, Tree t){
    if((t->Left==NULL&&t->Right==NULL)||t==NULL)return NULL;
    else{
        Tree minR = minRight(t->Left), minL = minLeft(t->Right);
        if(t->Data==x){
            if(minR!=NULL&&minR->Data<=x)return minR;
            return t->Left;
        }
        else if(x>t->Data){
            if(minL!=NULL&&minL->Data>=x)return t;
            return getPrevious(x,t->Right);
            
        }
        else return getPrevious(x,t->Left);
    }
}

Tree getNext(int x, Tree t){
    if((t->Left==NULL&&t->Right==NULL)||t==NULL)return NULL;
    else{
        Tree minR = minRight(t->Left), minL = minLeft(t->Right);
        if(t->Data==x){
            if(minL!=NULL&&minL->Data>=x)return minL;
            return t->Right;
        }
        else if(x<t->Data){
            if(minR!=NULL&&minR->Data<=x)return t;
            return getNext(x,t->Left);
            
        }
        else return getNext(x,t->Right);
    }
}

int main(){
    Tree t;
    t=initTree();
    insertNode(27,&t);
    insertNode(12,&t);
    insertNode(40,&t);
    insertNode(4,&t);
    insertNode(20,&t);
    insertNode(34,&t);
    insertNode(30,&t);
    insertNode(50,&t);


    int a[] = {4,12,20,27,30,34,40,50};
    for (size_t i = 0; i < 8; i++)
    {
        int x=a[i];
        Tree p = getNext(x,t);
        if(p!=NULL)printf("%i %i\n", a[i], p->Data);
        
    }
    
    // printf("%i ",minLeft(t->Right)->Data);

    return 0;
}