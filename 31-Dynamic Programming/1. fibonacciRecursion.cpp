/* Recursion based Solution for Fibonacci Number :
   Space Complexity : O(N)
   Time Complexity : O(2^N)   */

#include<iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int ans;
    ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
}
