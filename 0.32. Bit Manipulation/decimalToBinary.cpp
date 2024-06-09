/* Given a decimal number N,convert it into its binary representation.
Approach : Since numbers are stored in binary format in the memory,we can keep extracting the last bit till N > 0 and keep on
printing the extracted bits simultaneously. However, this will print the bits in reverse order.
To resolve this,we can convert it into a base 10 integer by multiplying by the powers of 10. */

#include<iostream>
using namespace std;

int decToBin(int n){
    int ans = 0;      //store the binary number (which actually is a base-10 integer)
    int power = 1;    //1 = 10^0
    while(n > 0){
        int last_bit = (n & 1);
        ans += last_bit * power;
        power = power * 10;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<decToBin(n)<<endl;
    return 0;
}
