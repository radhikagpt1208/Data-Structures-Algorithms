#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d){
		data = d;
		next = NULL;
	}
};

void insert(node*& head, int d){
	if(head == NULL){
		head = new node(d);
		return;
	}
	node* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = new node(d);
	return;
}

node* take_input(int size){
	int d;
	node* head = NULL;
	while(size--){
	    cin>>d;
		insert(head,d);
	}
	return head;
}

node* append(node*& head, int k, int n){
	if(head->next == NULL || head == NULL){
    	return head;
  	}
	if(k > n){
		return head;
	}
	node* temp = head;
	node* prev = head;
	node* curr = head;
	for(int i = 1 ; i < n-k+1; i++){
		prev = curr;
		curr = curr->next;
	}
	node* head1 = prev->next;
	prev->next = NULL;       //to break the link

	node* temp1 = curr;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = head;
	head = head1;
	return head;
}

void print(node* head){
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
	int n;
	cin>>n;
	node* head = take_input(n);
	int k;
	cin>>k;
	k = k%n;
	if(k != 0){
        append(head, k, n);
    }
	print(head);
	return 0;
}
