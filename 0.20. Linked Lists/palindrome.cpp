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

node* midNode(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;   //take 2 steps
        slow = slow->next;         //take 1 step
    }
    return slow;
}

node* reverse(node*& temp){
    node* prev = NULL;
    node* current = temp;
    node* next = NULL;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    temp = prev;
	return temp;
}

bool palindrome(node* head){
	node* mid = midNode(head);
	node* temp = mid->next;
	mid->next = NULL;   //to end the first half of the list
	node* newHead = reverse(temp);
	node* temp1 = head;
	node* temp2 = newHead;
	while(temp2 != NULL){
		if(temp1->data == temp2->data){
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else{
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin>>n;
	node* head = take_input(n);
	if(palindrome(head)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}
