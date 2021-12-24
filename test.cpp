#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef char ElementType;
struct Node{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node* Queue;
void makenull(Queue* Q){
    (*Q)=(struct Node*)malloc(sizeof(struct Node));
    (*Q)->Next=NULL;
}
int empty(Queue Q){
    return Q->Next==NULL;
}
Queue First(Queue Q){
    return Q;
}
Queue End(Queue Q){
    while(Q->Next!=NULL){
        Q=Q->Next;
    }
    return Q;
}
ElementType Front(Queue Q){
    if(empty(Q))printf("Loi! Hang doi rong!");
    else return Q->Next->Element;
}
void EnQueue(int x, Queue *Q){
    Queue T;
    makenull(&T);
    T->Element=x;
    if(empty(*Q))(*Q)->Next=T;
    else {
        Queue E=End(*Q);
        E->Next=T;
    }
}
void DeQueue(Queue *Q){
    if(empty(*Q))printf("Loi! Hang doi rong!");
    else{
        Queue T=First(*Q)->Next;
        (*Q)->Next=T->Next;
        free(T);
    }
}
void read(Queue *Q){
    makenull(Q);
    int n,x;
    printf("Nhap so luong phan tu: ");
    scanf("%i",&n);
    for(int i=0; i<n; i++){
        scanf("%i",&x);
        EnQueue(x,Q);
    }
}
void print(Queue *Q){
    while(!empty(*Q)){
        printf("%i ",Front(*Q));
        DeQueue(Q);
    }
}

char upper(char c){
    if('a' <= c && c <= 'z'){
        c = c - ('a' - 'A');
    }
    return c;
}
int main(){
    char a[50];
    fgets(a,50,stdin);
    if(a[strlen(a)-1]=='\n')a[strlen(a)-1]='\0';
    int i=0;
    Queue q;
    makenull(&q);
    while(a[i]!='\0'){
        if(a[i]>='a'&&a[i]<='z')EnQueue(a[i],&q);
        i++;
    }
    print(&q);

    return 0;
}