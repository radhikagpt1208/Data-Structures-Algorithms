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

void insert(node*&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    tail -> next = new node(d);
    return;
}

node* take_input(){
    int d;
    cin>>d;
    node* head = NULL;
    while(d != -1){
        insert(head, d);
        cin>>d;
    }
    return head;
}

node* merge(node* a, node* b){
    //base case:if one of the link list is null,then output is the other link list
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node* c;

    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

void print(node* head){
    while(head != NULL){
        cout<<head -> data<<" -> ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    node* list1 = take_input();
    node* list2 = take_input();

    node* newHead = merge(list1, list2);
    print(newHead);

    return 0;
}

