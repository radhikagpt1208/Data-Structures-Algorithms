/* Problem : There are n white and black dots which are equally spaced in a line. You want to connect each white dot with some
   black dot such that the length of wire required is minimum.
   In the input, you are given array that contains the coordinates(position)of white and black dots.Find the length of wire needed.
   Approach :
   For each white dot,find the nearest black dot. Hence connect white dots with the nearest black dots.
   To do this, first sort both the arrays and then connect the ith white dot in the first array with the ith black dot in the
   second array and then subtract the coordinates joined to get the minimum length and finally add all the lengths.
*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int white[] = {3, 4, 1};
    int black[] = {2, 5, 6};
    int n = sizeof(white)/sizeof(white[0]);

    //sort the arrays
    sort(white, white + n);    // 1,3,4
    sort(black, black + n);    // 2,5,6

    int total_len = 0;
    for(int i = 0; i < n; i++){
        int len = abs(white[i] - black[i]);
        total_len += len;
    }

    cout<<"Minimum length of wire required is : "<<total_len;
    return 0;
}
