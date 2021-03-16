/* Problem Statement :
Given a number n, count minimum steps to minimize the number n to 1 according to the following criteria:
->If n is divisible by 2 then you may reduce n to n/2.
->If n is divisible by 3 then you may reduce n to n/3.
->Decrement n by 1.

1. Greedy Approach (Does not work always) :
As per greedy approach we may choose the step that makes n as low as possible and continue the same, till it reaches 1.
while ( n > 1){
    if (n % 3 == 0)
        n /= 3;
    else if (n % 2 == 0)
        n /= 2;
    else
        n--;
    steps++;
}
If we observe carefully, the greedy strategy does not work here.
Example: Given n = 10 , Greedy -> 10 /2 = 5 -1 = 4 /2 = 2 /2 = 1 ( 4 steps ).
But the optimal way is -> 10 -1 = 9 /3 = 3 /3 = 1 ( 3 steps ).
So, we must think of dynamic approach for optimal solution.

2. Dynamic Approach: Time Complexity is O(N)
For finding minimum steps we have three possibilities for n, i.e, n can be reduced to : (n-1), n/2 and n/3.
f(n) = min (f(n-1), f(n/2), f(n/3)) + 1    ( +1 to reach from n to either of the 3 states)
*/

#include<iostream>
#include<climits>
using namespace std;

//TOP DOWN APPROACH
int minSteps1(int n, int dp[]){
    //Base Case
    if(n == 1){
        return 0;
    }
    //Lookup if n is already computed
    if(dp[n] != 0){
        return dp[n];
    }
    //Rec Case
    int opt1, opt2, opt3;
    opt1 = opt2 = opt3 = INT_MAX;

    if(n % 3 == 0){
       opt1 = minSteps1(n/3, dp);
    }
    if(n % 2 == 0){
        opt2 = minSteps1(n/2, dp);
    }
    opt3 = minSteps1(n-1, dp);

    int ans = min(min(opt1, opt2), opt3);
    dp[n] = ans + 1;
    return dp[n];
}

//BOTTOM UP APPROACH :
int minSteps2(int n){
    int dp[100] = {0};
    //initialize the base case
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        int opt1, opt2, opt3;
        opt1 = opt2 = opt3 = INT_MAX;

        if(i % 3 == 0)
            opt1 = dp[i/3];
        if(i % 2 == 0)
            opt2 = dp[i/2];
        opt3 = dp[i - 1];

        dp[i] = min(min(opt1, opt2), opt3) + 1;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    int dp[100] = {0};
    cout<<minSteps1(n, dp)<<endl;
    cout<<minSteps2(n)<<endl;
    return 0;
}

