/* You are given two 32-bit numbers,N and M and two bit positions, i and j.
Write a method to set all bits between i and j in N equal to M where i and j are computed from the right
(M becomes a substring of N located at i and starting at j).
Example :
    Input : N = 10000000000 ; M = 10101 ; i = 2 ; j = 6 (in the input, you will be given integers and not binary representations)
    Output: N = 10001010100

Approach :
1. First clear all the bits in the range i to j.
2. Then you basically have to left shift M by i places.
3. Do a bitwise OR of N with the M obtained above.  */

#include<iostream>
using namespace std;

int clear_range_i_to_j(int n, int i, int j){
    int mask_a = (~0) << (j+1);
    int mask_b = (1 << i) - 1;
    int final_mask = mask_a | mask_b;
    int ans = n & final_mask;

    return ans;
}

int replaceBitsinNbyM(int n, int m, int i, int j){
    int cleared_n = clear_range_i_to_j(n, i, j);
    int ans = cleared_n | (m << i);

    return ans;
}

int main(){
    int n = 15;
    int i = 1;
    int j = 3;
    int m = 2;

    cout<<replaceBitsinNbyM(n, m, i, j)<<endl;
    return 0;
}


