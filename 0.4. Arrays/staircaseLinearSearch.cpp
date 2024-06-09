#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i , j;
    int arr[n][n];
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i][j] == key){
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    return 0;
}

