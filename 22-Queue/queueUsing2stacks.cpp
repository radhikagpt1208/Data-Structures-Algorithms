#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> s1, s2;

public:
    void push(int data){
        // Push item into the first stack
        s1.push(data);
    }

    int size(){
        return s1.size();
    }

    bool isEmpty(){
        return size() == 0;
    }

    void pop(){
        //if both stacks are empty
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        // if s2 is empty, move elements from s1 to s2
        if(s2.empty()){
            while(s1.size() > 1){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s1.pop();
        //move all the elements again from s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return NULL;
        }
        if(s2.empty()){
            while(s1.size() > 1){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s1.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
};

int main(){
    Queue q;

    for(int i = 1; i <= 5; i++){
        q.push(i);
    }

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
