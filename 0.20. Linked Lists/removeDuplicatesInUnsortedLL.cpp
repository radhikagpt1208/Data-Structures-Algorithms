#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void insert(Node*&head, int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    tail -> next = new Node(d);
    return;
}

Node* take_input(){
    int d;
    cin>>d;
    Node* head = NULL;
    while(d != -1){
        insert(head, d);
        cin>>d;
    }
    return head;
}

Node * removeDuplicates(Node *head) {
    unordered_set<int> m;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!= NULL){
        if(m.find(temp->data) != m.end()){
            prev->next = temp->next;
            delete temp;
        }
        else{
            m.insert(temp->data);
            prev = temp;
        }
        temp = prev->next;
    }

    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head -> data<<" -> ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    Node* head = take_input();
    print(head);
    Node* newHead = removeDuplicates(head);
    print(newHead);

    return 0;
}
