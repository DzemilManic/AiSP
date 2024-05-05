#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}NODE;
NODE* head;
NODE* GetNewNode(int x){
	NODE* NewNode=(NODE*)malloc(sizeof(NODE));
	NewNode->data=x;
	NewNode->next=NULL;
	NewNode->prev=NULL;
	return NewNode;
}
void Display(){
	NODE* p=head;
	while(p!=NULL){
		printf("%d\n", p->data);
		p=p->next;
	}
}
void InsertAtTail(int x){
	NODE* temp=GetNewNode(x);
	NODE* p=head;
	if(head==NULL){
		head=temp;
		return;
	}
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=temp;
	temp->prev=p;
}
void InsertAfter(NODE* p, int x){
	NODE* temp=GetNewNode(x);
	if(head==NULL){
		head=temp;
		return;
	}
	p->next->prev=temp;
	temp->next=p->next;
	p->next=temp;
	temp->prev=p;
}
void InsertAfterPosition(NODE* head, int pos, int x){
	NODE* temp=GetNewNode(x);
	NODE* current=head;
	NODE* preview=head;
	if(head==NULL){
		return 0;
	}
	while(pos!=NULL){
		
			preview=current;
			current=current->next;
			pos--;
	}
		current->next->prev=temp;
		temp->next=current->next;
		current->next=temp;
		temp->prev=current;
}
void InsertBeforePosition(NODE* head, int pos, int x){
	NODE* temp=GetNewNode(x);
	NODE* current=head;
	NODE* preview=head;
	if(head==NULL){
		return;
	}
	while(pos!=1){
		preview=current;
		current=current->next;
		pos--;
	}
	current->prev=temp;
	temp->next=current;
	preview->next=temp;
	temp->prev=preview;
}
void DeleteBefore(NODE* head, int pos){
	NODE* current=head;
	NODE* preview=head;
	if(head==NULL){
		printf("lista je prazna");
	}
	if(pos==1){
		printf("nema prethodnih elemenata");
	}
	while(pos!=1){
		preview=current;
		current=current->next;
		pos--;
	}
	current->prev=preview->prev;
	preview->prev->next=current;
	free(preview);
	preview=NULL;
}
void DeleteAfter(NODE *head, int pos){
	if(head==NULL){
		printf("lista je prazna");
	}
	if(head->next==NULL){
		printf("lista ima samo jedan element");
	}
	NODE* p=head;
	NODE* current=head;
	while(pos!=1){
		current=current->next;
		pos--;
	}
	NODE* temp=current->next;
	current->next=temp->next;
	temp->next->prev=current;
	temp=NULL;
	free(temp);
}
void DeleteByValue(NODE* head, int value){
	if(head==NULL){
		return;
	}
	if(head->next==NULL && head->data==value){
		head=NULL;
		free(head);
	}
	NODE* p=head;
	
	while(p!=NULL){
		if(p->data==value){
			NODE* temp=p;
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			temp=NULL;
			free(temp);
		}
		p=p->next;
	}
}
NODE* Concat(NODE* List1, NODE* List2){
	if(List1==NULL && List2==NULL){
		printf("liste su pazne");
	}
	else if(List1==NULL && List2!=NULL){
		return List2;
	}
	else if(List1!=NULL && List2==NULL){
		return List1;
	}
	else{
		NODE* p=List1;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=List2;
		
	}
	return List1;
}
void Inversion(NODE *head){
	NODE* p=head;
	if(head==NULL){
		printf("lista je prazna");
	}
	if(head->next==NULL){
		printf("lista ima samo jedan element");
	}
	while(p->next!=NULL){
			p=p->next;
		}
	while(p->prev!=NULL){
			printf("%d", p->data);
			p=p->prev;
		}
}

int main(int argc, char *argv[]) {
/*	NODE * List1 = (NODE*)malloc (sizeof(NODE));
    NODE * List12 = (NODE*)malloc (sizeof(NODE));
    NODE * List123 = (NODE*)malloc (sizeof(NODE));

    NODE * List2 = (NODE*)malloc (sizeof(NODE));
    NODE * List22 = (NODE*)malloc (sizeof(NODE));
    NODE * List23 = (NODE*)malloc (sizeof(NODE));
    
    List1->data = 1; List1->next=List12;List1->prev=NULL;
    List12->data = 2; List12->next=List123;List12->prev=List1;
    List123->data = 3; List123->next=NULL;List123->prev=List12;

    List2->data = 4; List2->next=List22;List2->prev=NULL;
    List22->data = 5; List22->next=List23;List22->prev=List2;
    List23->data = 6; List23->next=NULL;List23->prev=List22;
	*/
	int n, i;
//	GetNewNode(1);
	InsertAtTail(3);
	InsertAtTail(5);
	InsertAtTail(7);
	InsertAtTail(9);
	InsertAtTail(0);
	
	NODE * List2 = (NODE*)malloc (sizeof(NODE));
	List2->data = 4; 
	List2->prev=NULL;
	
	NODE * List22 = (NODE*)malloc (sizeof(NODE));
	List22->data = 5; 
	List22->prev=List2;
	List22->next=NULL;
	List2->next=List22;
	//InsertAfter(head, 100);
	//InsertAfterPosition(head, 3, 505);
	//InsertBeforePosition(head, 3, 100);
	//DeleteBefore(head, 3);
	//DeleteAfter(head, 3);
	//DeleteByValue(head, 7);
	//NODE * temp= Concat(List2, head);
	Inversion(head);
	Display(head);
	
	return 0;
}
