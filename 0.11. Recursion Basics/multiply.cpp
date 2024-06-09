#include<iostream>
using namespace std;

int multiply(int a , int b){
    //base case
    if(a == 0 || b == 0){
        return 0;
    }
    //recursive case
    return a + multiply(a , b-1);
}

int main(){
    int a , b;
    cin>>a>>b;
    cout<<multiply(a , b);
    return 0;
}
