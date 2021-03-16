#include<iostream>
using namespace std;

int main(){
    int rows;
    cin>>rows;

    //loop for rows
    for(int i = 1 ; i <= rows ; i++){

        //loop for spaces
        for(int space = 1 ; space <= rows-i ; space++){
            cout<<" ";
        }

        //loop to print increasing numbers
        int val = i;
        for(int j = 1 ; j <= i ; j++ ){
            cout<<val;
            val++;
        }

        //loop for decreasing numbers
        val = val-2;
        for(int k = 1 ; k <= i-1; k++){
            cout<<val;
            val--;
        }

        cout<<"\n";
    }
    return 0;
}
