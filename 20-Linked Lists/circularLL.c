#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node* insertAtStart(struct node* head){
    struct node* new_node, *temp;
    int data;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d",&data);
    new_node->data = data;
    if(head == NULL){
        head = new_node;
        new_node->next = head;
        printf("%d INSERTED\n", data);
        return head;
    }
    else{
        temp = head;
        while(temp->next != head)
            temp = temp->next;
        new_node->next = head;
        temp -> next = new_node;
        head = new_node;
        printf("%d INSERTED\n", data);
        return head;
    }
}

struct node* insertAtLast(struct node* head){
    struct node *new_node,*temp;
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d", &data);
    new_node->data = data;
    if(head == NULL)  {
        head = new_node;
        new_node->next = head;
        printf("%d INSERTED\n", data);
        return head;
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp -> next;
        }
        temp -> next = new_node;
        new_node-> next = head;
        printf("%d INSERTED\n", data);
        return head;
    }
}

struct node* insertAtPos(struct node* head, int pos){
    if(pos == 0){
        return insertAtStart(head);
    }
    if(head == NULL){
        return head;
    }
    else{
        struct node* new_node = (struct node *)malloc(sizeof(struct node));
        int data;
        printf("Enter the node data: ");
        scanf("%d", &data);
        new_node->data = data;
        struct node* temp = head;
        for(int i = 0; i < pos-1; i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        printf(" %d INSERTED\n", data);
        return head;
    }
}

struct node* deleteAtStart(struct node* head){
    struct node *previous = head, *next = head;
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if(previous->next == previous) {
        printf("%d DELETED\n", head->data);
        head = NULL;
        return head;
    }
    while(previous->next != head) {
        previous = previous->next;
        next = previous->next;
    }
    previous->next = next->next;
    head = previous->next;
    printf("%d DELETED \n", next->data);
    free(next);
    return head;
}

struct node* deleteAtEnd(struct node* head){
    struct node *current = head, *previous;
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (current->next == current) {
        printf("%d DELETED \n", current->data);
        head = NULL;
        return head;
    }
    while(current->next != head) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    head = previous->next;
    printf("%d DELETED \n", current->data);
    free(current);

    return head;
}

struct node* deleteAtPos(struct node* head, int pos){
	int count = 1;
	struct node *prev = head, *next = head->next;

	if (head == NULL || pos < 0) {
		printf("List is empty \n");
		return head;
	}
	if (pos == 0) {
		return deleteAtStart(head);
	}
	while(pos != count){
	    prev = prev->next;
    	next = next->next;
    	count++;
	}
	prev->next = next->next;
    free(next);
    return head;
}

void display(struct node* head){
    struct node *temp = head;
    if(head == NULL){
        return;
    }
    else{
        while(temp->next != head){
            printf("%d ->", temp->data);
            temp = temp-> next;
        }
        printf("%d -> NULL \n", temp->data);
    }
}

int main (){
    struct node *head = NULL;
    int choice = 0;
    while(choice != 8){
        printf("Choose one option from the following\n");
        printf("1.Insert in beginning  2.Insert at last  3.Insert at a Position\n");
        printf("4.Delete from Beginning  5.Delete from last  6.Delete at a Position\n");
        printf("7.Show  8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        int pos;
        switch(choice){
            case 1: head = insertAtStart(head);
                    break;
            case 2: head = insertAtLast(head);
                    break;
            case 3: printf("Enter the position: ");
                    scanf("%d", &pos);
                    head = insertAtPos(head, pos);
                    break;
            case 4: head = deleteAtStart(head);
                    break;
            case 5: head = deleteAtEnd(head);
                    break;
            case 6: printf("Enter the position: ");
                    scanf("%d", &pos);
                    head = deleteAtPos(head, pos);
                    break;
            case 7: display(head);
                    break;
            case 8: exit(0);
                    break;
            default:printf("Please enter a valid choice");
        }
    }
}

