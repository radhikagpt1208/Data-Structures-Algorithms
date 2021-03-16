/* Top Down DP based Solution for Fibonacci Number :
    The basic idea is to store the overlapping subproblems. We can do this by making an array that will store the solution of overlapping subproblems.
    This is basically adding memory to your recursive solution. (Recursion + Memoization)
   Space Complexity : O(N)
   Time Complexity : O(N)   */

#include<iostream>
using namespace std;

int fib(int n, int dp[]){
    if(n == 0 || n == 1){
        return n;
    }
    //Lookup : If the value is precomputed in some other call
    if(dp[n] != 0){
        return dp[n];
    }
    int ans;
    ans = fib(n-1, dp) + fib(n-2, dp);
    return dp[n] = ans;
}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};

    cout<<fib(n, dp)<<endl;
}

