#include<iostream>
using namespace std;

void merge_array(int *arr , int s , int e){
    int mid = (s + e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];
    while(i <= mid && j <=e){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    //if any element is left in any of the array,directly copy them in the temp array
    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= e){
        temp[k] = arr[j];
        k++;
        j++;
    }

    //copy the temp array to the original array
    for(int i = s ; i <= e ; i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr , int s ,int e){
    //base case:in case of 1 or 0 elements
    if(s>=e){
        return;
    }
    //otherwise,follow 3 steps
    //divide the array about the mid point
    int mid = (s + e)/2;
    //recursively sort the two arrays
    mergeSort(arr , s , mid);
    mergeSort(arr , mid + 1 , e);

    //merge the two sorted arrays
    merge_array(arr , s , e);
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    mergeSort(arr , 0 , n-1);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
