#include<iostream>
using namespace std;

//f:front, r:rear, cs:current size, ms:max size
class Queue{
    int *arr;
    int f, r, cs, ms;

public:
    //Constructor : ask the user for size which is by default set to 5
    Queue(int ds = 5){
        arr = new int[ds];
        cs = 0;
        ms = ds;
        f = 0;
        r = ms-1;
    }

    //To check if the queue is full
    bool full(){
        return cs == ms;
    }

    //To check if the queue is empty
    bool empty(){
        return cs == 0;
    }
    //To insert elements at the rear
    void push(int data){
        //insert only if the queue is not full
        if(!full()){
            r = (r + 1) % ms;
            arr[r] = data;
            cout<<"Pushed "<<data<<endl;
            cs++;
        }
    }

    //To remove elements
    void pop(){
        //you can only pop an element if the queue is not empty
        if(!empty()){
            int r = arr[f];
            f = (f + 1) % ms;
            cout<<"Popped "<<r<<endl;
            cs--;
        }
    }

    int front(){
        return arr[f];
    }

    //Destructor
    ~Queue(){
        if(arr != NULL){
            delete [] arr;
            arr = NULL;
        }
    }
};

int main(){
    Queue q(100);   //pass the size in the constructor
    for(int i = 1 ; i <= 6 ; i++){
        q.push(i);
    }

    q.pop();
    q.pop();

    q.push(7);

    while(!q.empty()){
        cout<<"Element at the front is "<<q.front()<<endl;
        q.pop();
    }

    return 0;
}
