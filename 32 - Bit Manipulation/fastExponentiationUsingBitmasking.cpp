/* Given 2 numbers , 'a' and 'n' you have to compute a^n using bitwise.
This method uses bit masks and without using extra space to calculate a^n in O(log n) time because (log n) is the maximum no. of set bits in
any given number 'a'.
1. Consider variable 'ans' in which we store the result and initialize it with 1
   ('a' raised to the power any given 'n' will always be greater than 1 as a^0 = 1)
2. We consider 'n' in the form of binary representation and extract last bit from n.
3. If the Extracted bit is 1 multiply ans with current value of a, otherwise if the extracted bit is 0 then just discard the bit.
4. Before moving to the next bit position, update a to a*a.
5. Repeat steps 2 to 4 until n becomes 0  */

#include<iostream>
using namespace std;

int exponentiation(int a, int n){
    int ans = 1;
    while(n > 0){
        int bit = (n & 1);
        if(bit == 1){
            ans *= a;
        }
        a = a*a;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int a, n;
    cin>>a>>n;

    cout<<a<<" raised to the power "<<n<<" is "<<exponentiation(a, n)<<endl;
    return 0;
}
