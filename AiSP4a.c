#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
		return ;
	}
	while(pos!=1){
		
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

void SortirajListu(NODE* head){
    if(head==NULL){
        return;
    }
    NODE *i,*j;
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data<j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

NODE* ParniElementi(NODE* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        if(head->data%2==0){
            return head;
        }
    }
    NODE* p=head;
    NODE* newHead=NULL;
    NODE* newTail=NULL;
    NODE* parni=NULL;
    NODE* pom;
    while(p!=NULL){
        if(p->data%2==0){
            parni=(NODE*)malloc (sizeof(NODE));
            parni->data=p->data;
            if(newHead==NULL){
                parni->next=NULL;
                parni->prev=NULL;
                newHead=parni;
                newTail=parni;
                pom=parni;
            }
            else{
            newTail->next=parni;
            parni->prev=newTail;
            newTail=parni;
            }
        }
        p=p->next;
    }
    return pom;
}

bool Search(NODE* head,int x){
    if(head->next==NULL || head==NULL){
        return false;
    }
    else if(head->data==x) {
        return true;
    }
    else if(head->data!=x){
        return Search(head->next,x);
    }
}

int main(){
		int n, i;
//	GetNewNode(1);
	InsertAtTail(3);
	InsertAtTail(8);
	InsertAtTail(2);
	InsertAtTail(9);
	InsertAtTail(0);
	
	/*NODE * List2 = (NODE*)malloc (sizeof(NODE));
	List2->data = 4; 
	List2->prev=NULL;
	
	NODE * List22 = (NODE*)malloc (sizeof(NODE));
	List22->data = 5; 
	List22->prev=List2;
	List22->next=NULL;
	List2->next=List22;
	*/
	//InsertAfter(head, 100);
	//InsertAfterPosition(head, 3, 505);
	//InsertBeforePosition(head, 3, 100);
	//DeleteBefore(head, 3);
	//DeleteAfter(head, 3);
	//DeleteByValue(head, 7);
	//NODE * temp= Concat(List2, head);
	//Inversion(head);
	//SortirajListu(head);
	//ParniElementi(head);
	//Search(head, 3);
	Display(head);
	
	return 0;
}
