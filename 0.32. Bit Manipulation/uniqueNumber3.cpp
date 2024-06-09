/* We are given an array containing n numbers. All the numbers are present thrice except for one number which is only present once.
Find the unique number. Only use - bitwise operators, and no extra space.
Approach : In this case,we have to find a way to cancel out bits of those numbers that are getting repeated(can't be done using XOR)
So, if we find the sum of all the bits at every bit position of the given numbers, the sum will always be pf the from 3N or 3N+1 where N
is the bit position we are currently at(starting from 0 at the left).This is because if a no. is repeating thrice then its bits will also
repeat thrice and the sum will be 3N and if the unique no. also has a set bit at that bit position, the sum will be 3N+1.
So we can store the sum of all bit positions in an array(in the worst case we will have 64-bit positions).
Now take modulus of 3 with all the sum values stored in the array because by taking modulus we will eliminate the contribution of bits for
those nos. which are occurring 3N times and you will get only at those positions where you have set bits in the unique no.
The bits for which sum is not multiple of 3, are the bits of number with single occurrence.
After taking modulus, you can convert it into decimal to get the unique number. */

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //array of fixed size, hence O(1) space.
    int sum[64] = {0};
    //while storing the sum,we will store it in the reverse order,i.e,the sum of bits at the 0th bit position(from the right)will be stored
    //at the 0th index in the array and so on
    int num;
    for(int i =0; i < n; i++){
        cin>>num;
        //update sum array by extracting bits
        int j = 0;   //j denotes that for a number we will extract a bit and store the sum at the j-th index in the array.
        while(num > 0){
            int last_bit = (num & 1);
            sum[j] += last_bit;
            j++;    //increment j to store the sum of the next bit position
            num = num >> 1;   //to get the last bit in the remaining 'num'
        }
    }
    //iterate over the sum array(which in the worst case can have 64 bits)and take modulus with 3,then convert all 0s & 1s in a decimal no.
    int power = 1;    //since 2^0 = 1 (for decimal conversion)
    int ans = 0;
    for(int i = 0; i < 64; i++){
        sum[i] = sum[i] % 3;


        ans += (sum[i] * power);
        power = power<<1;   //to increase the power by a factor of 2
    }

    cout<<ans<<endl;

    return 0;
}

