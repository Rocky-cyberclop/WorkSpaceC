#include <stdio.h>
#include <math.h>
#define Maxlength 50
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements [Maxlength];
	int Last;
}List;
void makenullList(List *pL)
{
	(*pL).Last=0;	
	
}

int fullList(List L)
{
	return L.Last==Maxlength;
}

int emptyList(List L)
{
	return L.Last==0;
}

Position first (List L)
{
	return 1;
}

Position endList(List L){
    return L.Last+1;
}

Position next(Position P, List L){
    return P+1;
}

Position previous(Position P, List L){
    return P-1;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

void insertList(ElementType x, Position p, List *pL)
{
	if (fullList(*pL))
		printf("Danh sach day");
  	else if ((p<1) || (p>pL->Last+1))
	    printf("Vi tri khong hop le");
	else 
	{
		Position q;   
		for(q=pL->Last; q>=p; q--)
			pL->Elements[q]=pL->Elements[q-1];	  
		pL->Elements[p-1]=x;	  
		pL->Last++;	
	}
}

// Ham xoa phan tu
void deleteList(Position P, List *L){
    if((P > L->Last) || (P<1))
	printf("\nVi tri khong hop le !!!");
    else
	if(emptyList(*L))
	  printf("\nDanh sach rong !");
	else{
	  Position i;
	  for(i=P; i<L->Last; i++)
	  {
	     L->Elements[i-1] = L-> Elements[i];
	  }
	  L->Last--;
	}
}

// Tim vi tri dau tien chua x
Position locate (ElementType x, List L)
{
	Position p=first(L);
	int f=0;
	while (p!=endList(L)&& f==0)
	{
		if (retrieve(p,L)==x)
			f=1;
		else 
			p=next(p,L);
	}
	return p;
}

void Read_List(List *pL){
	int i, n;
	ElementType x;
	makenullList(pL);
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &x);
		insertList(x, endList((*pL)), pL);
	}
}


void print_List(List L){
	Position P;
	P= first(L);
	while(P != endList(L)){
		printf("%d ",retrieve(P,L));
		P= next(P,L);
	}
	printf("\n");
}

void hieu_2ds(List L1, List L2, List *pL){
	makenullList(pL);
	Position P;
	ElementType x;
	P = first(L1);
	x = retrieve(P,L1);
	while(P!=endList(L1)){
		if(locate(x, L2)==endList(L2))
			insertList(x,endList(*pL),pL);
		P=next(P,L1);
		x=retrieve(P,L1);
	}
}

int main(){
	List L1, L2, L3;
	Read_List(&L1);
	Read_List(&L2);
	print_List(L1);
	print_List(L2);
	hieu_2ds(L1,L2,&L3);
	print_List(L3);
	return 0;
}