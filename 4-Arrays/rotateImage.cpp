#include<iostream>
using namespace std;

void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void rotateArray(int arr[][1000], int n){
    for(int i=0; i<n; i++){
        int start=0;
        int e=n-1;
        while(start<e){
            swap(arr[i][start],arr[i][e]);
            start++;
            e--;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[1000][1000];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    rotateArray(arr, n);
    return 0;
}



