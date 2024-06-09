#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

//length of the list
int length(node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head -> next;
    }
    return cnt;
}

//recursive program to count the no of nodes
int getCount(node* head) {
    // Base case
    if (head == NULL)
        return 0;

    // count is 1 + count of remaining list
    return 1 + getCount(head -> next);
}

//--------INSERTION---------

//1.INSERT AT HEAD
void insertAtHead(node*&head,int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    //for the next time when head is not null
    node* n = new node(d);
    n -> next = head;
    //update the head
    head = n;
}

//2.INSERT AT TAIL
void insertAtTail(node*&head, int d){
    //if the list is null and someone calls this function,insertion will occur at the head
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* tail = head;
    //since we are not maintaining a tail pointer explicitly,we have to find the tail
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    tail -> next = new node(d);
    return;
}

//3.INSERT AT A POSITION
void insertAtPos(node*&head, int d, int pos){
    //corner case
    if(pos == 0 || head == NULL){
        insertAtHead(head, d);
    }
    //insertion at the end
    else if(pos > length(head)){
        insertAtTail(head, d);
    }
    else{
        //reach the node where you have to insert,i.e,(pos-1) place
        node* temp = head;
        int jumps = 1;
        while(jumps <= pos-1){
            temp = temp -> next;
            jumps++;
        }
        node* n = new node(d);
        n -> next = temp -> next;
        temp -> next = n;
    }
}

//--------DELETION---------

//1.DELETE HEAD
void deleteHead(node*&head){
    if(head == NULL){
        return;
    }
    //store the address of the next node before deleting
    node* temp = head -> next;
    delete head;
    head = temp;
}

//2.DELETE TAIL
void deleteTail(node*&head){
    if(head == NULL){
        deleteHead(head);
    }
    node* tail = head;
    node* prev;
    while(tail -> next != NULL){
        prev = tail;
        tail = tail -> next;
    }
    delete tail;
    //make the previous element point to null
    prev -> next = NULL;
}

//DELETE IN MIDDLE
void deleteAtPos(node*&head, int pos){
    //corner case
    if(head == NULL || pos > length(head)){
        return;
    }
    if(pos == 0){
        deleteHead(head);
    }
    else{
        node* temp = head;
        node* prev = NULL;
        int jumps = 0;
        while(jumps < pos){
            prev = temp;
            temp = temp -> next;
            jumps++;
        }
        prev -> next = temp -> next;
        delete temp;
    }
}

//--------SEARCHING---------
//Linear Search
bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == key){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

//Recursive Search
bool recursiveSearch(node* head, int key){
    //base case
    //if you have reached the end,and not found the key,return false
    if(head == NULL){
        return false;
    }
    if(head -> data == key){
        return true;
    }
    else{
        return recursiveSearch(head -> next, key);
    }
}

//Insertion
//keep creating head nodes,and return it to the main
node* take_input(){
    int d;
    cin>>d;
    node* head = NULL;
    while(d != -1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

void print(node* head){
    while(head != NULL){
        cout<<head -> data<<" -> ";
        head = head -> next;
    }
    cout<<endl;
}

//OPERATOR OVERLOADING
//overloading left shift operator for printing the list
//head is passed by value,because while printing we don't modify the head
ostream& operator<<(ostream &os, node* head){
    print(head);
    return os;   //cout object
}

//overloading right shift operator for taking input
//head is passed with reference because while taking input we modify the head
istream& operator>>(istream &is, node*&head){
    head = take_input();
    return is;
}

int main(){
    /*node* head1 = take_input();
    node* head2 = take_input(); */
    node* head1;
    node* head2;
    cin>>head1>>head2;   //take input of 2 linked lists
    cout<<head1<<head2;  //prints entire linked list

    /*node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    print(head);

    insertAtPos(head, 3, 3);
    print(head);

    insertAtTail(head, 5);
    print(head);

    deleteHead(head);
    print(head);

    deleteTail(head);
    print(head);

    deleteAtPos(head, 2);
    print(head);

    int key;
    cin>>key;
    if(recursiveSearch(head, key)){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    } */

    return 0;
}

