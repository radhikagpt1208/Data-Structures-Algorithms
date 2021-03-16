/* A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell.
The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions.
That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.
Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells,
your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).
Since the answer can get very large, output the answer modulo 1000000007.
Input :
The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.
Output :
Output should contain a single integer, the number of paths modulo 1000000007.

Approach : You can reach a cell (i,j) from their neighboring cells by moving right or down if those cells are not blocked by the formula :
ans[i][j] = ans[i][j-1] + ans[i-1][j]. We will make an array ways[][] that will store the no. of ways to reach a cell (i,j).
So,ways to reach any cell (i,j) in the 0th row or 0th column will always be 1 because you can either reach by moving right or by moving down respectively but
this is only when no cell is blocked. If any of the cells in between is blocked, the ways to reach that cell and all the cells following it will be 0. */

#include<iostream>
#include<cstring>
using namespace std;
#define MOD 1000000007

int dp[1001][1001];

int count_ways(int M, int N){
    //Base Case
    //If the origin(starting cell) is blocked, we can't move further
    if(dp[0][0] == -1){
        return 0;
    }
    //compute ways for first row
    for(int j = 0; j < N; j++){
        if(dp[0][j] == -1){
            break;      //you can't go further, hence no. of ways for those cells remain 0
        }
        dp[0][j] = 1;   //else the no. of ways to reach any cell in the first row is 1
    }
    //compute ways for first column
    for(int j = 0; j < M; j++){
        if(dp[j][0] == -1){
            break;      //you can't go further, hence no. of ways for those cells remain 0
        }
        dp[j][0] = 1;   //else the no. of ways to reach any cell in the first col is 1
    }

    //Bottom Up DP for the remaining cells
    for(int i = 1; i < M; i++){
        for(int j = 1; j < N; j++){
            //if the cell is blocked,just move on to the next cell
            if(dp[i][j] == -1){
                continue;
            }
            //otherwise assume answer for the current cell is 0
            dp[i][j] = 0;
            //to reach (i,j) if the cell in the same row and the previous col is not blocked, you can reach (i,j) by moving right
            if(dp[i][j-1] != -1){
                dp[i][j] = dp[i][j-1] % MOD;
            }
            //to reach (i,j) if the cell in the same col and the previous row is not blocked, you can reach (i,j) by moving down
            if(dp[i-1][j] != -1){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
    }
    //Check : if the final cell is blocked, you can't reach that cell
    if(dp[M-1][N-1] == -1){
        return 0;
    }
    //Print the DP table
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[M-1][N-1];
}

int main(){
    memset(dp, 0, sizeof dp);
    int M, N, P;      //M : no. of rows  N : no. of cols  P : no. of blocked cells
    cin>>M>>N>>P;

    for(int i = 0; i < P; i++){
        int x, y;
        cin>>x>>y;
        //Mark all blocked cells as -1
        dp[x-1][y-1] = -1;       //DP array has 0 based indexing, hence we subtract 1
    }
    cout<<count_ways(M, N)<<endl;
    return 0;
}

/* Input :
    4 3 2
    3 3
    3 1
   Output :
    2
*/
