#include<iostream>
#include<stack>
using namespace std;

class myStack{
public:
    stack<int>s;
    int min_ele;

    void push(int x){
        if(s.empty()){
            s.push(x);
            min_ele = x;
            cout<<"Pushed "<<x<<endl;
        }
        else if(!s.empty()){
            if(x >= min_ele){
                s.push(x);
                cout<<"Pushed "<<x<<endl;
            }
            else if(x < min_ele){
                s.push(2*x-min_ele);
                cout<<"Pushed: "<<x<<endl;
                min_ele = x;
            }
        }
    }

    void pop(){
        if(s.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        int y = s.top();
        s.pop();

        if(y >= min_ele){
            cout<<"Popped: "<<y<<endl;
        }
        else if(y < min_ele){
            cout<<"Popped: "<<min_ele<<endl;
            min_ele = 2*min_ele - y;
        }
    }

     void getMin(){
        if (s.empty()){
            cout << "Stack is empty"<<endl;
        }
        else{
            cout<<"Minimum Element: "<<min_ele<<endl;
        }
     }

    void peek(){
        if (s.empty()){
            cout << "Stack is empty ";
            return;
        }
        int z = s.top();    // Top element.
        cout<<"Top Most Element is: ";
        // If z<min_ele means min_ele stores value of t.
        (z < min_ele) ? cout<<min_ele : cout<<z;
        cout<<endl;
    }
};

int main(){
    myStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
    s.getMin();

    return 0;
}

