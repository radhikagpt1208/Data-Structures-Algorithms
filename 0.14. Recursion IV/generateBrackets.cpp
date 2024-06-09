#include<iostream>
using namespace std;

void generateBrackets(int n , char *output , int i , int open , int close){
    //base case
    //for n number of brackets,there will be 2n,i.e,opening and closing
    if(i == 2*n){
        output[i] = '\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    //2 options
    if(open < n){
        output[i] = '(';
        generateBrackets(n , output , i + 1 , open + 1 , close);
    }
    if(close < open){
        output[i] = ')';
        generateBrackets(n , output , i + 1 , open , close + 1);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    char output[1000];
    generateBrackets(n , output , 0 , 0 , 0);
    return 0;
}
