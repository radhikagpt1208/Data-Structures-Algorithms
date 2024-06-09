#include<iostream>
using namespace std;

class node{
public:
	int coeff;
	int pow;
	node* next;

	node(int x, int y){
	    coeff = x;
	    pow = y;
	    next = NULL;
	}
};

void create_node(int x, int y, node* &head){
	if (head == NULL){
	    head = new node(x, y);
	    return;
	}
	node* n = new node(x, y);
	node* tail = head;
	while(tail->next != NULL){
	    tail = tail->next;
	}
	tail->next = n;
	return;
}

void polyadd(node* head1, node* head2, node* &poly){
    poly = new node(0,0);
    node* curr = poly;
    node* temp;
	while (head1->next != NULL && head2->next != NULL) {
	    // If power of 1st polynomial is greater than 2nd,then store 1st as it is and move its pointer
		if (head1->pow > head2->pow) {
			temp = new node(head1->coeff, head1->pow);
			curr->next = temp;
			curr=curr->next;
			head1 = head1->next;
		}
		// If power of 2nd polynomial is greater than 1st,then store 2nd as it is and move its pointer
		else if (head1->pow < head2->pow) {
			temp = new node(head2->coeff, head2->pow);
			curr->next = temp;
			curr = curr->next;
			head2 = head2->next;
		}

		// If power of both polynomial numbers is same then add their coefficients
		else {
			temp = new node(head1->coeff+head2->coeff, head1->pow);
			curr->next = temp;
			curr=curr->next;
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	while (head1->next || head2->next) {
		if (head1->next) {
			temp = new node(head1->coeff, head1->pow);
			curr->next = temp;
			curr=curr->next;
			head1 = head1->next;
		}
		if (head2->next) {
			temp = new node(head2->coeff, head2->pow);
			curr->next = temp;
			curr=curr->next;
			head2 = head2->next;
		}
	}
	poly = poly->next;
}

void show(node* head){
    node* temp = head;
	while (temp != NULL) {
		cout<<temp->coeff<<"x^"<<temp->pow;
		temp = temp->next;
		if (temp != NULL){
			cout<<" + ";
		}
	}
	cout<<endl;
}

int main(){
	node *head1 = NULL;
	node *head2 = NULL;
	node *poly = NULL;

	// Create first list of 5x^2 + 4x^1 + 2x^0
	create_node(5, 2, head1);
	create_node(4, 1, head1);
	create_node(2, 0, head1);

	// Create second list of -5x^1 - 5x^0
	create_node(-5, 1, head2);
	create_node(-5, 0, head2);

	cout<<"1st Number: ";
	show(head1);

	cout<<"2nd Number: ";
	show(head2);

	polyadd(head1, head2, poly);

	cout<<"Added polynomial: ";
	show(poly);

	return 0;
}

