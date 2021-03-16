#include<iostream>
using namespace std;

bool isSorted(int *arr , int n){
    //base case
    //if the size of array is 0 or 1,it will be sorted
    if(n == 0 || n == 1){
        return true;
    }

    //recursive call
    if(arr[0] < arr[1] && isSorted(arr + 1 , n - 1)){
        return true;
    }
    return false;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    cout<<isSorted(arr , n);
    return 0;
}
