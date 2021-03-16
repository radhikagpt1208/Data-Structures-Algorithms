#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int d){
	    data = d;
	    next = NULL;
	}
};

int isEmpty(Node* root) {
	return !root;
}

void push(Node* &root, int data) {
	Node* stackNode = new Node(data);
	stackNode->next = root;
	root = stackNode;
	cout << data << " pushed to stack\n";
}

int pop(Node* &root) {
	if (isEmpty(root))
		return INT_MIN;
	Node* temp = root;
	root = root->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(Node* root) {
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main() {
	Node* root = NULL;
	push(root, 10);
	push(root, 20);
	push(root, 30);
	cout << pop(root) << " popped from stack\n";
	cout << "Top element is " << peek(root) << endl;
	return 0;
}


