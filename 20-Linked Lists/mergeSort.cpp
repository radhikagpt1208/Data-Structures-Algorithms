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

//To divide the list about the mid-point
node* midPoint(node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;   //take 2 steps
        slow = slow -> next;           //take 1 step
    }
    return slow;
}

node* merge(node* a, node* b){
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

node* mergeSort(node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    //rec case
    //1.Divide the list about the mid point
    node* mid = midPoint(head);
    //2.Make 2 link lists
    node* a = head;
    node* b = mid->next;
    //to break the link
    mid->next = NULL;

    //3.Recursively sort the 2 parts
    a = mergeSort(a);
    b = mergeSort(b);

    //3.Merge the 2 sorted parts
    node* c = merge(a, b);
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
    node* head = take_input();
    head = mergeSort(head);
    print(head);
    return 0;
}


