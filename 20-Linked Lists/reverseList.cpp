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

void insert(node*&head , int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n -> next = head;
    head = n;
}

void reverse(node*& head){
    //initialize 3 pointers
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while(current != NULL){
        //store the next node
        next = current -> next;
        //reverse current node
        current -> next = prev;
        //move pointers one position ahead
        prev = current;
        current = next;
    }
    head = prev;
}

//RECURSIVE METHOD
node* recReverse(node*head){
    //base case
    //if you are left with one node or the link list is empty
    if(head -> next == NULL || head == NULL){
        return head;
    }
    //rec case
    //make a call on the smaller part of the linked list
    node* smallHead = recReverse(head -> next);
    //now you have the small head
    node* temp = smallHead;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    head -> next = NULL;
    temp -> next = head;
    return smallHead;
}

//OPTIMIZED RECURSIVE METHOD
node* optRecReverse(node*head){
    //base case
    if(head -> next == NULL || head == NULL){
        return head;
    }
    //rec case
    node* smallHead = recReverse(head -> next);
    //temp is always one node ahead of the head node
    /* node* temp = head -> next;
    temp -> next = head;
    head -> next = NULL; */
    //instead of taking temp node,the above 3 lines can be written as
    head -> next -> next = head;
    head -> next = NULL;
    return smallHead;
}

void print(node* head){
    while(head != NULL){
        cout<<head -> data<<" -> ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);

    cout<<"Given linked list"<<endl;
    print(head);

    reverse(head);
    cout<<"Reversed Linked list"<<endl;
    print(head);

    cout<<"Reversed Linked list using Recursion"<<endl;
    head = recReverse(head);
    print(head);

    cout<<"Reversed Linked list using Optimized Recursion"<<endl;
    head = recReverse(head);
    print(head);

    return 0;
}


//ITERATIVE METHOD IS MORE EFFICIENT THAN THE REC METHOD
//TIME COMMPLEXITY FOR BOTH : O(N)
//SPACE COMPLEXITY FOR ITERATIVE : O(1)
//SPACE COMPLEXITY FOR REC : O(N)stack space
