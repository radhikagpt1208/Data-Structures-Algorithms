/* APPROACH
1.By making pop operation costly:
    In push operation, the new element is always enqueued to q1.
    In pop() operation, if q2 is empty then all the elements except the last, are moved to q2.
    Finally the last element is dequeued from q1 and returned.
    A)push(s, x) operation:
        Enqueue x to q1 (assuming size of q1 is unlimited).
    B)pop(s) operation:
        One by one dequeue everything except the last element from q1 and enqueue to q2.
        Dequeue the last item of q1, the dequeued item is result, store it.
        Swap the names of q1 and q2
        Return the item stored in step 2.


2. By making push operation costly:
    This method makes sure that newly entered element is always at the front of q1,
    so that pop operation just dequeues from q1. q2 is used to put every new element at front of q1.

    A)push(s, x) operation:
        Enqueue x to q2
        One by one dequeue everything from q1 and enqueue to q2.
        Swap the names of q1 and q2
    B)pop(s) operation:
        Dequeue an item from q1 and return it.  */

//IMPLEMENTATION OF 1ST MENTHOD

#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class Stack{
    queue<T> q1, q2;

public:
    void push(T x){
        q1.push(x);
    }

    void pop(){
        //move n-1 elements from q1 to q2
        if(q1.empty()){
            return;
        }
        while(q1.size() > 1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        //now you are left with the last element in q1 which is the required element to be popped
        q1.pop();

        //swap the names of q1 and q2
        swap(q1, q2);
    }

    T top(){
        while(q1.size() > 1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        T element = q1.front();
        q1.pop();
        q2.push(element);

        swap(q1,q2);
        return element;
    }

    int size(){
        return q1.size() + q2.size();
    }

    bool empty(){
        return size() == 0;
    }
};

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
