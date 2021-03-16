/* PROBLEM STATEMENT:
 Given an array arr[] of N distinct integers points on the 2D Plane. The task is to count the number of Right-Angled Triangle
 from N points such that the base or perpendicular is parallel to the X or Y-axis.
 Approach :
 The idea is to store the count of each co-ordinates having the same X and Y co-ordinates respectively in a map that stores the
 value of x (or y co-ordinate) and the count of the coordinates that have the same value as that of the x(or y coordinate)
 Now traverse each given points and the count of a right-angled triangle formed by each coordinate (X, Y) is given by:
 (n1-1)C(1) * (n2-1)C(1) where n1 is the count of the coordinates that have the same value of x-coordinate
                               n2 is the count of the coordinates that have the same value of y-coordinate
REASON: if we consider a coordinate (x,y) then we will have to choose 1 coordinate out of (n1-1) coordinates and
        1 coordinate out of (n2-1) coordinates to make a complete right angled triangle
Hence, Count of right-angled triangles = (frequencies of X coordinates - 1) * (frequencies of Y coordinates - 1)
                                       = (n1 - 1) * (n2 - 1)  */

#include<iostream>
#include<unordered_map>
using namespace std;

int countTriangles(int arr[][2], int n){
    /*Create 2 maps to store count of points,one for having the same X-coordinate and another for having the same Y-coordinate */
    unordered_map<int, int> x;
    unordered_map<int, int> y;

    for(int i = 0; i < n; i++){
        x[arr[i][0]]++;
        y[arr[i][1]]++;
    }

    int cnt = 0;
    /* Iterate to check for total number of possible triangle */
    for(int i = 0; i < n; i++){
         if(x[arr[i][0]] >= 1 && y[arr[i][1]] >= 1) {
            cnt += (x[arr[i][0]] - 1) * (y[arr[i][1]] - 1);
         }
    }
    return cnt;
}

int main(){
    int n = 7;
    int arr[][2] = { { 1, 2 },
                     { 2, 1 },
                     { 2, 2 },
                     { 2, 3 },
                     { 3, 2 },
                     { 1, 4 },
                     { 3, 1 }
                   };

    cout<<countTriangles(arr, n)<<endl;
    return 0;
}
