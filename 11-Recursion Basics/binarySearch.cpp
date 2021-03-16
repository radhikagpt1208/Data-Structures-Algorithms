#include<iostream>
using namespace std;

int binarySearch(int arr[] , int key , int s , int e){
    if(s <= e){
        int mid = (s + e)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            return binarySearch(arr , key , s , mid - 1);
        }
        return binarySearch(arr , key , mid + 1 , e);
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    int key = 5;
    int result = binarySearch(arr , key , 0 , n-1 );
    if(result == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<result;
    }
    return 0;
}
