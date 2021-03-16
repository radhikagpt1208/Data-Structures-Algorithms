#include<iostream>
#include<stack>
using namespace std;

void showstack(stack <int> s) {
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout <<endl;
}

int main (){
	stack <int> s;
	s.push(10);
	s.push(30);
	s.push(20);
	s.push(5);
	s.push(1);

	cout<<"The stack is: ";
	showstack(s);
	cout<<"s.size(): "<<s.size()<<endl;
	cout<<"s.top(): "<<s.top()<<endl;
	cout<<"s.pop(): "<<endl;
	s.pop();
	showstack(s);

	return 0;
}

