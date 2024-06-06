/* Given an array of size n with 0s and 1s,flip at most k 0s to get the longest possible sub array of 1s.
We can solve this problem using two pointers technique. We take 2 pointers say, l and r and we maintain 2 variables for storing the count of 0s and the
maximum length of the current sub array say, zero_count and max_length.
We keep both the pointers l and r at 0th index of the array. We start iterating over the whole array with pointer r and whenever we encounter 0, we will
increment the zero_count and simultaneously update the max_length. If the zero_count becomes greater than k, we will start incrementing the pointer l till
zero_count > k and if we encounter a 0 we will first decrement the zero_count and then increment the l pointer. Also we will keep updating the max_length
by using the formula : (r - l + 1)
*/

#include<iostream>
using namespace std;

int maxSubarray(int arr[], int n, int k){
    int l = 0, r = 0;
    int zero_count = 0;
    int max_len = 0, best_len = 0;

    for(int r = 0; r < n; r++){
        if(arr[r] == 1){
            if(max_len < r-l+1){
                max_len = r-l+1;
                best_len = l;
            }
	    continue;
	}
        else if(arr[r] == 0){
            zero_count++;
            while(zero_count > k){
                if(arr[l] == 0){
                    zero_count--;
                }
                //increment the left pointer
                l++;
            }
        }
       if(max_len < r-l+1){
            max_len=r-l+1;
            best_len=l;
        }
    }
   // cout<<"l = "<<l<<" r =  "<<r<<endl;
   //to modfiy 0 to 1
   for(int i = best_len; i < best_len + max_len; i++){
        arr[i] = 1;
    }
    return max_len;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<maxSubarray(arr, n, k)<<endl;
    //print the modified array
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
