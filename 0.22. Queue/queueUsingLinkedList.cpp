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

class Queue{
public:
    node *rear, *front;
    Queue(){
        rear = front = NULL;
    }

    //push data in the queue
    void insertAtTail(int data){
        node* temp = new node(data);
        cout<<"Pushed "<<data<<endl;
        //if queue is empty,then both front and rear = new node
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        //add the new node at the end of the queue(tail) and change the rear
        rear->next = temp;
        rear = temp;
    }

    void removeFromHead(){
        //if queue is empty
        if(front == NULL){
            return;
        }
        // Store previous front and move front one node ahead
        node *temp = front;
        cout<<"Popped "<<temp->data<<endl;
        front = front->next;

        //If front becomes NULL, then change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};

int main(){
    Queue q;
    q.insertAtTail(10);
    q.insertAtTail(20);
    q.removeFromHead();
    q.removeFromHead();
    q.insertAtTail(30);
    q.insertAtTail(40);
    q.insertAtTail(50);
    q.removeFromHead();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
    return 0;
}
