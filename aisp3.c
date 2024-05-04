#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Data;
    struct Node* Next;
}Node;

Node *First=NULL, *Last=NULL, *Temp=NULL;

//kreiranje liste
void Create(int elem)
{
	Temp=(struct Node*)malloc(sizeof(struct Node));
	Temp->Data=elem;
	Temp->Next=NULL;
	if(IsEmpty()){
		First=Temp;
		Last=Temp;
	}
	else{
		Last->Next=Temp;
		Last=Temp;
	}

}
//proverava da li je lista prazana
int IsEmpty() 
{
	if(First==NULL)
		return 1;
	else return 0;
}

//insert after direktno
void InsertAfter(Node *p,int Value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->Data=Value;
    newNode->Next=p->Next;
    p->Next=newNode;
}

//insert before direktno
void InsertBefore(Node *p,int Value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->Data=p->Data;
    p->Data=Value;
    newNode->Next=p->Next;
    p->Next=newNode;
}
//delete after direktno
void DeleteAfter(Node*p){
    Node *temp=p->Next;
    p->Next=temp->Next;
    free(temp);
    temp=NULL;
}
//rekurzivna funkcija za racunanje sume elemenata liste
int Suma(Node *First)
{
    Node*p=First;
    if (p==NULL)
        return 0;
    else
        return Suma(p->Next) + p->Data;
}
//posle svakog neparnog elementa pise 0, a posle parnog 1
Node* InsertElement(Node* First){
    Node*p=First;
    while(p!=NULL){
        Node*temp=(Node*)malloc(sizeof(Node));
        if(p->Data%2==0){
            temp->Data=1;
            temp->Next=p->Next;
            p->Next=temp;
            p=temp->Next;
        }
        else{
            temp->Data=0;
            temp->Next=p->Next;
            p->Next=temp;
            p=temp->Next;
        }
    }
}
//stampanje liste
void Display(Node *First){
    Node*p=First;
    while(p!=NULL){
        printf("%d\n",p->Data);
        p=p->Next;
    }
}
int main(){
	/*rucno kreiranje cvorova
	Node * First = (struct Node*)malloc (sizeof(struct Node));
    Node * Second = (struct Node*)malloc (sizeof(struct Node));
    Node * Third = (struct Node*)malloc (sizeof(struct Node)); */
	Create(1);
	Create(2);
	Create(3);
	IsEmpty();
	InsertAfter(First->Next, 14);
	InsertBefore(Last, 0);
	Display(First);
	printf("Suma iznosi=%d\n",Suma(First));
	InsertElement(First);
	Display(First);
	return 0;
}
