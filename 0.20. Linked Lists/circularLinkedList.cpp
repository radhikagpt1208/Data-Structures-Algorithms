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

void insert(node*& head, int data){
    node* n = new node(data);
    node* temp = head;
    n->next = head;
    //if there already exists a node
    if(head != NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        //link the last node with the new node inserted at the head
        temp->next = n;
    }
    //to insert first node
    else{
        //self loop
        n->next = n;
    }
    //update the head
    head = n;
}

//SEARCH
node* getNode(node* head, int data){
    node* temp = head;
    //for all nodes except last node
    while(temp->next != head){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    //for the last node as the while condition becomes false and it does not search for the last node
    if(temp->data == data){
        return temp;
    }
    return NULL;
}

void deleteNode(node*& head, int data){
    //to get the node to be deleted
    node* del = getNode(head, data);
    if(del == NULL){
        //node does not exist
        return;
    }
    //if head is to be deleted
    if(head == del){
        head = head->next;
    }
    node* temp = head;
    //we will go till one node behind the one to be deleted
    while(temp->next != del){
        temp = temp->next;
    }
    //link with the correct node
    temp->next = del->next;
    //finally delete the node
    delete del;
}

void print(node* head){
    node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    //print the last node explicitly
    cout<<temp->data<<endl;
    return;
}

int main(){
    node* head = NULL;
    insert(head, 5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    print(head);
    deleteNode(head, 3);
    print(head);
    deleteNode(head, 1);
    print(head);

    return 0;
}
