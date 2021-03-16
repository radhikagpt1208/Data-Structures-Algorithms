#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void insertAtStart(struct Node* &head, int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = head;
	new_node->prev = NULL;

	if (head != NULL){
		head->prev = new_node;
	}
	head = new_node;
	printf("%d Inserted at the start\n", data);
	return;
}

void insertAtEnd(struct Node* &head, int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tail = head;

	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL) {
		new_node->prev = NULL;
		head = new_node;
		printf("%d Inserted at the end\n", data);
		return;
	}
	while (tail->next != NULL){
		tail = tail->next;
    }
	tail->next = new_node;
	new_node->prev = tail;
	printf("%d Inserted at the end\n", data);

	return;
}

void insertAtPos(struct Node* head, int data, int pos){
    if(head == NULL){
        printf("Error, List is empty!\n");
    }
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node* temp = head;
    int i;
    while(i < pos-1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    if(temp != NULL){
        new_node->data = data;
        new_node->next = temp->next;
        new_node->prev = temp;
        if(temp->next != NULL){
            temp->next->prev = new_node;
        }
        temp->next = new_node;
        printf("%d Inserted at index %d \n", data, pos);
    }
    else{
        printf("Error, Invalid position\n");
    }
}

void deleteAtStart(struct Node* &head){
    if(head == NULL){
        return;
    }
    else if(head->next == NULL) {
        head = NULL;
        printf("%d Deleted\n", head->data);
        free(head);
    }
    struct Node * temp = head;
    head = head -> next;
    head -> prev == NULL;
    printf("%d Deleted\n", temp->data);
    free(temp);
}

void deleteAtEnd(struct Node* head) {
    struct Node *tail;
    if(head == NULL){
        return;
    }
    else if(head->next == NULL){
        printf("%d Deleted\n", head->data);
        head = NULL;
        free(head);
        return;
    }
    else {
        tail = head;
        while(tail->next != NULL){
            tail = tail -> next;
        }
        tail->prev->next = NULL;
        printf("%d Deleted\n", tail->data);
        free(tail);
        return;
    }
}

void printList(struct Node* node){
	while (node->next != NULL) {
		printf(" %d -> ", node->data);
		node = node->next;
	}
	printf("%d -> NULL", node->data);
	printf("\n");
	return;
}

int main(){
	struct Node* head = NULL;
	insertAtStart(head, 2);
	insertAtStart(head, 1);
	insertAtStart(head, 0);

	insertAtEnd(head, 3);
	insertAtEnd(head, 5);

	insertAtPos(head, 4, 4);

	printf("Doubly Linked List is: ");
	printList(head);

	deleteAtStart(head);
	deleteAtEnd(head);

	printf("Doubly Linked List after deletion is: ");
	printList(head);

	return 0;
}

