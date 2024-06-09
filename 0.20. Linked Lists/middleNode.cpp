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

int length(node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head -> next;
    }
    return cnt;
}

node* mid(node* head){
    node* temp = head;
    int len = length(head);
    for(int i = 0 ; i < len/2 ; i++){
        temp = temp -> next;
    }
    return temp;
}

//USING RUNNER TECHNIQUE
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

int main(){
    node* head = NULL;
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);

    node* midNode = mid(head);
    cout<<midNode -> data<<endl;

    node* middlePoint = midPoint(head);
    cout<<middlePoint -> data;

    return 0;
}
