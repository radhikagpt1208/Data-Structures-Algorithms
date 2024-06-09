/* Given an unsorted array of integers, sort the array into a wave like array.
An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >=...
Brute Force : Sort all the elements of the array and then swap the elements in pairs,i.e, alternatively to get a wave like array.
Time Complexity : O(nLogn)
Efficient Approach: This can be done in O(n) time by doing a single traversal of given array. The idea is based on the fact that
if we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their adjacent odd elements, we don’t
need to worry about odd positioned element. Following are simple steps.
1) Traverse all even positioned elements of input array, and do following.
….a) If current element is smaller than previous odd element, swap previous and current.
….b) If current element is smaller than next odd element, swap next and current.
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    //wave sort
    for(int i = 0; i < n; i += 2){
        //check for 2 comparisons
        //if the current element is smaller than the previous element and the next element,swap
        if(i != 0 && arr[i] < arr[i-1]){
            swap(arr[i] , arr[i-1]);
        }
        if(i != (n-1) && arr[i] < arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
