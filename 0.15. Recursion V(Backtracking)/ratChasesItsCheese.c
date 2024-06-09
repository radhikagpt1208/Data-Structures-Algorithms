#include<iostream>
using namespace std;

//rat can move in any of the 4 directions

bool rat_in_a_maze(char maze[][10], int solution_array[][10], int i, int j, int m, int n){
    if(i == m && j == n){
        solution_array[m][n] = 1;

        //print the solution array
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                cout<<solution_array[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //rec case
    //Condition 1: Rat should be in the grid
    if(i > m || j > n || i < 0 || j < 0){
        return false;
    }
    //Condition 2: The cell should not be blocked
    if(maze[i][j] == 'X'){
        return false;
    }
    //assume solution exists from the current cell
    solution_array[i][j] = 1;

    bool right , down , up , left;
    //if 1 already exixts,you can't go in that direction
    if(solution_array[i][j+1] == 0){
        right = rat_in_a_maze(maze, solution_array, i, j + 1, m, n);
        if (right) return true;
    }

    if(solution_array[i+1][j] == 0){
        down = rat_in_a_maze(maze, solution_array, i + 1, j, m, n);
        if (down) return true;
	}

    if(solution_array[i][j-1] == 0){
        left = rat_in_a_maze(maze, solution_array, i , j - 1, m, n);
        if (left) return true;
	}

    if(solution_array[i-1][j] == 0){
        up = rat_in_a_maze(maze, solution_array, i - 1, j, m, n);
		if (up) return true;
    }

    //BACKTRACKING
    //before returning or printing the path,we have to replace 1 with 0 from whichever cell we're going back
    solution_array[i][j] = 0;
    return false;
}

int main(){
    int m,n;
	cin>>m>>n;
	char maze[10][10];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>maze[i][j];
		}
	}
    //initialize a solution array with all the values as 0
    int solution_array[10][10] = {0};

    bool ans = rat_in_a_maze(maze, solution_array, 0, 0, m-1, n-1);

    if(ans == false){
        cout<<"NO PATH FOUND";
    }
    return 0;
}
