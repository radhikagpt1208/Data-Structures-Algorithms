/*
Problem : Given an array, the task is to calculate the sum of lengths of contiguous sub arrays having all elements distinct.
Approach :
1. Starting from the first element,find the max length sub array with unique elements(starting from index i up to an index j)
2. After getting the largest sub array starting from the first element which has all distinct elements,count the sum of lengths
   of all such sub arrays in the range arr[i....j] (starting from index i)with all unique elements by using the
   formula : ((j-i+1)*(j-i+2))/2
3. To find the next sub array of distinct elements, increment starting point, i and ending point,j unless (i+1,j) are distinct.
   If not possible, then we increment i again and move forward the same way.
4. Hence to do this,prepare a map to keep a check how many elements are unique and then iterate over the whole array one by one
   and keep a pointer j that initially will be 0 and for every element we will iterate with index i, we will find an index j such
   that j < n and the element that we find at j is not present in the map(no repetition).When we are finding all such elements
   that are not in the map, we will insert them and increment j.
   Whenever we finally get the max index j for which the subarray starting from i at a particular  index has all the elements
   unique, increment ans by ((j-i+1)*(j-i+2))/2 and erase element at ith index from the map because we have done the work for
   a particular index i as we have calculated sum of lengths of all unique element sub arrays starting from i.
*/

#include<iostream>
#include<unordered_set>
using namespace std;

int sumOfLenOfAllSubarrays(int arr[], int n){
     unordered_set<int> s;
     int j = 0, ans = 0;
     // Fix starting point
     for(int i = 0; i < n; i++){
        // Find ending point for current sub array with distinct elements
        while(j < n && s.find(arr[j]) == s.end()){
            s.insert(arr[j]);
            j++;
        }
        // Calculating and adding all possible length sub arrays in arr[i..j]
        ans += ((j - i)*(j - i + 1)) / 2;
        // Remove arr[i] as we pick new stating point from next
        s.erase(arr[i]);
     }
     return ans;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<sumOfLenOfAllSubarrays(arr, n);
    return 0;
}

