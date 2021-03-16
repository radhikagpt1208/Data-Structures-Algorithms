/* Problem Statement: Given n friends,they have to go to a party. Each one can remain single or can be paired up with some other friend. Each friend can be paired only once.
Find out the total number of ways in which friends can go to the party.
DP Approach :
f(n) = ways n people can remain single or pair up.
For n-th person there are two choices:
1)nth person remains single, we recur for the remaining n-1 friends for f(n - 1)
2)n-th person pairs up with any of the remaining n-1 persons,i.e,he will choose 1 friend out of the remaining n-1 friends as (n-1)C(1).We get (n-1)*f(n-2)
Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1)C(1) * f(n - 2) =  f(n - 1) + (n - 1) * f(n - 2) */

#include<iostream>
using namespace std;

//Bottom Up DP
int pairing(int n, int dp[]){
    for(int i = 0; i <= n; i++){
        //Initialize the base case
        if(i <= 2){
            dp[i] = i;
        }
        else{
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    cout<<"Total no. of ways are : "<<pairing(n, dp);
}

