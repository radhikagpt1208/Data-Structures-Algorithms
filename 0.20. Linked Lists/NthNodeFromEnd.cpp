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

node* NthNodeFromEnd(node*head, int n){
    node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    //check if n is larger than length
    if(n > len){
        return NULL;
    }
    temp = head;
    for(int i = 1 ; i < len-n+1 ; i++){
        temp = temp -> next;
    }
    return temp;
}

//2 POINTER APPROACH
void nthNode(node* head, int n){
    node* ref_ptr = head ;
    node* main_ptr = head;

    int cnt = 0;
    if(head == NULL || head->next == NULL){
        return;
    }
    //else move ref ptr to n nodes from the head
    while(cnt < n){
        if(ref_ptr == NULL){
            cout<<"n is greater than the no. of nodes";
        }
        ref_ptr = ref_ptr->next;
        cnt++;
    }
    //move both the pointers now
    while(ref_ptr != NULL)
    {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
    }
    cout<<main_ptr->data;
}

int main(){
    node* head = take_input();
    int n;
    cin>>n;
    /*node* NthNode = NthNodeFromEnd(head, n);
    cout<<NthNode->data<<endl; */

    nthNode(head, n);
    return 0;
}
