#include<iostream>
using namespace std;

//function to store the index of the key element in another array and returns count
int storeOcc(int *arr , int n , int  i , int key , int *output , int j){
    //base case
    if(i == n){
        return j;
    }
    //rec case
    if(arr[i] == key){
        output[j] = i; //store the index
        return storeOcc(arr , n , i + 1 , key , output , j+1);
    }

    return storeOcc(arr , n , i + 1 , key , output , j);
}

//function to print the index
void allOcc(int *arr , int n , int i , int key){
    //base case
    if(i == n){
        return;
    }
    //rec case
    if(arr[i] == key){
        cout<<i<<" ";
    }
    allOcc(arr , n , i + 1 , key);
}
int main(){
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 10};
    int n = sizeof(arr)/sizeof(int);
    int key = 7;

    allOcc(arr , n , 0 , key);
    cout<<endl;

    int output[100];
    int cnt = storeOcc(arr ,  n , 0 , key , output , 0);
    cout<<"Count is "<<cnt<<endl;
    //print the output array
    for(int k = 0 ; k < cnt ; k++){
        cout<<output[k]<<" ";
    }
    return 0;
}
