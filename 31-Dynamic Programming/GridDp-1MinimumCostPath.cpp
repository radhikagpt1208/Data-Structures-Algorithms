/*Given a cost matrix cost[][] and a position (x,y) in cost[][], write a function that returns cost of minimum cost path to reach (x,y) from (0, 0).
Each cell of the matrix represents a cost to traverse through that cell.Total cost of a path to reach (x,y) is sum of all the costs on that path
(including both source and destination). You can only traverse down and right cells from a given cell, i.e,from a given cell (i, j), cells (i+1, j) and
(i, j+1) can be traversed. You may assume that all costs are positive integers.
Approach : The path to reach (x,y) must be through one of the 2 cells: (x-1,y) or (x, y-1). So minimum cost to reach (x,y) can be written as
minimum of the 2 cells plus cost[x][y]
minCost(x,y) = min (minCost(x-1, y), minCost(x, y-1)) + cost[x][y] */

#include<iostream>
using namespace std;
#define R 3
#define C 3

int dp[1000][1000];

int min_cost(int cost[R][C]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            //If you are at the zeroth row and zeroth column
            if(i == 0 && j == 0){
                dp[i][j] = cost[0][0];
            }
            //you can traverse the zeroth row by moving only in the rightward direction
            else if(i == 0){
                dp[i][j] = dp[0][j - 1] + cost[0][j];
            }
            //you can traverse the zeroth col by moving only in the downward direction
            else if(j == 0){
                dp[i][j] = dp[i - 1][0] + cost[i][0];
            }
            //else you can move in either directions
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
            }
        }
    }
    return dp[R - 1][C - 1];
}

int main(){
    int cost[R][C] = {
                       {1, 5, 2},
                       {7, 1, 1},
                       {8, 1, 3}
                     };
    cout<<min_cost(cost);
    return 0;
}
