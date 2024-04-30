#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int info;
    struct node* next;
}NODE;

NODE *front=NULL, *rear=NULL;

void Create(int x){
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    newNode->info=x;
    if(rear==NULL){
        front=newNode;
        rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
    rear->next=front;
}
void Display(NODE* front){
    NODE* p=front;
    if(front==NULL){
        return;
    }
    while(p!=rear){
        printf("%d\n",p->info);
        p=p->next;
    }
}

void InsertBefore(NODE* front, int pos, int x){
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    NODE* current=front, *p=front;
    newNode->info=x;
    while(pos!=1){
        current=current->next;
        pos--;
    }
    newNode->next=current->next;
    current->next=newNode;
    newNode->info=current->info;
    current->info=newNode->info;
}
int SumaListe(){
    if(front==NULL){
        return 0;
    }
    NODE* p=front;
    int suma=0;
    while(p!=rear){
        suma+=p->info;
        p=p->next;
    }
    return suma;
}
int main(){
    Create(2);
    Create(12);
    Create(33);
    Create(26);
    Create(47);
    //InsertBefore(front,4,999);
    //printf("Suma liste je %d\n", SumaListe(front,rear));
    //Display(front);
    //printf("%d\n",rear->info);
    return 0;
}
