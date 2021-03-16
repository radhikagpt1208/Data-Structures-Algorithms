/* Problem Statement : Given a 2D screen,location of a pixel in the screen and a color,replace color of the given pixel and all adjacent same
   colored pixels with the given color.
   1. Flood fill is a simple variant of BFS/DFS that can be used to label(color) the various connected components present in a graph
   2. It is generally performed on implicit graphs(2D matrices)
   3. Starting from a particular cell,we call DFS on neighboring cells to color them.Neighbors can be 4(up,down,left,right)or 8(including diagonals)
ALGORITHM:
// A recursive function to replace previous color 'prevC' at  '(x, y)' and all surrounding pixels of (x, y) with new color 'newC' and
   floodFill(screen[M][N], x, y, prevC, newC)
1) If x or y is outside the screen, then return.
2) If color of screen[x][y] is not same as prevC, then return
3) Recur for up,down,left and right
    floodFill(screen, x+1, y, prevC, newC);
    floodFill(screen, x-1, y, prevC, newC);
    floodFill(screen, x, y+1, prevC, newC);
    floodFill(screen, x, y-1, prevC, newC);      */

#include<iostream>
using namespace std;

//these arrays define the positions of i,j for all 4 directions
//W,N,E,S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

//ch is the character to be replaced
//color is the character to be added
void floodFill(char mat[][50], int R, int C, int i, int j, char ch, char color){
    //Base case (matrix boundary)
    if(i < 0 || j < 0 || i >= R || j >= C){
        return;
    }
    //Boundary Condition (figure boundary)
    //in our case character we have to fill is a '.' So if at any point we reach to some other character,we just return back
    if(mat[i][j] != ch){
        return;
    }
    if(mat[i][j] == color){
        return;
    }
    //Recursive Call
    //fill the current cell with the required color
    mat[i][j] = color;
    /* either call recursively for all the directions
    floodFill(mat, i - 1, j, ch, color);
    floodFill(mat, i, j - 1, ch, color);
    floodFill(mat, i + 1, j, ch, color);
    floodFill(mat, i, j + 1, ch, color);
    4 directions : West, North, East,South */
    for(int k = 0; k < 4; k++){
        floodFill(mat, R, C, i + dx[k], j + dy[k], ch, color);
    }
}

void printMatrix(char input[][50], int R, int C){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int R, C;
    cin>>R>>C;

    char input[15][50];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>input[i][j];
        }
    }
    printMatrix(input, R, C);
    floodFill(input, R, C, 8,13, '.', 'r');
    printMatrix(input, R, C);
    return 0;
}
