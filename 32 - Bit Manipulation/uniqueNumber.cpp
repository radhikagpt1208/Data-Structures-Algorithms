/* Problem Statement: Given a list of numbers where every number occurs twice except one number, find that unique number.
Hint : We know that for a number x, x^x = 0(Bitwise XOR)Hence keep inputting numbers and keep taking the XOR in a variable ans.
At the end,'ans' variable will store the unique number because the XOR of the rest of the numbers(that are getting repeated)
will get canceled.
No extra storage/memory required. */

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int num, ans = 0;

    for(int i = 0;i < n; i++){
        cin>>num;
        ans = ans^num;
    }
    cout<<ans<<endl;
    return 0;
}

