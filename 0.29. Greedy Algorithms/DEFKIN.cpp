/* Problem Statement : DEFKIN - Defense of a Kingdom
Theodore implements a new strategy game "Defense of a Kingdom" .
On each level a player defends the Kingdom that is represented by a rectangular grid of cells.
The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column.
No two towers share a row or a column.The penalty of the position is the number of cells in the largest undefended rectangle.
Help Theodore write a program that calculates the penalty of the given position.
Input :
The first line of the input file contains the number of test cases.
Each test case consists of a line with three integer numbers:w-width of the grid,h-height of the grid,n-number of crossbow towers
(1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi - the coordinates of the cell occupied by a tower
(1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
Output :
For each test case, output a single integer number-the number of cells in the largest rectangle that is not defended by the towers.

Approach : Any area that lies between 2 towers is the undefended area. You should know the distance of the 1st tower from the start,
the subsequent distances between all the towers and the distance of the last tower from the end as well.
Hence we can find the x and y coordinates of the undefended areas.For eg:if the x-coordinate of 1st tower is 3 and that of the 2nd
tower is 8,then for 1st tower,we will get delta x(width of undefended area)as(3-0-1 = 2)and that for the 2nd tower will be(8-3-1=4)
(We subtract 1 because we know that the column and the row at which the tower is kept, is already defended)
Hence one value of delta x is 2 and 4 and  and we will keep doing this for all towers for both x and y coordinates and then pick
up max delta x and delta y to get max no of cells.

Algorithm :
1. Given w, h as width and height of the playing field,and the coordinates of the towers as (x1,y1) ... (xN,yN),split the
   coordinates into two lists x1...xN, y1...yN, sort both of those coordinate lists.
2. Then calculate the empty spaces, e.g. dx[] = { x1, x2-x1, ..., xN - xN-1,(w + 1) - xN }.
   Do the same for the y coordinates: dy[] = { y1, y2-y1,..., yN - yN-1, (h + 1) - yN }.
   Multiply max(dx)-1 by max(dy)-1 and you should have the largest uncovered rectangle. You have to decrement the delta values
   by one because the line covered by the higher coordinate tower is included in it, but it is not uncovered. */

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t, height, width, n;
    cin>>t;
    int x[40010], y[40010];
    while(t--){
        cin>>width>>height>>n;
        for(int i = 0; i < n; i++){
            cin>>x[i]>>y[i];
        }
        sort(x, x + n);
        sort(y, y + n);

        int dx = x[0] - 1;     //initial value of dx
        int dy = y[0] - 1;     //initial value of dy

        for(int i = 1; i < n; i++){
            dx = max(dx, x[i] - x[i - 1] - 1);
            dy = max(dy, y[i] - y[i - 1] - 1);
        }

        //consider corner case (from last tower to end of grid)
        dx = max(dx, width - x[n - 1]);
        dy = max(dy, height - y[n - 1]);

        cout<<dx*dy<<endl;
    }

    return 0;
}
