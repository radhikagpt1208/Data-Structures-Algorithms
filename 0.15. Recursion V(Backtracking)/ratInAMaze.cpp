#include<iostream>
using namespace std;

bool rat_in_a_maze(char maze[10][10], int solution_array[][10], int i, int j, int m, int n){
    //i,j:coordinates of current cell(starting point)
    //m,n:coordinates of the last cell(destination)
    //base case
    //if we reach the last cell,stop
    if(i == m && j == n){
        solution_array[m][n] = 1;
        //print the solution array
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                cout<<solution_array[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;     //true: we have found at least one path
    }
    //rec case
    //Condition 1: Rat should be in the grid
    if(i > m || j > n){
        return false;
    }
    //Condition 2: The cell should not be blocked
    if(maze[i][j] == 'X'){
        return false;
    }
    //assume solution exists from the current cell
    solution_array[i][j] = 1;
    //check if we get a valid path on moving in the right direction(same row but next col)
    bool rightSuccess = rat_in_a_maze(maze, solution_array, i, j + 1, m, n);
    //check if we get a valid path on moving in the downward direction(next row but same col)
    bool downSuccess = rat_in_a_maze(maze, solution_array, i + 1, j, m, n);

    //BACKTRACKING
    //before returning or printing the path,we have to replace 1 with 0 from whichever cell we're going back
    solution_array[i][j] = 0;

    if(rightSuccess || downSuccess){
        return true;            //we have found the path
    }
    return false;
}

int main(){
    //initialize a char 2D array for a maze
    char maze[10][10] = {
                            "0000",
                            "00X0",
                            "000X",
                            "0X00"
                        };
    //initialize a solution array with all the values as 0
    int solution_array[10][10] = {0};
    int m = 4, n = 4;
    bool ans = rat_in_a_maze(maze, solution_array, 0, 0, m-1, n-1);
     //0,0:coordinates of current cell(starting point)
    //m,n: coordinates of the last cell(destination)
    if(ans==false){
        cout<<"Path doesn't exist";
    }
    return 0;
}
