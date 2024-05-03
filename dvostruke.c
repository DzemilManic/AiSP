#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int Data;
    struct Node*Next;
    struct Node*Prev;
}Node;

Node*First=NULL;

int isEmpty(){
    if(First==NULL)return 1;
    return 0;
}

Node*GetNewNode(int elem){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->Next=NULL;
    newNode->Prev=NULL;
    newNode->Data=elem;
    return newNode;
}

void InsertAtTheFront(int elem){
    Node*temp=GetNewNode(elem);
    if(isEmpty()){
        First=temp;
        return;
    }
    temp->Next=First;
    First->Prev=temp;
    First=temp;
}

void InsertAtTheEnd(int elem){
    Node*temp=GetNewNode(elem);
    if(isEmpty()){
        First=temp;
        return;
    }
    Node*t=First;
    while(t->Next!=NULL){
        t=t->Next;
    }
    t->Next=temp;
    temp->Prev=t;
}

void Display(Node*First){
    if(isEmpty()){
        return;
    }
    Node*p=First;
    while(p){
        printf("%d ",p->Data);
        p=p->Next;
    }
}

void ReversePrint(){
    if(isEmpty()){
        return;
    }
    Node*p=First;
    while(p->Next!=NULL){
        p=p->Next;
    }
    while(p!=NULL){
        printf("%d ",p->Data);
        p=p->Prev;
    }
}

void InsertAfter(int position,int elem){
    if(isEmpty()){
        return;
    }
    Node*q=First;
    Node*temp=GetNewNode(elem);
    while(position!=1){
        q=q->Next;
        position--;
    }
    if(q->Next==NULL){
    temp->Next=NULL;
    q->Next=temp;
    temp->Prev=q;
    }
    else{
    temp->Next=q->Next;
    q->Next->Prev=temp;
    q->Next=temp;
    temp->Prev=q;
    }
}

void InsertBefore(int position,int elem){
    if(isEmpty())return;
    Node*temp=GetNewNode(elem);
    Node*q=First;
    if(position==1){
        temp->Next = First;
        First->Prev = temp;
        temp->Prev = NULL;
        First = temp;
        return;//OBAVEZNO!!!!!!!!!!!!!!!!!!!!!!!
    }
    while(position!=1 && q!=NULL){
        q=q->Next;
        position--;
    }
    temp->Next=q;
    q->Prev->Next=temp;
    temp->Prev=q->Prev->Next;
    q->Prev=temp;
    
}

void DeleteAfter(int position){
    if(isEmpty())return;
    if(position==1 && First->Next==NULL){
        return;
    }
    Node*temp,*q=First;
    while(position!=1 && q!=NULL){
        q=q->Next;
        position--;
    }
    if(q->Next==NULL){
        free(temp);
        return;
    }
    temp=q->Next;
    q->Next=temp->Next;
    temp->Next->Prev=q;
    free(temp);
    temp=NULL;
}

void DeleteBefore(int position){
    if(isEmpty())return;
    if(position<=2){
        return;
    }
    Node*temp,*q=First;
    while(position>2){
        q=q->Next;
        position--;
    }
    temp=q->Prev;
    q->Prev=temp->Prev;
    temp->Prev->Next=q;
    free(temp);
    temp=NULL;
}

void DeletePosition(int position) {
    if (isEmpty() || position <= 0) {
        return;
    }

    Node* temp = First;

    if (position == 1) {
        First = First->Next;

        if (First != NULL) {
            First->Prev = NULL;
        }

        free(temp);
        return;
    }

    int currentPosition = 1;

    while (currentPosition < position && temp != NULL) {
        temp = temp->Next;
        currentPosition++;
    }

    if (temp == NULL) {
        return;
    }

    temp->Prev->Next = temp->Next;

    if (temp->Next != NULL) {
        temp->Next->Prev = temp->Prev;
    }

    free(temp);
    temp = NULL;
}


void DeleteValue(int Value) {
    if (isEmpty()) {
        return;
    }

    Node* p = First;

    while (p != NULL) {
        if (p->Data == Value) {
            if (p == First) {
                First = First->Next;
                if (First != NULL) {
                    First->Prev = NULL;
                }
            } else {
                p->Prev->Next = p->Next;
                if (p->Next != NULL) {
                    p->Next->Prev = p->Prev;
                }
            }

            free(p);
            return;
        }

        p = p->Next;
    }
}


void DeleteFirst() {
    if(isEmpty()) {
        return;
    }
    Node* temp = First;
    First = temp->Next;
    if (First != NULL) {
        First->Prev = NULL;
    }
    free(temp);
}


int MaxElementRekurzivno(Node*First){
    if(isEmpty())return 0;
    if(First->Next==NULL)return First->Data;
    int Max=First->Data;
    int prethodniMax=MaxElementRekurzivno(First->Next);
    if(Max<prethodniMax)
    return prethodniMax;
    else
    return Max;
}

void Sortiraj(){
    if(isEmpty())return;
    int pom;
    Node*temp=First->Next;
    while(temp){
        Node*pomocna=First;
        while(pomocna->Next!=NULL){
            if(pomocna->Next->Data<temp->Data){
                pom=pomocna->Data;
                pomocna->Data=temp->Data;
                temp->Data=pom;
            }
            pomocna=pomocna->Next;
        }
        temp=temp->Next;
    }
}

