/* Consider a row of n coins of values A1,A2,..An, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects
either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of
money we can definitely win if we move first. Note: The opponent is as clever as the user.
Approach: As both the players are equally strong, both will try to reduce the possibility of winning of each other.
There are two choices:
1. The user chooses the ith coin with value Ai. The opponent either chooses (i+1)th coin or jth coin. The opponent intends to choose the max value coin which
   leaves the user with minimum value.
   So the opponent will choose max of the (i+1)th coin or the jth coin. Hence the user can collect the value (Ai + min(f(i+2, j), F(i+1, j-1) ).
2. The user chooses the jth coin with value Aj. The opponent either chooses ith coin or (j-1)th coin. The opponent intends to choose the max value coin
   which leaves the user with minimum value.
   The opponent will choose max of the ith coin or the (j-1)th coin,i.e. the user can collect the value Aj + min(f(i+1, j-1), f(i, j-2) ).
Following is the recursive solution that is based on the above two choices. We take a maximum of two choices: f(i, j) represents the max value the user
can collect from ith coin to jth coin.
f(i, j) = max(Ai + min(f(i+2, j), f(i+1, j-1) ),
              Aj + min(f(i+1, j-1), f(i, j-2) ))
As user wants to maximize the number of coins.
Base Cases :
    f(i, j) = Ai           If j == i     (when no elements are left in the array)
    f(i, j) = max(Ai, Aj)  If j == i + 1 (greedy approach can be followed when j == i + 1,i.e, when there are only 2 coins)

*/

#include<iostream>
using namespace std;

int arr[10001];
int dp[10001][10001];

int optimal_strategy(int i, int j){
    //dp[i][j]= maximum amount you can definitely win if you move first with available coins[i...j]
    //Base case
    //if no coins are left
    if(i > j){
        return dp[i][j] = 0;
    }
    //if only 2 coins are left, player will obviously choose the max coin
    if(j == i + 1){
        return dp[i][j] = max(arr[i], arr[j]);
    }
    //Lookup
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int opt1 = arr[i] + min(optimal_strategy(i + 2, j), optimal_strategy(i + 1, j - 1));
    int opt2 = arr[j] + min(optimal_strategy(i + 1, j - 1), optimal_strategy(i, j - 2));
    dp[i][j] = max(opt1, opt2);

    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Maximum value you can win is : "<<optimal_strategy(0, n-1)<<endl;
    return 0;
}
