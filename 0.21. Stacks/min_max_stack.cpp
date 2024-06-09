#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class min_max_stack{
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

public:
    void push(int data){
        int curr_min = data;
        int curr_max = data;
        if(min_stack.size()){
            curr_min = min(min_stack[stack.size()-1],data);
            curr_max = max(max_stack[stack.size()-1],data);
        }
        stack.push_back(data);
        min_stack.push_back(curr_min);
        max_stack.push_back(curr_max);
    }
    void pop(){
        stack.pop_back();
        min_stack.pop_back();
        max_stack.pop_back();
    }

    int get_min(){
        return min_stack[min_stack.size()-1];
    }

    int get_max(){
        return max_stack[max_stack.size()-1];
    }

    int top(){
        return stack[stack.size()-1];
    }

    bool empty(){
        return stack.size() == 0;
    }
};

int main(){
    min_max_stack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout<<s.get_max()<<endl;
    s.pop();
    cout<<s.get_min()<<endl;
    cout<<s.get_max()<<endl;

    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.get_max()<<endl;
    cout<<s.get_min()<<endl;
    return 0;
}
