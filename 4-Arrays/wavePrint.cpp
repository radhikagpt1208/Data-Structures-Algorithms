#include <iostream>
using namespace std;

int main()
{
    int rows,cols;
    cin>>rows>>cols;
    int arr[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
        }
    }

    for(int j=0; j<cols; j++){
        if(j%2==0)
        {
            for(int i=0; i<rows;i++){
            cout<<arr[i][j]<<",";
            }
        }
        else{
            for(int i=rows-1; i>=0; i--){
                cout<<arr[i][j]<<",";
            }
        }
    }
    cout<<"END";

    return 0;
}
