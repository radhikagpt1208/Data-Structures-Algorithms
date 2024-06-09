/* We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.
Approach :
A simple solution is to generate all pairs, find their XOR values and finally return the maximum XOR value.
An efficient solution is to consider pattern of binary values from L to R.
We can see that first bit from L to R either changes from 0 to 1 or it stays 1 i.e. if we take the XOR of any two numbers for
maximum value their first bit will be fixed which will be same as first bit of XOR of L and R itself.
After observing the technique to get first bit, we can see that if we XOR L and R, the most significant bit of this XOR will tell
us the maximum value we can achieve i.e. let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get is
1111 because from L to R we have all possible combination of xxx and it is always possible to choose these bits in such a way from
two numbers such that their XOR becomes all 1. */

#include <iostream>
#include<algorithm>
using namespace std;

int max_xor(int x, int y){
    int maxxor = 0;
    for(int i = x; i <= y; i++){
        for(int j = x + 1; j <= y; j++){
          maxxor = max(maxxor , i ^ j);
        }
    }
    return maxxor;
}

int maxXOR(int x, int y) {
    //get xor of limits
    int x_XOR_y = x ^ y;

    //loop to get most significant bit position of x^y
    int msbPos = 0;
    while(x_XOR_y){
        msbPos++;
        x_XOR_y = x_XOR_y >> 1;
    }

    // construct result by adding 1, msbPos times
    int maxXOR = 0;
    int two = 1;
    while (msbPos--) {
        maxXOR += two;
        two <<= 1;
    }
    return maxXOR;
}

int main(){
	int x, y;
    cin>>x>>y;
    int result = max_xor(x,y);
    cout<<result<<endl;

    cout<<maxXOR(x, y)<<endl;

    return 0;
}
