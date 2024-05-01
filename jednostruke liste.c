#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int Data;
    struct Node*Next;
}Node;

Node*First=NULL,*Last=NULL;

int isEmpty(){
    if (First==NULL) return 1;
    return 0;
}

void Create(int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->Data=elem;temp->Next=NULL;
    if(First==NULL){
        First=temp;Last=temp;
    }
    Last->Next=temp;Last=temp;
}

void InsertAtTheFront(Node**First,int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->Data=elem;
    if(First==NULL){
        temp=*First;
    }
    temp->Next=*First;
    *First=temp;
}

void InsertAtTheEnd(Node**First,int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->Data=elem;
    if(First==NULL){
        *First=temp;
    }
    Node*last=*First;
    while(last->Next!=NULL){
    last=last->Next;   
    }
    last->Next=temp;
}

void InsertAfter(Node*pom,int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->Data=elem;
    if(pom==First && First==NULL){
        First=pom;
        Last=pom;
    }
    temp->Next=pom->Next;
    pom->Next=temp;
    if(pom==Last)Last=temp;
}

void InsertAfterPosition(int position,int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->Data=elem;
    Node*q=First;
    if(position !=1 && First==NULL){
        return;
    }
    while(position!=1){
        q=q->Next;
        position--;
    }
    temp->Next=q->Next;
    q->Next=temp;
}

void InsertBefore(Node*pom,int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    if(pom==First && First==NULL){
        First=pom;
        Last=pom;
    }
    temp->Data=pom->Data;
    pom->Data=elem;
    temp->Next=pom->Next;
    pom->Next=temp;
    if(pom==Last)temp=Last;
}

void InsertBeforePosition(int position,int elem){
    Node*temp=(Node*)malloc(sizeof(Node));
    Node*q=First;
    if(position!=1 && First==NULL){
        return;
    }
    while(position!=1){
        q=q->Next;
        position--;
    }
    temp->Data=q->Data;
    q->Data=elem;
    temp->Next=q->Next;
    q->Next=temp;
}

void DeleteAfter(Node*pom){
    if(isEmpty())
    return;
    Node*temp=pom->Next;
    pom->Next=temp->Next;
    free(temp);
    temp=NULL;
}

void DeleteAfterPostion(int position){
    if(isEmpty())
    return;
    Node*q=First,*temp;
    while(position!=1){
        q=q->Next;
        position--;
    }
    temp=q->Next;
    q->Next=temp->Next;
    free(temp);
    temp=NULL;
}

void DeleteActual(Node*pom){
    if(pom==NULL)return;
    if(pom==First && First==Last)
    First=NULL;Last=NULL;free(pom);
    Node*temp=pom->Next;
    pom->Next=temp->Next;
    pom->Data=temp->Data;
    free(temp);
}

void DeleteByPosition(int position){
    if(First==NULL)
    return;
    Node*q=First,*p=NULL;
    while(q->Next!=NULL){
        p=q;
        q=q->Next;
        position--;
    }
    Node*temp=p;
    temp->Next=q->Next;
    q->Next=NULL;
    free(q);
}

void DeleteByValue(int Value){
    if(First==NULL)
    return;
    Node*temp,*q,*p=First;
    bool semafor=true;
    while(p->Next!=NULL){
        if(Value==p->Data)
        break;
        q=p;
        p=p->Next;
        semafor=false;
    }
    if(semafor==false)
    return;
    if(p==First){
        First=p->Next;
        free(p);p=NULL;
    }
    else if(p==Last){
        q->Next=NULL;
        free(p);p=NULL;
    }
    else{
        q->Next=p->Next;
        free(p);p=NULL;
    }
}

void Display(Node*Head){
    Node*temp=Head;
    while(temp){
        printf("%d ",temp->Data);
        temp=temp->Next;
    }
}

void Invertuj(){
    Node*q=First,*p=NULL,*n=NULL;
    if(First==NULL)
    return;
    while(q){
        n=q->Next;
        q->Next=p;
        p=q;
        q=n;
    }
    First=p;
}
Node* Concat(Node*List1,Node*List2){
    if(List1==NULL)
    return List2;
    if(List2==NULL)
    return List1;
    if(List1==NULL && List2==NULL)
    return NULL;
    Node*temp=List1;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=List2;
    return List1;
}
int Nadjen1(int elem){
    bool semafor=true;
    if(First==NULL)
    return 0;
    Node*p=First;
    while(p->Next!=NULL){
        if(p->Data==elem){
         semafor=true;
         return 1;   
        }
        p=p->Next;
        semafor=false;
    }
    if(semafor==false)
    return 0;
}

Node*Nadjen2(int elem){
    bool semafor=true;
    if(First==NULL)
    return NULL;
    Node*p=First;
    while(p->Next!=NULL){
        if(p->Data==elem){
          semafor=true;
          return p;  
        }
        p=p->Next;
    }
    if(semafor==false)
    return NULL;
}

Node*PresekListi(){
    
}

void Zameni(int elem1,int elem2){
    if(First==NULL)
    return;
    Node*p=First;
    while(p->Next!=NULL){
        if(p->Data==elem1)
        p->Data=elem2;
        p=p->Next;
    }
}

void DeleteFirst(Node**First){
    if(isEmpty())
    return;
    Node*temp=*First;
    *First=temp->Next;
    free(temp);
    temp=NULL;
}

