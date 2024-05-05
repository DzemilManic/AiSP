#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 15 

/*
typedef struct Node{
	int data;
	struct Node*next;
	struct Node*prev;
}Node;

Node*first=NULL;

int isEmpty(){
	if(first==NULL) 
		return 1;
	return 0;
}
Node*GetNewNode(int elem){
	Node*newNode=(Node*)malloc(sizeof(Node));
	newNode->next=NULL;
	newNode->prev=NULL;
	newNode->data=elem;
	return newNode;
}
void InsertAtTheEnd(int elem){
	Node*temp=GetNewNode(elem);
	if(isEmpty()){
		first=temp;
		return;
	}
	Node*t=first;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    temp->prev=t;
}
void Display(Node*first){
	if(isEmpty())
		return;
	Node*t=first;
	while(t){
		printf("%d ", t->data);
		t=t->next;
	}
}
float srednjavrednost(Node*first){
	float s=0, br=0;
	if(isEmpty()){
		printf("Lista nema elemenata");
	}
	Node*t=first;
	while(t){
		s+=t->data;
		br++;
		t=t->next;
	}
	return (s/br);
}
bool search(Node*first, int elem){
   if(isEmpty()){
   	printf("prazna lista");
   }
   Node*t=first;
   while(t!=NULL){
       if(t->data==elem){
           return true;
       }
       t=t->next;
   }
   return false;
}

int main(){
	float srednjavr;
	InsertAtTheEnd(1);
	InsertAtTheEnd(2);
	InsertAtTheEnd(3);
	Display(first);
	srednjavr=srednjavrednost(first);
	printf("\nsrednja vrednost %f\n", srednjavr);
	printf("%d",search(first, 5));
	return 0;
}

*/
int CQ[SIZE], f=-1, r=-1;

int  CQfull(){                     
    if((f==r+1) || (f==0 && r==SIZE-1)) 
		return 1;
	return 0;
}
int CQempty(){
    if(f== -1) return 1;
    return 0;
}

int CQdelete()
{                      
    int elem;
    if (CQempty()) {
        printf("red prazan");
        return(-1);
    }
    else 
    {
        elem = CQ[f];
        if (f == r) { f = -1; r = -1; }
        else
            f = (f + 2) % SIZE;
        return(elem);
    }
}

void insert(int elem1, int elem2)
{                       
    if(CQfull())
		printf("red pun");
    else{
        if(f==-1)
            f = 0;
        r=(r+2)%SIZE;
        if (r!=0)
            CQ[r-1]=elem1;
        else
            CQ[14]=elem1;
        CQ[r]=elem2;
    }
}
void Display(){
    int i;
    if(CQempty())
		printf("Prazan red");
    else{
        for(i=f;i!=r;i=(i+1)%SIZE)
            printf("%d ",CQ[i]);
        printf("%d ",CQ[i]);
	}
}

void brisiPozicija(int x){
	int i;
	if (CQempty()){
		printf("prazan red");
	}
	else{
		int nadjen = -1;
		for(i=f;i!=r;i=(i+1)%SIZE){
			if (i==x-1){
				nadjen=i;
				break;
			}
		}
		if (r==x-1)
			nadjen=r;
		if (nadjen==-1){
			printf("nije nadjen");
		}
		else{
			int br=0;
			for(i=f;i<=r;i++)
				br++;
			int pomocni[br-1];
			int pomInd=0;
			for (i=f;i<=r;i++){
				if (i!=nadjen){
					pomocni[pomInd]=CQ[i];
					pomInd++;
				}
			}
			f=0;
			r=br-2;
			for(i=f;i<=r;i++)
				CQ[i]=pomocni[i];
		}
	}
}

void brisiPozicija2(int a) {
	int i;
    if (CQ[a] == NULL) {
        printf("ne postoji element na toj poziciji\n");
    }
    else {
        for (i = a; i !=f; i = (i - 1) % SIZE) {
            CQ[i] = CQ[(i - 1) % SIZE];
        }
        f = (f + 1) % SIZE;
    }
}
int main(){
	insert(1,2);
	insert(3,4);
	insert(5,6);
	insert(1,2);
	insert(3,4);
	insert(5,6);
	//DeletePosition(3);
	CQdelete();
	brisiPozicija(5);
	Display();
	return 0;
}

