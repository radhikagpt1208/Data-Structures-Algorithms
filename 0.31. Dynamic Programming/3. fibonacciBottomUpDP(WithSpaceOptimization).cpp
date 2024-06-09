/* Bottom Up DP based Solution for Fibonacci Number :
    We will make an array and initialize the base cases in the array and then you will compute the other subproblems in a bottom up fashion.
    Space Complexity : O(N)
    Time Complexity : O(N)
    For space optimization,we can use 2 variables, say a and b that will store the previous 2 values since every time we don't need the entire array,
    instead only last 2 values are required.  Hence,array can be eliminated.
    Space Complexity : O(1)
    */

#include<iostream>
using namespace std;

int fib(int n, int dp[]){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//Bottom Up Approach With Space Optimization
int fibo(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};

    cout<<fib(n, dp)<<endl;
    cout<<fibo(n)<<endl;
    return 0;
}


