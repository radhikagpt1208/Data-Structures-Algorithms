//Dutch national flag problem :
//To sort an array of 0s, 1s and 2s in a single pass iteration. Swaps the array inplace with O(N) time complexity.

#include<iostream>
using namespace std;

void DNF_sort(int arr[] , int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++ ;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid] , arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    DNF_sort(arr, n);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
