#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(char *s){
    stack<char> a;
    for(int i = 0; s[i] != '\0'; i++){
        char ch = s[i];

        if(ch == '('){
            a.push(ch);
        }
        else if(ch == ')'){
            //no pairing can happen in this case
            if(a.empty() || a.top()!='('){
                return false;
            }
            //else pairing will take place and we pop the opening brackett
            a.pop();
        }
    }
    return a.empty();
}

int main(){
    char s[100] = "((a+b)+(c-d+f)";
    if(isValidExp(s)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
