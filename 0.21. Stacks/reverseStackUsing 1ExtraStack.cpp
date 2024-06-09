#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>& s1, stack<int>& s2, int n){
    for(int i = 0; i < n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1){
    //helper stack
    stack<int> s2;
    int n = s1.size();
    for(int i = 0; i < n; i++){
        //pick the element at the top and insert it at the bottom
        //1.store the top most element in another variable and then remove that element from the stack
        int x = s1.top();
        s1.pop();
        //2.transfer the remaining n-1-i elements from s1 to s2
        transfer(s1, s2, n-i-1);
        //3.insert x at the bottom of s1
        s1.push(x);
        //4. transfer again from s2 to s1
        transfer(s2, s1, n-i-1);
    }
}

int main (){
	stack <int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverseStack(s);

	while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
	}
	return 0;
}

