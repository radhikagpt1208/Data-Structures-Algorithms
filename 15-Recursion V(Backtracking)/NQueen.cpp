#include<iostream>
using namespace std;

bool isSafe(int board[][10] , int i , int j , int n){
    //check for column
    for(int row = 0 ; row < i ; row++){
        //check if a queen already exists in that column
        if(board[row][j] == 1){
            return false;
        }
    }

    //check for left diagonal
    int x = i;
    int y = j;
    //check if a queen already exists in the upper left diagonal
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        //go on the previous row and previous col
        x--;
        y--;
    }

    //check for right diagonal
    x = i;
    y = j;
    //check if a queen already exists in the upper right diagonal
    while(x >= 0 && y < n){
        if(board[x][y] == 1){
            return false;
        }
        //go on the previous row and next col
        x--;
        y++;
    }

    //if none of the above return false, hence the (i,j) pos is safe
    return true;
}

bool solveNQueen(int board[][10] , int i , int n){
    //base case
    if(i == n){
        //you have successfully places n queens in n rows(0-n-1)
        //print the board
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        //to get one possible configuration
        //return true;
        cout<<endl<<endl;
        //to get all possible configurations,return false so that it keeps in checking further
        return false;
    }

    //rec case
    //try to place the queen in the current row and call the func for the remaining rows which will be solved by recursion
    //iterate over all the columns
    for(int j = 0 ; j < n ; j++){
        //check if if (i,j) position is safe to place the queen
        //i.e,there should be no queen in the upper left or upper right diagonal and and in the same column above it
        //no need to check for lower diagonals as we're going row wise
        if(isSafe(board, i , j , n)){
            //place the queen assuming i,j is the right position
            board[i][j] = 1;

            //to check for the rest of the queen in the further rows
            bool nextQueen = solveNQueen(board , i + 1 , n);
            if(nextQueen){
                return true;
            }

            //if there is no suitable place left for the next queen
            //i.e,(i,j) is not the right place and the assumption is wrong
            //BACKTRACKING
            //remove the queen above this row,and check for the next col
            board[i][j] = 0;
        }
    }

    //no suitable positions found in the current row
    return false;
}

int main(){
    int n;
    cin>>n;
    //take a board of 10X10 and initialize it with 0
    int board[10][10] = {0};

    solveNQueen(board , 0 , n);
    return 0;
}
