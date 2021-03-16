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

void removeLoop(node* head, node* slow_ptr, node* fast_ptr){
    //let the fast_ptr be at one of the loop nodes found in the above function and take slow_ptr to the head of the link list
    slow_ptr = head;
    //Move both pointers at the same pace,they will meet at LOOP STARTING NODE
    while(slow_ptr != fast_ptr){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    //now both the pointers are at the starting node of the loop
    //to find the last node of the loop:
    while(fast_ptr->next != slow_ptr){
        fast_ptr = fast_ptr->next;
    }
    //Set the next node of the loop ending node to null to break the loop
    fast_ptr->next = NULL;
}

bool detectCycleAndRemove(node* head){
    node* slow_ptr = head;
    node* fast_ptr = head;
    while(fast_ptr != NULL && fast_ptr->next != NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
        //If slow_p and fast_p meet at some point then there is a loop
        if(fast_ptr == slow_ptr){
            removeLoop(head, slow_ptr, fast_ptr);
            //return true to indicate that loop is found
            return true;
        }
    }
    //return false to indicate that there is no loop
    return false;
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
    //Create a loop for testing
    //head->next->next->next->next->next = head->next->next;
    if(detectCycleAndRemove(head)){
        cout<<"Cycle is present"<<endl;
        cout<<"On breaking the cycle,the linked list is:"<<endl;
        print(head);
    }
    else{
        cout<<"No cycle is present"<<endl;
    }
    return 0;
}
