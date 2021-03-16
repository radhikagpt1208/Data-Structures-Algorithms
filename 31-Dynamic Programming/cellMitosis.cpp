/* There's a scientist named Brook who is interested in budding of cells. He has one container which initially contains only a single cell.
Now Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways :
    1.Double the number of cells present in the container.
    2.Increase the number of cells in the container by 1.
    3.Decrease the number of cells in the container by 1.
Now, all the above operations have different costs associated with them x,y,z respectively for above operations. Help brook in finding the minimum cost to
generate n cells in the container starting from one cell .
Input Format :
Each test case contains 2 lines. First lines contains an integer n Second lines contains 3 space separated integers x, y, and z.
Solution :
Now, for i no of cells, you can either make it to 2*i or i + 1 or i - 1. Hence, we can reach i from 3 states : (i/2), (i - 1) and (i + 1).
The current state i can be divided into 2 cases :
1.When i is odd
    a)When you are computing value of dp[i],you can't consider the first case(doubling i) because i is not a multiple of 2. So you can't reach (i/2)th state.
    b)Now to reach i, you can either come from (i-1)th state or (i+1)th state.
      When you are computing dp[i], you can first reach the state (i-1) and then increment it by 1 to reach ith state.
      Hence, first option of cost of making dp[i] = dp[i-1] + y(cost of incrementing) and the cost of dp[i-1] is already computed.
      However, in the second option, dp[i+1] is not computed. Hence, to reach (i+1)th state, we can either come from ith state but since we are already
      computing the cost of reaching ith state, we can't use this path. So the only way of reaching (i+1)th state is by coming from (i/2)th state.
      For eg: If i = 7, we can reach 7 via 6 by incrementing it by 1 however to reach 7 from 8, we will have to first go to 4 and then double it to reach 8
      and then decrement by 1 to reach 7. Hence cost is : dp[i] = dp[i+1/2] + x(doubling cost) + z(decrementing cost).
    Hence, when i is odd, dp[i] = min( dp[i-1] + y, dp[i+1/2] + x + z)
2.When i is even
    a)When you are computing value of dp[i], you can first reach the state (i/2) and then double it.
      Hence, first option of cost of making dp[i] = dp[i/2] + x(cost of doubling)
    b)When you are computing value of dp[i], you can first reach the state (i-1) and then increment it by 1 to reach ith state.
      Hence, second option of cost of making dp[i] = dp[i-1] + y(cost of incrementing)
    c)We can't consider the third case,i.e,decrementing by 1 because when I say that  I have to reach state i from state (i+1) by decreasing it by 1, it is
      always going to cost more because we will have to perform more no. of operations to reach (i+1)th state because it is an odd value.
    Hence, when i is even, dp[i] = min( dp[i/2] + x, dp[i-1] + y) */

#include<iostream>
using namespace std;

//Bottom Up DP
long long solve_cell(int n, int x, int y, int z){
    long long *dp = new long long[n+1];
    //Base Case : to construct 0 cells or 1 cell, we need 0 cost
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        if(i % 2 == 0){
            dp[i] = min(dp[i/2] + x, dp[i-1] + y);
        }
        else{
            dp[i] = min(dp[(i+1)/2] + x + z, dp[i-1] + y);
        }
    }
    for(int i = 0; i <= n; i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];
}

int main(){
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    cout<<solve_cell(n, x, y, z);
    return 0;
}
