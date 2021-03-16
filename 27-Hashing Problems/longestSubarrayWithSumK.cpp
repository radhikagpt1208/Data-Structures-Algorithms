#include<iostream>
#include<unordered_map>
using namespace std;

/*csum[j] - csum[i] will give the sum of the elements from (i+1,j) in the array
  hence for current sum at index 'j' we will find a sum that occurred before this such that csum[j] - k = csum[i]
  where 'i' is the index before the current index in the csum array
  if at any index i in the cumulative sum array, csum[i] = k,then this sub array which has a sum K will be of the length 0-i*/

int longestSubarrayWithSumK(int arr[], int n, int k){
    //in the hash map,store the sum and the index where it occurred
    unordered_map<int, int> m;

    int pre = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        pre += arr[i];

        if(pre == k){
            maxLen = max(maxLen, i+1);
        }
        if(m.find(pre - k) != m.end()){
            maxLen = max(maxLen, i - m[pre - k]);
        }
        //if the sum is occurring for the first time
        else{
            m[pre] = i;
        }
    }
    return maxLen;
}

int main(){
    int n, k;
    cin>>n>>k;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<longestSubarrayWithSumK(arr, n, k);

    return 0;
}

