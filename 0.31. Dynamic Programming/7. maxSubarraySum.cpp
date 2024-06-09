#include<iostream>
using namespace std;

//Bottom Up DP (Linear Time)
int maxSubarraySum(int arr[], int n){
    int dp[100] = {0};
    //0th element of the dp array = 0th element of the given array only if it is greater than zero
    dp[0] = arr[0] > 0 ? arr[0] : 0;

    int max_so_far = dp[0];
    for(int i = 1; i < n; i++){
        //add the current element to the previous sum
        dp[i] = dp[i - 1] + arr[i];
        //if on including the next element we get a negative sum we will not include it by making its value in the DP array as zero
        //if the element itself is negative, it is not necessary it will reduce the sub array sum because it is possible that there are large positive
        //numbers  ahead of this element that can increase the sum . Hence, we will only exclude the element if it makes the sum negative, no matter if
        //the element itself is negative.
        if(dp[i] < 0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}

//Space Optimized Approach :Since the answer for the current state depends only on the previous state, there is no need to store answers for all the states.
//Only the maximum sum so far is required, so we just have to store one variable instead of the entire array. Hence space complexity : O(1)
int maxSum(int arr[], int n){
    int current_sum = 0;
    int max_so_far = 0;

    for(int i = 0; i < n; i++){
        current_sum += arr[i];
        if(current_sum < 0){
            current_sum = 0;
        }
        max_so_far = max(max_so_far, current_sum);
    }
    return max_so_far;
}

/* int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];

         int dp[1000001] = {0};
        dp[0] = nums[0];
         int max_so_far = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = max( nums[i], dp[i-1]+nums[i] );
            max_so_far = max(max_so_far, dp[i]);
        }
        return max_so_far;
    }
*/

//Special Case : If all elements are negative, the sum will be zero but it might be possible that we have to output the smallest negative element
//because you need at least one element in the sub array.

int main(){
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr)/sizeof(int);

    cout<<maxSubarraySum(arr, n)<<endl;
    cout<<maxSum(arr, n)<<endl;
    //max sum will be 20 if we take elements in the sub array from 2 to 7.
    return 0;
}
