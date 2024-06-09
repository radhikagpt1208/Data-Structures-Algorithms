#include<iostream>
using namespace std;

void spiralPrint(int arr[][1000] , int m , int n){
    int startRow=0;
    int endRow=m-1;
    int startColumn=0;
    int endColumn=n-1;

    while(startRow <= endRow && startColumn <= endColumn){
        //First Row
        for(int i = startColumn ; i <= endColumn ; i++){
            cout<<arr[startRow][i]<<" ";
        }
        startRow++;

        //Last Column
        for(int i = startRow ; i <= endRow ; i++){
            cout<<arr[i][endColumn]<<" ";
        }
        endColumn--;

        //Last Row
        if(startRow < endRow){
            for(int i = endColumn ; i >= startColumn ; i--){
            cout<<arr[endRow][i]<<" ";
            }
            endRow--;
        }

        //Start Column
        if (endColumn > startColumn) {
            for(int i = endRow ; i >= startRow ; i--){
                cout<<arr[i][startColumn]<<" ";
            }
            startColumn++;
        }

    }
}

int main(){
    int m , n;
    cin>>m>>n;
    int arr[1000][1000];
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>arr[i][j];
        }
    }

    spiralPrint(arr,m,n);

    return 0;
}
