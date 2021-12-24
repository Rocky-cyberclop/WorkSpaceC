#include <stdio.h>
#include <malloc.h>
typedef int ElementType;
struct Node{
	ElementType Elements;
	struct Node *Next; 
};
typedef struct Node* Position;
typedef Position List;
void MakeNull(List* Header){
	(*Header)=(struct Node*)malloc(sizeof(struct Node));
	(*Header)->Next=NULL;
}
int Empty(List L){
	return L->Next==NULL;
}
Position First(List L){
	return L;
}
Position End(List L){
	while(L->Next!=NULL)L=L->Next;
	return L;
}
Position Next(Position P, List L){
	return P->Next;
}
ElementType Retrieve(Position P, List L){
	if(P->Next!=NULL){
		return P->Next->Elements;
	}
}

int Member(ElementType x, List L){
	for(; L->Next!=NULL; L=L->Next)if(Retrieve(L,L)==x)return 1;
	return 0;
}
Position Locate(ElementType X, List L){
    Position p=L;
    while(p->Next!=NULL){
        if(Retrieve(p,L)==X){
            return p;
        }
        p=p->Next;
    }
    return p;
}
void Insert(ElementType X, Position P, List* L){
	Position T;
	T=(Node*)malloc(sizeof(struct Node));
	T->Elements=X;
	T->Next=P->Next;
	P->Next=T;
}
void Delete(Position P, List* L){
	Position T;
	if(P->Next!=NULL){
		T=P->Next;
		P->Next=T->Next;
		free(T);
	}
}

void Read(List *L){
	MakeNull(L);
	int n;
	ElementType x;
	printf("Nhap so luong phan tu: ");scanf("%i",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%i",&x);
		Insert(x,End(*L),L);
	}
}
void Print(List L){
	for(Position P=First(L); P->Next!=NULL; P=Next(P,L))printf("%i ", Retrieve(P,L));
	printf("\n");
}

void DeleteX(ElementType X, List *pL){
    Position P=Locate(X,*pL);
    while(P->Next!=NULL){
        Delete(P,pL);
        P=Locate(X,*pL);
    }
}
void InsertAt(ElementType x, int pos, List *L){
	Position t;
	t=*L;
	int p=1;
	while(p!=pos){
		t=t->Next;
		p++;
	}
	Insert(x,t,L);
}
void DeleteAt(int pos, List *L){

}
void DeleteDup(List* L){
    Position P=*L,q,t;
	while(P->Next!=NULL){
		q=P->Next;
		t=Locate(Retrieve(P,P),q);
		while(t->Next!=NULL){
			Delete(t,&q);
			t=Locate(Retrieve(P,P),q);
		}

		P=q;
	}
}
void printNM(List L1, List L2){
    Position P1=L1;
    for(; P1->Next!=NULL; P1=P1->Next)printf("%i ",Retrieve(P1,P1));
    for(; L2->Next!=NULL; L2=L2->Next){
        if(!Member(Retrieve(L2,L2),L1))printf("%i ",Retrieve(L2,L2));
    }
}
void Sort(List *L){
	Position p,q;
	p=(*L);
	while(p!=End(p)){
		q=p->Next;
		while(q!=End(q)){
			if(Retrieve(p,p)>Retrieve(q,q)){
				int t=Retrieve(p,p);
				p->Next->Elements=Retrieve(q,q);
				q->Next->Elements=t;
			}
			q=Next(q,q);
		}
		p=Next(p,p);
	}
}
void append(ElementType x, List *pL){
    List p=End(*pL);
    List q;
    MakeNull(&q);
    q->Elements=x;
    p->Next=q;
}


int main(){
	List L;
	MakeNull(&L);
	append(10,&L);
	append(20,&L);
	Print(L);
	
	

	return 0;
}