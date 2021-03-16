#include<iostream>
#include<vector>
using namespace std;

class Stack{
private:
    vector<int> v;
public:
    void push(int data){
        v.push_back(data);
        cout<<data<<" pushed into stack"<<endl;
    }

    bool empty(){
        return v.size() == 0;
    }

    void pop(){
        if(!empty()){
            v.pop_back();
        }
    }

    int top(){
        return v[v.size()-1];
    }
};

int main(){
    Stack s;
    for(int i=1; i<5; i++){
        s.push(i);
    }
    //print the content by popping each element
    while(!s.empty()){
        cout<<s.top()<<" popped from stack"<<endl;
        s.pop();
    }

    return 0;
}
