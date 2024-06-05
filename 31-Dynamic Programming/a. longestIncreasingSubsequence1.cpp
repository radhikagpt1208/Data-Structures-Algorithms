/* The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the
subsequence are sorted in increasing order.

Approach 1 : Using DP , Time Complexity : O(N^2)
Let arr[0..n-1] be the input array and dp[i] be the length of the longest inc subseq ending at index i such that arr[i] is the last element of the LIS.
dp[i] represents what is the length of the subsequence of which arr[i] is a part of.
Then, dp[i] can be recursively written as:
    dp[i]= 1 + max( dp[j] ) where 0 < j < i and arr[j] < arr[i]; or dp[i]= 1, if no such j exists
To find the LIS for a given array, we need to return max(dp[i]) where 0 < i < n.
That is, for every element(arr[i]) we find all the elements less than this current element that also lies before this current element in the input array,i.e,
to the left of this current element so that we finally choose that element which has the maximum ending so that when we include the current element to
that element, we get the max length subsequence. */

#include<iostream>
using namespace std;

int lis(int arr[], int n, int dp[]){
    //Base Case
    if(n == 1){
        return 1;
    }
    //there is no element before the 0th element, hence the 0th element will have the LIS as 1(which will have 0th element only)
    dp[0] = 1;
    //for every element, find the LIS
    for(int i = 0; i < n; i++){
        //every element can end at length 1(it can have only one element in the subsequence,i.e, itself in the worst case)
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    //you have made the DP array,choose the LIS
    int lis = 0;
    for(int i = 0; i < n; i++){
        lis = max(lis, dp[i]);
    }
    //print the DP array
    for(int i = 0; i < n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return lis;
}

int main(){
    int arr[] = {1, 5, 2, 3, 4, 9, 6, 10};
    int n = sizeof(arr)/sizeof(int);

    int dp[n];
    //LIS is of length 6 : 1,2,3,4,9,10 OR 1,2,3,4,6,10
    cout<<lis(arr, n, dp)<<endl;

    return 0;
}
