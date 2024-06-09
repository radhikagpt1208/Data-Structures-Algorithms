//Given a number N, count the number of set bits in its binary representation.

#include<iostream>
using namespace std;

/*1.Simple Method
Loop through all bits in an integer,check if a bit is set and if it is then increment the set bit count.
This can be done by finding the last bit by n&1, if it comes out to be 1 we increment the count else we discard the last bit and
go to the previous bit and repeat the same until the number left is > 0. You can discard the last bit of N by right shift by 1
Time Complexity : In any number N, you can have at most logN bits because the binary representation goes in powers of 2.
Also, the largest number you can store in long long int is 10^18 and log18 = 64. So, if all bits are set then you will need 64
iterations in the worst case. */
int countSetBits1(int n){
    int cnt = 0;
    while(n > 0){
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

/*2. Brian Kernighan’s Algorithm:
Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1)including the rightmost set bit.
So if we subtract a number by 1 and do bitwise & with itself(n&(n-1)),we basically unset the rightmost set bit.
If we do n&(n-1) in a loop and count the no. of times loop executes we get the set bit count because the loop removes the set
bits from right to left.
Hence,the number of times it loops is equal to the number of set bits in a given integer.
Time complexity : It is ideally O(number of set bits). In the worst case, the no. of set bits can be logN. Hence time complexity
                  is O(logN) */
int countSetBits2(int n){
    int ans = 0;
    while(n > 0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<countSetBits1(n)<<endl;
    cout<<countSetBits2(n)<<endl;
    //3.Directly count set bits using inbuilt function: __builtin_popcount() by avoiding a separate function for counting.
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}

