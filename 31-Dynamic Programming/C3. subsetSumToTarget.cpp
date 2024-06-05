/* Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Method 1: Using Recursion - Time Complexity is exponential
For every element, we have 2 choices,i.e, either we choose that element in the sub array or we don't. For the recursive approach we will consider two cases.
1. We will either consider the last element in the subset so that now the required sum = target sum - value of 'last' element and
   number of elements = total elements - 1
2. Leave the 'last' element and now the required sum = target sum(sum will remain the same as we have not included this element in our subset) and
   number of elements = total elements - 1
Recursive formula for isSubsetSum() problem :
    isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1])
Base Cases:
    isSubsetSum(set, n, sum) = false, if sum > 0 and n == 0 (if there are no elements left in the array and you have not found a suitable subset)
    isSubsetSum(set, n, sum) = true, if sum == 0

Method 2: To solve the problem in Pseudo-polynomial time use the Dynamic programming.
          Time Complexity: O(sum*n), where sum is the target sum and n is the size of array.
          Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
So we will create a 2D array of size (arr.size()+1)*(target+1) of type boolean.
The state DP[i][j] will be true if there exists a subset of elements from A[0..i] with sum value = j.
We will first iterate over all the rows and mark dp[i][0] = true because to achieve a target sum of 0,we always have a subset in every set called the null
or empty set.
We will then iterate over all the columns & mark dp[0][j] = false because if we consider 0 elements,there is no subset possible to achieve target sum = j.
We will iterate over the rest of the array and check :
1. if(arr[i]>j),i.e, if current element has value greater than 'current sum value' we will copy the answer for previous cases. This means that we can
   never include arr[i] in our subset so we will choose the best answer available by excluding this element.
2. if the current sum value is greater than the 'ith' element we will see if any of previous states have already experienced the sum = j OR any previous
   states experienced a value 'j - arr[i]' which will solve our purpose,i.e, we can either exclude the element or include it in the subset and if we are
   including that element we will decrease the current sum by the current value of that element.
The approach for the problem is :
if (arr[i] > j)   DP[i][j] = DP[i-1][j]
else    DP[i][j] = DP[i-1][j] OR DP[i-1][sum - arr[i]]*/

#include<iostream>
using namespace std;

long long int dp[1001][100001];

//Method 1 : Recursion
bool isSubset1(int arr[], int n, int sum){
    //Base case
    if(sum == 0){
        return true;
    }
    if(n == 0 && sum != 0){
        return false;
    }
    //If last element is greater than sum, then ignore it
    if(arr[n-1] > sum){
        return isSubset1(arr, n - 1, sum);
    }
    //else, check if sum can be obtained by any of the following: (a) including the last element (b) excluding the last element
    return isSubset1(arr, n - 1, sum - arr[n-1]) || isSubset1(arr, n - 1, sum);
}

//Method 2 - Bottom Up DP
bool isSubset2(long long int arr[], long long int n, long long int sum){
    //// If sum is 0, then answer is true
    for(long long int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    // If sum is not 0 and set is empty, then answer is false
    for(long long int j = 0; j <= sum; j++){
        dp[0][j] = false;
    }
    // Fill the subset table in bottom up manner
    for(long long int i = 1; i <= n; i++){
        for(long long int j = 1; j <= sum; j++){
            if(arr[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }
            if(j >= arr[i - 1]){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i-1]];
            }
        }
    }
    /* prlong long int table
     for(long long int i = 0; i <= n; i++) {
       for (long long int j = 0; j <= sum; j++)
          cout<<dp[i][j]);
        cout<<endl;
     }*/

    return dp[n][sum];
}

int main(){
    long long int n, sum;
	cin>>n>>sum;
	long long int arr[n];
    for(long long int i = 0; i < n; i++){
		cin>>arr[i];
	}

    if(isSubset2(arr, n, sum)){
        cout<<"Yes"<<endl;;
    }
    else{
        cout<<"No"<<endl;;
    }
    return 0;
}

/* Input :
   5 10
   1 2 3 4 5
   Output :
   Yes
*/

