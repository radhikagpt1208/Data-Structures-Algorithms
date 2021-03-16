#include<iostream>
using namespace std;

//Common Bit Tasks

//1. check if a given number is even or odd
//This can be done by using bitwise operators. If the last bit of th number is 1, it is an odd number and vice versa.
//Hence, for a number n you do bitwise & with 1 and if you get 1,it is odd and vice versa.
bool isOdd(int n){
    return (n & 1);
}

/*2.Given a number n and i(1<= i<= 32),find the value of i-th bit in the binary representation of n.
Bits are numbered from right (Least Significant Bit) to left (Most Significant Bit) (0 based indexing)
Approach:
1)Create a mask,i.e,find a number with all 0s except at the i-th position. We get this number by(1<<i).
2)Do bitwise & of above-obtained number with n. If the number so obtained is > 1,i-th bit in n is set and vice versa. */
int getBit(int n, int i){
    int mask = (1<<i);
    int bit = (n & mask) > 0 ? 1 : 0;

    return bit;
}

/*Given a number n and a value i(from the right)set the i-th bit in the binary representation of n.
Approach :
1.To set any bit we use bitwise OR | operator.
2.Create a mask as above.
3.Since bitwise OR | operator evaluates each bit of the result to 1 if any of the operand's corresponding bit is set(1).
4.Do bitwise OR of the mask created with n and you will get the required result. */
int setBit(int n, int i){
    int mask = (1<<i);
    int ans = (n | mask);

    return ans;
}

/*Clearing a bit means that if i-th bit is 1,then clear it to 0 and if it is 0 then leave it unchanged.
Eg : Clearing the 2nd bit in 5, will give you the answer as 1.
Approach :
1. Create a mask with all 1's except at the i-th position,i.e,only the i-th position will be 0 and the rest will be 1.
2. This mask can be created by first creating a number with all 0's except at the i-th position and then negating this number.
3. Do bitwise & of the mask with n to get the required result.
(passing n with reference so that it gets updated) */
void clearBit(int &n, int i){
    int mask = ~(1 << i);
    n = (n & mask);
}

/*Given a number n,a position i and a binary value v,update the bit at i-th position in 'n' to value v.
Approach :
1. First clear the i-th bit(make it 0) and then create a mask with the i-th bit as v and all the rest as 0's which can be done
   by v<<i.
2. Do a bitwise OR to get the updated answer.
*/
void updateBit(int &n, int i, int v){
    int mask = ~(1<<i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);
}

/* Given a number n and a position i,clear all the last i bits from the right.
So for this we have to create a mask such that we have 1 at those positions which are to be retained and 0 at those positions
which are to be cleared.
To do this, we can start with all 1's(i.e, a 32 bit number with all 1s).
This can be either done by taking ~0 or taking the starting number as -1 (-1 in 2's complement form is stored as a collection of
all 1s)
Now we can create the mask by doing (starting number)11111111111111 << i
Do a bitwise & of the number n with the mask to get the required answer. */
int clear_last_i_bits(int n, int i){
    int starting_number = ~0;
    int mask = starting_number << i;
    int ans = n & mask;

    return ans;
}

/* Given a number n and a positions i and j,clear the range of bits from i to j
1.So for this we have to create a mask such that we have 1 at those positions which are to be retained and 0 at those positions
which are to be cleared.
2.To create this mask,let us split into 2 parts : left and right part of the mask
3.Mask a : We first create a mask that has all 0s starting from j-th position till 0th position and the rest as 1s.
  This can be done by taking the starting number as all 1s and then do left shift j+1 times.
4.Mask b : We then create another mask that has all 1s starting from (i+1)th position till 0 and the rest 0s.
  This can be done by using 2^i - 1 = (1<<i) - 1 and you will get (i+1) 1s on the right.
5.Do a bitwise OR on both the above masks to get the final mask.
6.Do a bitwise & of n with the mask obtained to get the result. */
int clear_range_i_to_j(int n, int i, int j){
    int mask_a = (~0) << (j+1);
    int mask_b = (1 << i) - 1;
    int final_mask = mask_a | mask_b;
    int ans = n & final_mask;

    return ans;
}

int main(){
    int n = 5;
    int i;
    cin>>i;

    if(isOdd(n)){
        cout<<"Odd number"<<endl;
    }
    else{
        cout<<"Even number"<<endl;
    }
    cout<<i<<"-th bit is "<<getBit(n, i)<<endl;

    int result = setBit(n, i);
    cout<<"After setting "<<i<<"-th bit : "<<result<<endl;

    clearBit(n, i);
    cout<<"After clearing "<<i<<"-th bit : "<<n<<endl;

    //update the 2th bit in 5 with a value 0 and 3rd bit with a value 1
    updateBit(n, 2, 0);
    updateBit(n, 3, 1);
    cout<<"After updating the number : "<<n<<endl;

    //clear last i bits
    int num = 15;
    int x = 3;    //x is the number of bits to be cleared and not the position
    cout<<"After clearing last "<<i<<" bits : "<<clear_last_i_bits(num, x)<<endl;

    int number = 31;
    int y = 1;
    int z = 3;
    cout<<"After clearing bits in the range "<<y<<" to "<<z<<" : "<<clear_range_i_to_j(number, y, z)<<endl;

    return 0;
}
