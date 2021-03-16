#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;

    int i = 0;
    int j = n-1;
    while(i<n && j>=0)
    {
        if(arr[i][j] < key){
            i++;
        }
        else if(arr[i][j] > key){
            j--;
        }
        else if(arr[i][j]==key){
            cout<<i+1<<" "<<j+1;
            break;
        }
    }
    return 0;
}


