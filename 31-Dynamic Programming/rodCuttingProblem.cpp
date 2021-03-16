/* Problem Statement :
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n,i.e, you are given the price of each piece
of length 1,2,3,...,n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. */

#include<iostream>
#include<climits>
using namespace std;

//Recursive Solution
int max_profit(int prices[], int n){
    //Base Case
    if( n <= 0){
        return 0;
    }
    int ans = INT_MIN;
    //while iterating over the prices array, for every value of i we are cutting a piece of length i+1
    for(int i = 0; i < n; i++){
        //try all possible solutions,i.e, cut pieces of every length possible and then recursively find the profit from the leftover length
        int cut_length = i + 1;

        int current_ans = prices[i] + max_profit(prices, n - cut_length);
        ans = max(ans, current_ans);
    }
    return ans;
}

//Bottom Up DP Approach
//Time Complexity : O(N^2)
int max_profit_dp(int *prices, int n){
    //the DP array,i.e, dp[len] will contain the maximum profit gained by cutting a piece of length 'len'
    int dp[n + 1];
    //initialize the base case
    dp[0] = 0;
    //calculate profit for all possible lengths
    for(int len = 1; len <= n; len++){
        int ans = INT_MIN;
         for(int i = 0; i < len; i++){
            int cut_length = i + 1;
            int current_ans = prices[i] + dp[len - cut_length];
            ans = max(ans, current_ans);
         }
         //we have computed the max profit for dp[len]
         dp[len] = ans;
    }
    return dp[n];
}

int main(){
    //the prices array has a 0 based indexing but the length of all the pieces starts from 1 to n(i.e, price of length i = prices[i-1])
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices)/sizeof(int);
    //the output for the given array is 22 if we cut a piece of length 6 and a piece of length 2 (17 + 5 = 22)
    cout<<max_profit(prices, n)<<endl;
    cout<<max_profit_dp(prices, n)<<endl;

    return 0;
}
