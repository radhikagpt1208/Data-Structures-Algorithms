/* Traveling Salesman Problem (TSP):
-> Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once
   and returns to the starting point.
-> Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once.
-> A Hamiltonian cycle is a Hamiltonian Path such that there is an edge (in the graph) from the last vertex to the first vertex of the Hamiltonian Path,i.e,
   it contains of a set of edges such that every node is visited once and we finally come back to the starting node.
-> Here we know that Hamiltonian Tour exists (because the graph is complete) and in fact many such tours exist,
   the problem is to find a minimum weight Hamiltonian Cycle.

Naive Solution:
1) Consider city 1 as the starting and ending point.
2) Generate all (n-1)! Permutations of cities.
3) Calculate cost of every permutation and keep track of minimum cost permutation.
4) Return the permutation with minimum cost.
Time Complexity: O(n!)

Use a mask that denotes the cities that have been visited in the current call.
Another Approach : Choose the origin city and recursively find the distance to reach the origin city from all the different options,i.e,
suppose you have 4 cities A,B,C and D and A is the origin city. Now suppose from A, you have a direct to B, C and D. So you find the
distance of visiting all the vertexes via B, C and D and as soon as the mask becomes 1111, you return the distance of going back to the
origin city. Hence, you will get all the possible answers, and you choose the minimum one.
Dynamic Programming Based Approach :
Optimization in the mask approach : Total number of distinct states in DP will be 2^n * n (states of the mask can vary from 0 to (1<<n)-1,i.e,starting from 0000 to 1111
and the position variable represents n cities).
Hence we can make a 2D DP table of the order [2^n][n] which will optimize the time complexity from O((n-1)!) to O(2^n*n) */

#include<iostream>
using namespace std;
#define INT_MAX 999999

int n = 4;
int dp[16][4];
//Adj Matrix that defines our graph
int dist[10][10] = {
                    {0, 20, 42, 25},
                    {20, 0, 30, 34},
                    {42, 30, 0, 10},
                    {25, 34, 10, 0}
};

//Define a mask if all cities have been visited(i.e, integer as last n bits as 1 because when all cities have been visited, all the bits would be 1)
int VISITED_ALL = (1<<n) - 1;

//this function accepts the mask through which we will get to know the cities that have not been visited yet in the current path(cities that are marked 0)
//and the position of the current city so that appropriate cost can be added
int tsp(int mask, int pos){
    //Base Case : if we have visited all cities
    if(mask == VISITED_ALL){
        //return the distance of going back to the origin from the current city because you have to return back to the origin city
        return dist[pos][0];
    }
    //if value has already been computed(in case of overlapping subproblem)
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    //otherwise,from the current node try to visit all the cities which have not been visited
    for(int city = 0; city < n; city++){
        //check if the current city has been visited or no by making a temporary mask and using bitwise '&' operator which does AND on every bit of the
        //two masks. If the final value of ith bit is 1 city is visited and if it is 0 it is unvisited,i.e, check if the ith bit is 1 or 0
        if((mask&(1<<city)) == 0){
            //city is unvisited if ith bit is 0
            //try to guess what is the answer from this city,which is :
            //distance of going from the current city to the new city + remaining distance(given by recursive call)
            //in rec call,change the mask such that the new city is now visited and update the position of the current city to the new city
            int newAns = dist[pos][city] + tsp(mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    for(int i = 0 ; i  <(1<<n)-1; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }
    //arguments are such that we are starting from the 0th city and the 0th city has been visited(hence mask is 1 which denotes 0001)
    cout<<"Cost of Minimum Weight Hamiltonian path is : "<<tsp(1, 0)<<endl;
    return 0;
}










