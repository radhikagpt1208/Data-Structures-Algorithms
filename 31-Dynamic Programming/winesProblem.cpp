/* Problem Statement : Maximum profit from sale of wines
Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sale the first or the last wine in the row.
However,the price of wines increases over time. Let the initial profits from the wines be P1, P2, P3..Pn.
On the Yth year, the profit from the ith wine will be Y*Pi.
For each year, your task is to print "beg" or "end" denoting whether first or last wine should be sold.
Also, calculate the maximum profit from all the wines.

Greedy Approach :
This initially looks like a greedy problem in which every year,we should sell the cheaper of the two (leftmost and rightmost) available wines so that we get
maximum profit in the coming years by selling expensive wines later. However, the greedy solution does not guarantee a globally optimal solution.
Rec Approach :
In every step of recursion, we have two choices, either select the first wine or the last wine.We will try all possible solutions and then check the solution
which gives the maximum answer. We will pick either the first wine and multiply with the current year and recursively move to next year or we will select the
last wine and multiply with the current year and move recursively to the next part.
Then we will select the maximum of the two subproblems(profit obtained by selecting leftmost wine or profit obtained by selecting the rightmost wine)
for the current solution as follows :
f(beg, end, year) = max( p[beg]*year + f(beg+1, end, year+1) , p[end]*year + f(beg, end-1, year+1)
So, we have a total of 2^(n-1) choices. Therefore time complexity - O(2^n)
DP Approach :
Since in the recursion tree, there are many overlapping subproblems we can reduce the time complexity be memoization technique.
In this approach, when we calculate the profit, we save it in an array so that if the profit has to be calculated again next time, we can reuse it and
save time and space. For this, we will use a 2D array because it involves two variables(beg, end) that are getting updated after every call.
By doing memoization, the time complexity decreases to O(N^2).
*/

#include<iostream>
using namespace std;

//Top Down Approach
int max_profit(int wines[], int beg, int end, int year, int dp[][100]){
    //Base Case
    //If there are no bottles left, profit = 0
    if(beg > end){
        return 0;
    }
    //Lookup
    if(dp[beg][end] != 0){
        return dp[beg][end];
    }
    //Rec Case
    //you have 2 options
    //1. You sell the first bottle and check the profit you will get from the remaining bottles
    int opt1 = wines[beg]*year + max_profit(wines, beg + 1, end, year + 1, dp);
    //2. You sell the last bottle and check the profit you will get from the remaining bottles
    int opt2 = wines[end]*year + max_profit(wines, beg, end - 1, year + 1, dp);

    return dp[beg][end] = max(opt1, opt2);
}
//Bottom Up DP
int profit(int *wines, int n){
    int dp[n][n];
    //if i > j that means no bottles are left
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j)
                dp[i][j] = 0;
        }
    }
    //you are left with only one bottle,i.e, the case in the n-th year when you have sold the rest (n-1) bottles
    for(int i = 0; i < n; i++){
        dp[i][i] = n * wines[i];
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(i != j && i < j){
                int year = n - (j - i);
                dp[i][j] = max(year*wines[i] + dp[i+1][j] , year*wines[j] + dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof(wines)/sizeof(int);
    int dp[100][100] = {0};

    //cout<<max_profit(wines, 0, n - 1, 1, dp)<<endl;
    cout<<profit(wines, n)<<endl;
    return 0;
}



