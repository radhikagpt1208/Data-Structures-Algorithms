#include<iostream>
using namespace std;

int pow(int a , int n){
    //base case
    if(n == 0){
        return 1;
    }

    //recursive call
    return a * pow(a , n-1);
}

//optimized approach
int fastPower(int a , int n){
    //base case
    if(n == 0){
        return 1;
    }
    //rec case
    int sub_ans = fastPower(a , n/2);
    sub_ans *= sub_ans;
    //if n is odd,we can write a*(a^n/2)^2
    if(n % 2 != 0){      //or: if(n&1)
        return a * sub_ans;
    }
    //if n is even,we can write (a^n/2)^2
    return sub_ans;
}

int main(){
    int a , n;
    cin>>a>>n;
    cout<<pow(a , n)<<endl;
    cout<<fastPower(a , n);
    return 0;
}
