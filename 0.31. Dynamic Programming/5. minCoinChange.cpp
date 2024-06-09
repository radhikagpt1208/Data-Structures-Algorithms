/* Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
what is the minimum number of coins to make the change?
Approach :
The minimum number of coins for a value V can be computed using below formula :
If V == 0, then 0 coins required.
If V > 0,
   minCoins(coins[0..m-1], V) = min {1 + minCoins(V-coin[i])} where i varies from 0 to m-1 and coin[i] <= V
Using DP, time complexity : O(mV) where m is the number of coins given and V is the input amount for which change has to be made. */

#include<iostream>
#include<climits>
using namespace std;

////TOP DOWN DP :
//n : types of coins available to us
int minCoins1(int amt, int coins[], int n, int dp[]){
    //Base Case
    if(amt == 0){
        return 0;
    }
    //Lookup
    if(dp[amt] != 0){
        return dp[amt];
    }
    //Rec Case : find the sub problems from all possible coins available
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        //ensures that you don't choose coins that are larger than the amount
        if(amt - coins[i] >= 0){
            int sub_prob_ans = minCoins1(amt - coins[i] , coins, n, dp);
            ans = min(ans, sub_prob_ans + 1);
        }
    }
    dp[amt] = ans;
    return dp[amt];
}

//BOTTOM UP APPROACH
int minCoins2(int amt, int coins[], int n){
    int dp[100] = {0};
    //initialize the base case
    dp[0] = 0;

    //Iterate over all states from 1....amt
    for(int i = 1; i <= amt; i++){
        //initialize the current answer
        dp[i] = INT_MAX;
        //find the sub problems from all the coins given
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                int sub_prob_ans = dp[i - coins[j]];
                dp[i] = min(dp[i], sub_prob_ans + 1);
            }
        }
    }
    return dp[amt];
}

int main(){
    int n;      //number of coins available
    cin>>n;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }
    int dp[100] = {0};
    int V;
    cin>>V;

    //cout<<minCoins1(V, coins, n, dp)<<endl;
    cout<<minCoins2(V, coins, n)<<endl;
    return 0;
}

/* Input :
    3
    1 7 10
    15
   Output :
    3
*/
