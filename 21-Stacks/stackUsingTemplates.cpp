#include<iostream>
#include<vector>
using namespace std;

//T:variable that will tell you the data-type when a stack object is created
template<typename T,typename U>
class Stack{
private:
    vector<T> v;
    vector<U> u;
public:
    void push(T data){
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

    T top(){
        return v[v.size()-1];
    }
};

int main(){
    //whenever you create an object,you will have to tell your data-type
    Stack<char,int> s;
    for(int i=65; i<70; i++){
        s.push(i);
    }
    cout<<endl;
    //print the content by popping each element
    while(!s.empty()){
        cout<<s.top()<<" popped from stack"<<endl;
        s.pop();
    }

    return 0;
}