Node* OdvojNeparne(){
    if(isEmpty()){
        return NULL;
    }
    Node*p=First,*Head=NULL,*Last=NULL;
    while(p){
        if(p->Data%2!=0){
        Node*temp=(Node*)malloc(sizeof(Node));
        temp->Data=p->Data;
            if(Head==NULL){
                Head=temp;
                Last=temp;
            }
        Last->Next=temp;
        Last=temp;
        }
        p=p->Next;
    }
    return Head;
}


Node* PresekListi(Node* List1, Node* List2){
    if(List1 == NULL || List2 == NULL) return NULL;
    Node* p = List1;
    Node* q = List2;
    Node* head = NULL;
    Node* last = NULL;
    while(p != NULL){
        q = List2;
        while(q != NULL){
            if(p->Data == q->Data){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->Data = p->Data;
                newNode->Next = NULL;
                newNode->Prev = NULL;
                if(head == NULL){
                    head = newNode;
                    last = newNode;
                } else {
                    last->Next = newNode;
                    newNode->Prev = last;
                    last = newNode;
                }
            }
            q = q->Next;
        }
        p = p->Next;
    }
    return head;
}

bool pretraziListu(Node* lista, int element){
   Node* p = lista;
   while(p != NULL){
       if(p->Data == element){
           return true;
       }
       p = p->Next;
   }
   return false;
}


int SumaUnijeListi(Node* list1, Node* list2){
   int suma = 0;
   Node* p = list1;
   Node* q = list2;
   
   // Dodaj elemente iz prve liste u sumu
   while(p != NULL){
       suma += p->Data;
       p = p->Next;
   }
   
   // Dodaj elemente iz druge liste u sumu, izbegavajuci dupliranje sa prvom listom
   while(q != NULL){
       if(!pretraziListu(list1, q->Data)) {
           suma += q->Data;
       }
       q = q->Next;
   }
   
   return suma;
}


void InvertujDoN(int position){
    if(isEmpty() || position <= 1) return;
    Node* p = First;
    Node* temp = NULL;
    while(p != NULL && position > 1){
        temp = p->Prev;
        p->Prev = p->Next;
        p->Next = temp;
        p = p->Prev;
        position--;
    }
    if(temp != NULL){
        First = temp->Prev;
    }
}


void RemoveDuplicates() {
    if (First == NULL) {
        return;
    }

    Node* curr = First;
    while(curr!=NULL){
        Node*pomocna=curr;
        while(pomocna->Next!=NULL){
            if(pomocna->Next->Data==curr->Data){
                Node*temp=pomocna->Next;
                pomocna->Next=temp->Next;
                temp->Next=pomocna;
                free(temp);
                temp=NULL;
            }
            else
            pomocna=pomocna->Next;
        }
        curr=curr->Next;
    }
}

void DeleteKthNode(Node*pom,int k){
    if(First==NULL)return;
    if(k==1){
        First=NULL;
        free(pom);
    }
    Node*Curr=pom;
    Node*Prev=NULL;
    int count=1;
    while(Curr!=NULL){
        if(count==k){
            Prev->Next=Curr->Next;
            free(Curr);
            Curr=Prev->Next;
            count=1;
        }
        else{
            Prev=Curr;
            Curr=Curr->Next;
            count++;
        }
    }
}


int main(){
    InsertAtTheFront(5);
    InsertAtTheEnd(10);
    InsertAtTheEnd(5);
    InsertAtTheEnd(20);
    InsertAtTheEnd(5);
    
    Node * List1 = (struct Node*)malloc (sizeof(struct Node));
    Node * List12 = (struct Node*)malloc (sizeof(struct Node));
    Node * List123 = (struct Node*)malloc (sizeof(struct Node));

    Node * List2 = (struct Node*)malloc (sizeof(struct Node));
    Node * List22 = (struct Node*)malloc (sizeof(struct Node));
    Node * List23 = (struct Node*)malloc (sizeof(struct Node));
    
    Node * List3 = (struct Node*)malloc (sizeof(struct Node));
    Node * List32 = (struct Node*)malloc (sizeof(struct Node));
    Node * List33 = (struct Node*)malloc (sizeof(struct Node));

    List1->Data = 1; List1->Next=List12;
    List12->Data = 2; List12->Next=List123;
    List123->Data = 3; List123->Next=NULL;

    List2->Data = 1; List2->Next=List22;
    List22->Data = 2; List22->Next=List23;
    List23->Data = 3; List23->Next=NULL;
    
    List3->Data = 9; List2->Next=List22;
    List32->Data = 8; List22->Next=List23;
    List33->Data = 7; List23->Next=NULL;
    //InsertAfter(1,5);
    //InsertBefore(1,30);
    //DeleteAfter(3);
    //DeleteBefore(2); 
    //DeletePosition(5);
    //DeleteValue(10);
    //printf("Maximalan element je %d ",MaxElementRekurzivno(First));
    //Sortiraj();
    //Node*neparni=OdvojNeparne();
    //Node*presecnaLista=PresekListi(List1,List2);
    //Display(presecnaLista);
    //printf("Suma unije lista je %d",SumaUnijeListi(List1,List3));
    //InvertujDoN(3);
    //RemoveDuplicates();
    DeleteKthNode(First,2);
    Display(First);
    return 0;
}
