#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int matrix[][9] , int i , int j , int n , int number){
    //check if the number already exists in the row or in the col
    for(int x = 0 ; x < n ; x++){
        if(matrix[x][j] == number || matrix[i][x] == number){
            return false;
        }
    }

    //check if the number already exists in the sub-grid,where every sub-grid is of size (root(n) * root(n))
    int subgrid_size = sqrt(n);
    //start point of a sub-grid
    int sx = (i/subgrid_size) * subgrid_size;
    int sy = (j/subgrid_size) * subgrid_size;

    for(int x = sx ; x < sx + subgrid_size ; x++){
        for(int y = sy ; y < sy + subgrid_size ; y++){
            if(matrix[x][y] == number){
                return false;
            }
        }
    }
    //if none of the above return false
    return true;
}

bool solveSudoku(int matrix[][9] , int i , int j , int n){
    //base case
    if(i == n){
        //print the matrix
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //when the row ends,you have to go to the next row
    if(j == n){
        return solveSudoku(matrix , i + 1 , 0 , n);
    }
    //skip the pre-filled cells
    if(matrix[i][j] != 0){
        return solveSudoku(matrix , i , j + 1 , n);
    }
    //rec case
    //fill the current cell with possible options,i.e,from 1-n
    for(int number = 1; number <= n ; number++){
        if(canPlace(matrix , i , j , n , number)){
            //assume that on placing this number,sudoku will be solved
            matrix[i][j] = number;

            //check for the next empty call
            bool next = solveSudoku(matrix , i , j + 1 , n);
            if(next){
                return true;
            }
        }
    }
    //if the sudoku doesn't get solved,we will have to backtrack
    matrix[i][j] = 0;
    return false;
}

int main()
{
    // 0 means unassigned cells
    int matrix[9][9] =
        {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        };

    solveSudoku(matrix , 0 , 0 , 9);
    return 0;
}
