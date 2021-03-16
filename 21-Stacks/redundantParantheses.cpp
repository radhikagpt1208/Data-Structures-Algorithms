/*We iterate through the given expression and for each character in the expression, if the character is a open parenthesis ‘(‘
or any of the operators or operands, we push it to the stack.
If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found.
Now for redundancy two condition will arise while popping-
1.If immediate pop hits a open parenthesis ‘(‘, then we have found a duplicate parenthesis.
2.If immediate pop doesn't hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets
surrounded by expression. */

#include<iostream>
#include<stack>
using namespace std;

bool checkRedundancy(string str){
	stack<char> s;
	for(int i = 0; str[i] != '\0'; i++){
		char ch = str[i];

		if(ch == ')'){
			char top = s.top();
			if(top == '('){
				return true;
			}
			while(!s.empty() && s.top() != '('){
				s.pop();
			}
			s.pop();
		}
		else{
			s.push(ch);
		}
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		if(checkRedundancy(str)){
			cout<<"Duplicate"<<endl;
		}
		else{
			cout<<"Not Duplicates"<<endl;
		}
	}
}
