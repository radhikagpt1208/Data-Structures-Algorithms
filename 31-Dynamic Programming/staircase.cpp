/*Given n no.of staircases,find the total number of ways to reach nth stair from the bottom when a person is only allowed to take atmost k steps at each step.
We can easily find the recursive nature in the above problem.
The person can reach nth stair from (n-1)th stair,(n-2)th stair,..., (n-k)th stair.
Hence, for each stair n, we try to find out the number of ways to reach (n-1)th,(n-2)th..(n-k)th stair and add them to give the answer for the nth stair.
Therefore the expression for such an approach comes out to be :
f(n) = f(n-1) + f(n-2) +....+ f(n-k)
This can be implemented using Top Down DP, Bottom Up DP and to make the time complexity linear, it can also be done using the concept of sliding window*/

#include<iostream>
using namespace std;

//1. Top Down DP
//Time Complexity : O(N.K) ; Space Complexity : O(N)
int stairs1(int n, int k, int dp[]){
    //Base Case
    //0 means you're on the ground and there is only one way to stand on the ground
    if(n == 0){
        return 1;
    }
    //Lookup
    if(dp[n] != 0){
        return dp[n];
    }
    //Rec case
    //find the number of ways to reach all possible number of stairs less than or equal to n from the present stair
    int ways = 0;
    for(int i = 1; i <= k; i++){
        if(n - i >= 0){
            ways += stairs1(n - i, k, dp);
        }
    }
    return dp[n] = ways;
}

//2. Bottom Up DP
//Time Complexity : O(N*K)
int stairs2(int n, int k){
    int dp[100] = {0};
    //Initialize the base case
    dp[0] = 1;    //way to reach the 0th step is 1
    //calculate the number of ways to reach every step till n
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        //for every ith step, iterate over the last k steps and sum the no. of ways of reaching (i-1)th step,(i-2)th...(i-k)th step such that the ith
        //index of the array will contain the no. of ways required to reach the ith step considering all the possibilities of climbing (i.e. from 1 to i).
        for(int j = 1; j <= k; j++){
            //add up the last k(=3) states
            if(i - j >= 0){
                dp[i] += dp[i - j];
            }
        }
    }
    //Print the DP array to see the no. of ways to reach all the steps up to n
    for(int i = 0; i <= n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}

/* 3. Using the technique of Sliding Window to arrive at the solution. It efficiently implements the DP approach making the time complexity linear.
For the (i-1)th stair, we keep a window of sum of last k possible stairs from which we can climb to the (i-1)th stair,i.e, for every (i-1)th stair
we need a window that has k no. of elements denoting the no. of ways to climb the last k possible stairs. Hence we have a window of k stairs.
For every(i)th stair,we will need its previous k elements for which we will have to add the no. of ways to climb (i-1)th stair and subtract the first
element of the prev window.
So for the dp[i-1] we add the last k elements, but for dp[i], the window will move forward by 1 step and hence we subtract the first
element from the previous window and add the (i-1)-th element.
Hence, dp[i] = dp[i-1] - dp[i-1-k] + dp[i-1]
Time Complexity : O(N + K) ~ O(N)  */
int stairs3(int n, int k){
    int dp[100] = {0};
    //initialize the base case
    dp[0] = dp[1] = 1;
    //for elements where (i-1-k)th stair does not exist
    for(int i = 2; i <= k; i++){
        dp[i] = 2 * dp[i - 1];
    }
    for(int i = k + 1; i <= n; i++){
        dp[i] = 2 * dp[i - 1] - dp[i - 1- k];
    }
    //Print the DP array to see the no. of ways to reach all the steps up to n
    for(int i = 0; i <= n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}


int main(){
    int n, k;
    cin>>n>>k;
    int dp[100] = {0};

    cout<<"Number of ways(using top down dp) :"<<stairs1(n, k, dp)<<endl;
    cout<<"Number of ways(using bottom up dp) :"<<stairs2(n, k)<<endl;
    cout<<"Number of ways :"<<stairs3(n, k)<<endl;
}
