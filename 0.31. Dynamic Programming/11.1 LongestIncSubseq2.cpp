/* Approach 2 : Time Complexity : O(N^2)
Let arr[0..n-1] be the input array and dp[i] be the ELEMENT at which the subsequence of length i ends. In Approach 1,'i' represented the index,however here
'i' represents the length of the subsequence.
There may be different elements at which LIS of length i ends. However, we will consider taking the smaller element as explained :
For eg : in the input array : 1 5 2 3 4 9 6 10, there are 2 elements that end at length 5 of the LIS and those elements are 9 and 6,if we consider the LIS to
be 1 2 3 4 9 10 or 1 2 3 4 6 10. In both the LIS, 6 and 9 end at length 5. But we will choose dp[i]=6(smaller element) because on moving further in the input
array, if I get 7 I will be able to include it in the LIS since 6 < 7. However if instead of 6 we would have considered 9, we would not have been able to
include 7 in the subsequence.
Hence,assume that the end element of largest sequence is E. We can add (replace) current element A[i] to the existing sequence if there is an element A[j]
(j > i) such that E < A[i] < A[j] or (E > A[i] < A[j] - for replace)
//Modification to reduce Time Complexity to O(NlogN)
The DP array so formed will always be strictly increasing(if we ignore the base case values), i.e,it will be a monotonic order.
Since it is a monotonic order,it gives an advantage of using binary search over the values to find a position such that dp[pos] < A[i] < dp[pos+1>
To find a suitable position for a particular element, you just have to apply upper bound so that you get an element just greater than it and simply place
the element at the required position.  */

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int lis(int arr[], int n, int dp[]){
    //DP tricky method to understand the modification code
    /*for(int i = 0; i < n; i++){
        //print the initial DP array
        for(int length = 0 ; length <= n; length++){
            cout<<dp[length]<<" ";
        }
        cout<<endl;
        //find a particular suitable position for every element in input array and update it with the given value
        //length of the LIS can vary from 0-n
        for(int length = 0; length < n; length++){
            if(dp[length] < arr[i] && arr[i] < dp[length + 1]){
                dp[length + 1] = arr[i];
            }
        }
        //print the final DP array
        for(int length = 0 ; length <= n; length++){
            cout<<dp[length]<<" ";
        }
        cout<<endl;
    } */
    //Modification
    for(int i = 0; i < n; i++){
        for(int length = 0 ; length <= n; length++){
            cout<<dp[length]<<" ";
        }
        cout<<endl;
        //find an index(index will basically give the length of a subsequence) that will give the upper bound to place the
        //element at a suitable position.
        int index = upper_bound(dp, dp + n + 1, arr[i]) - dp;
        //update the index
        if(dp[index - 1] < arr[i] && arr[i] < dp[index]){
            dp[index] = arr[i];
        }
    }
    for(int length = 0 ; length <= n; length++){
            cout<<dp[length]<<" ";
        }
        cout<<endl;

    int lis = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] != INT_MAX)
            lis = i;
    }
    return lis;
}

int main(){
    int arr[] = {2, 3, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(int);

    int dp[n + 1];
    //initialize the DP array with infinity except at 0th index(because the min length of an inc subsequence will at least be 1 at)
    dp[0] = INT_MIN;
    for(int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
    }
    cout<<"Longest Increasing Subsequence : "<<lis(arr, n, dp);
    return 0;
}
