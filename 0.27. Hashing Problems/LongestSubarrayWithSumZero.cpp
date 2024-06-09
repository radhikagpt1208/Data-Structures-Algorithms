/*After making the prefix sum array,calculate the length of the sub arrays which have sum = 0.Such sub arrays will occur when:
  1. The value of sum is zero in the prefix array.
     Length of such a sub array will be (i + 1) where i:index where zero occurred in the prefix sum array
  2. When there is a repeated value of sum in the prefix array.
     Length = (j - i) where j:index of second occurrence of the repeated value of sum
                            i:index of first occurrence of the repeated value of sum in the prefix sum array */

#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarrayWith0Sum(int arr[], int n){
    //in the unordered map,store the value of sum and at what index the sum appeared
    //if the sum is repeating,store the first occurrence of the sum and find the length of the sub array formed
    //when you find another occurrence of the same sum by using (j - i) and update the value of maxLen when required.
    unordered_map<int, int> m;

    int pre = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        pre += arr[i];

        if(pre == 0){
            maxLen = max(maxLen, i+1);
        }
        //repeated sum,length=current index of the repeated sum - first occurrence of the pre sum
        if(m.find(pre) != m.end()){
            maxLen = max(maxLen, i - m[pre]);
        }
        //if the sum is occurring for the first time
        else{
            m[pre] = i;
        }
    }
    return maxLen;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<longestSubarrayWith0Sum(arr, n);

    return 0;
}
