/* You are given a 2D array and you have to find the number of ways in which you can reach a particular position from a given starting point in the 2D grid
   for the following 2 cases :
    1. You are given a Rat that can only move rightwards or downwards by 1 step.
    2. You are given an Elephant that can move rightwards and downwards by K no. of steps.

Approach 1 : Using recursion and DP
In case of a rat, the row and the first column of the grid can be traversed only in 1 way,i.e, you can go to every next cell in the first row by moving only
in one direction,i.e, rightwards. Similarly, to move in the first col, you can move only in one direction,i.e, downwards.
However, for all the other cells, you will have 2 ways to reach that cell, either by moving downwards or rightwards,i.e, dp[x][y] = dp[x-1][y] + dp[x][y-1].
Time Complexity for this approach is O(N^2)
Approach 2 : Using mathematical formula of Permutations and Combinations
Suppose there are R rows and C columns in the grid. To traverse R cells in the right direction and C cells in the downward direction, you will need R-1 and
C-1 steps respectively. Now you can permute these steps in any order,i.e, arrange right and downward moves in any random order.
So, no. of possible permutations you can make = ( (R - 1) + (C - 1) )!)/ (R-1)! * (C-1)! because (R-1) and (C-1) ways are identical.
However, you cannot apply this formula if you have a case where some of the cells are blocked. When certain cells are blocked, you can apply
DP and say that the no. of ways to reach a cell which is blocked is 0.
Time Complexity of this approach : O(N)

In case of an elephant, for the same path you have multiple ways as it depends on the no. of steps you take to traverse the path(Since the elephant can cover
the whole path with K no. of steps in any random manner). Hence,to reach a cell (x,y), you have to take the sum along the row and the column.
dp[x][y] = Σ dp[k][y] where k ranges from 0 to x-1 + Σ dp[x][k] where k ranges from 0 to y-1
Time Complexity : O(N^3)  */

#include<bits/stdc++.h>
using namespace std;

//Approach 1
int rat_ways(int R, int C){
    int dp[R][C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            //there is one way to traverse the first row & the first col,i.e,moving towards right or down
            if(i == 0 || j == 0){
                dp[i][j] = 1;
            }

            //you can traverse the (i,j)-th cell by moving either rightwards or downwards
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[R-1][C-1];
}

//Approach 2
int fac(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n*fac(n-1);
}

int rat_ways1(int R, int C){
    int numerator = fac(R - 1 + C - 1);
    int denominator = fac(R-1) * fac(C-1);
    return numerator/denominator;
}

int elephant_ways(int R, int C){
    int dp[R][C];
    memset(dp, 0, sizeof(dp));
    //there is one way to reach the first cell
    dp[0][0] = 1;
    //ways for the first column
    for(int i = 1; i < R; i++){
        for(int k = 0; k < i; k++){
            dp[i][0] += dp[k][0];
        }
    }
    //ways for the first row
    for(int i = 0; i < C; i++){
        for(int k = 0; k < i; k++){
            dp[0][i] += dp[0][k];
        }
    }
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            int x1 = 0, x2 = 0;
            for(int k = 0; k < i; k++){
                x1 += dp[k][j];
            }
            for(int k = 0; k < j; k++){
                x2 += dp[i][k];
            }
            dp[i][j] = x1 + x2;
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[R-1][C-1];
}

int main(){
    int R, C;
    cin>>R>>C;

    cout<<rat_ways(R, C)<<endl;
    cout<<rat_ways1(R, C)<<endl;
    cout<<elephant_ways(R, C)<<endl;
    return 0;
}
