#include<iostream>
using namespace std;

int firstOcc(int * arr , int n , int key){
    //base case
    if(n == 0){
        return -1;
    }
    //rec case
    if(arr[0] == key){
        return 0;
    }
    int i = firstOcc(arr + 1 , n - 1 , key);
    if(i == -1){
        return -1;
    }
    return i + 1;
}

//another way using linear search,i.e,equivalent to a for loop
int linearSearch(int *arr , int i , int n , int key){
    //base case
    if(i == n){
        return -1;
    }

    //rec case
    if(arr[i] == key){
        return i;
    }

    return linearSearch(arr , i + 1 , n , key);
}

int main(){
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int n = sizeof(arr)/sizeof(int);
    int key = 7;
    cout<<firstOcc(arr , n , key)<<endl;
    cout<<linearSearch(arr , 0 , n , key);

    return 0;
}
