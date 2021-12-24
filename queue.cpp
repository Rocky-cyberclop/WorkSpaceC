#include <stdio.h>
#include <malloc.h>
typedef int ElementType;
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
int Remain(Queue q){
    int count=0;
    while(!empty(q)){
        count++;
        q=q->Next;
    }
    return count;
}

void reset(int a[], int sokhach){
    int i;
    for(i=0; i<=sokhach; i++){
        a[i]=0;
    }
}

int main(){
    int sokhach,soquay,i;
    float thoigianxuli,thoigianden,x,tong;
    scanf("%i %i %f %f %f",&sokhach,&soquay,&thoigianxuli,&thoigianden,&x);

    int *a;
    a=(int*)malloc(sizeof(int)*sokhach);
    for(i=-soquay; i<=sokhach; i++){
        a[i]=0;
    }
    Queue q;
    makenull(&q);

    for (i = 1; i <= soquay; i++)
    {
        int j;
        for (j = 1; j <= sokhach; j++)
        {
            EnQueue((j*thoigianden),&q);
        }
        j=1;
        reset(a,sokhach);
        while(!empty(q)){
            a[j-i]=Front(q)+thoigianxuli;
            tong+=a[i]-Front(q);
            j++;
            DeQueue(&q);
        }




        printf("So quay: %i; Thoi gian cho trung binh: %.1f",i,(tong/sokhach));

        if(tong<=x){
            printf("=> Sieu thi se mo %i quay",i);
            return 0;
        }
    }
    
    printf("Voi %i quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.",soquay,(tong/sokhach));

    
    
    return 0;
}