bool Jednakost(Node*List1,Node*List2){
    if(List1==NULL)return false;
    if(List2==NULL)return false;
    if(List1==NULL&& List2==NULL)return true;
    Node*p=List1,*q=List2;
    while(p!=NULL && q!=NULL){
        if(p->Data!=q->Data)
        return false;
        p=p->Next;q=q->Next;
    }
    return true;
}

int Suma(){
    int suma=0;
    if(First==NULL)
    return 0;
    if(First==Last)
    return First->Data;
    Node*p=First;
    while(p){
        suma+=p->Data;
        p=p->Next;
    }
    return suma;
}

int MaxElement(){
    if(First==NULL)
    return 0;
    if(First==Last)
    return First->Data;
    Node*temp=First;
    int Max=First->Data;
    while(temp){
        if(Max<temp->Data)
        Max=temp->Data;
        temp=temp->Next;
    }
    return Max;
}

bool nadjiRekurzivno(Node*First,int elem){
    if(First==NULL)
    return false;
    if(First->Data==elem)
    return true;
    else
    return nadjiRekurzivno(First->Next,elem);
}

void ZameniRekurzivno(Node* First,int elem1,int elem2){
    if(First==NULL)
    return;
    if(First->Data==elem1)
    First->Data==elem2;
    else
    return ZameniRekurzivno(First->Next,elem1,elem2);
}

void ElementPisi(Node* First){
    if(First==NULL)return;
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

void ubaci2(Node*First){
    if(First==NULL)return;
    Node*p=First;
    while(p){
        Node*temp=(Node*)malloc(sizeof(Node));
        temp->Data=2;
        temp->Next=p->Next;
        p->Next=temp;
        p=temp->Next;
    }
}

void SrednjiElement(){
    if(First==NULL)return;
    Node*p=First,*t=First;
    int br=0,Srednji;
    while(p){
        br++;
        p=p->Next;
    }
    free(p);p=NULL;
    Srednji=br/2;
    while(Srednji!=1){
        t=t->Next;
        Srednji--;
    }
    printf("%d ",t->Next->Data);
}
int Prebroj(int elem){
    int br=0;
    if(First==NULL)return 0;
    if(First==Last && First->Data==elem)return 1;
    Node*p=First;
    while(p){
        if(p->Data==elem)
        br++;
        p=p->Next;
    }
    return br;
}

void Sortiraj(){
    if(First==NULL)return;
    int pom;
    Node*p=First->Next;
    while(p!=NULL){
        Node*t=First;
        while(t->Next!=NULL){
            if(t->Data<p->Data){
            pom=t->Data;
            t->Data=p->Data;
            p->Data=pom;
            }
            t=t->Next;
        }
        p=p->Next;
    }
}
void addEndAtTheFront(){
    int elem;
    if(First==NULL)return;
    if(First==Last)return;
    Node*p=First,*q=First,*prev=NULL;
    while(p->Next!=NULL){
        prev=p;
        p=p->Next;
    }
    elem=p->Data;
    prev->Next=NULL;
    free(p);
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->Data=q->Data;
    q->Data=elem;
    temp->Next=q->Next;
    q->Next=temp;
}
Node* OdvojParne(Node* First) {
    if (First == NULL) {
        return NULL;
    }
    Node* Head = NULL;
    Node* Rear = NULL;
    Node* p = First;
    while (p != NULL) {
        if (p->Data % 2 == 0) {
            Node* parni = (Node*)malloc(sizeof(Node));
            parni->Data = p->Data;
            parni->Next = NULL;
            if (Head == NULL) {
                Head = parni;
                Rear = parni;
            }
            else {
                Rear->Next = parni;
                Rear = parni;
            }
        }
        p = p->Next;
    }
    return Head;
}

void DeleteKthNode(Node*pom,int k){
    if(First==NULL)return;
    if(k==1){
        First=NULL;Last=NULL;
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
                free(temp);
            }
            else
            pomocna=pomocna->Next;
        }
        curr=curr->Next;
    }
}
int main(){
    Create(5);
    Create(10);
    Create(15);
    Create(20);
    Create(25);
    //InsertAtTheFront(&First,14);
    //InsertAtTheEnd(&First,44);
    //InsertAfter(First,2);
    //InsertAfterPosition(5,55);
    //InsertBefore(First,14);
    //InsertBeforePosition(1,777);
    //DeleteAfter(First);
    //DeleteAfterPostion(4);
    //DeleteByValue(29);
    //Invertuj();
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
    /*
    Node*novaLista=Concat(List1,List2);
    if(Nadjen1(5))
    printf("\nIma.");
    else printf("\nNema.");
    if(Nadjen2(5)!=NULL){
    Node*noviElement=Nadjen2(5);
    printf("\nelement je %d",noviElement->Data);
    }
    else
    printf("\nElementa nema.");
    */
    //Zameni(5,8);
    //DeleteFirst(&First);
    //Display(First);
    /*
    if(Jednakost(List1,List2))
    printf("jesu.");
    else
    printf("nisu.");
    */
    //printf("Suma elemenata je %d",Suma());
    //printf("Maximalan %d",MaxElement());
    /*if(nadjiRekurzivno(First,5))
    printf("Ima.");
    else
    printf("Nema.");*/
    //ZameniRekurzivno(First,5,787);
    //ElementPisi(First);
    //ubaci2(First);
    //SrednjiElement();
    //printf("pojavljuje se %d ",Prebroj(5));
    //Sortiraj();
    //addEndAtTheFront();
    //Node*Parniii=OdvojParne(First);
    //DeleteKthNode(First,2);
    //RemoveDuplicates();
    Display(First);
    return 0;
}
