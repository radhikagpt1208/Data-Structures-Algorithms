#include<iostream>
#include<stack>
using namespace std;

class Queue{
	stack<int> s1, s2;

public:
	int size(){
		return s1.size();
	}

	bool empty(){
		return size() == 0;
	}

	void push(int x){
		//push all elements from s1 to s2
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		//push everything back to s1
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}

	void pop(){
		if(s1.empty()){
			return;
		}
		else{
			s1.pop();
		}
	}

	int front(){
		if(s1.empty()){
			return NULL;
		}
		else{
			int x = s1.top();
			return x;
		}
	}
};

int main() {
	Queue q;
	int n;
	cin>>n;

	for(int i = 0 ; i < n ; i++){
		q.push(i);
	}

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}
