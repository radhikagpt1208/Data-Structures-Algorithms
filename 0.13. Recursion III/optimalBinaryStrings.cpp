/* If we take a closer look at the pattern, we can observe that the count is actually (n+2)’th Fibonacci number for n >= 1.
The Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ….  */

#include<iostream>
using namespace std;

int cnt(int n){
    //base case
    if(n == 0){
        return 1;
    }
    if(n == 1){
        //the element can either be 1 or 0
        return 2;
    }
    //rec case
    //if we place a 0 at the end,we will get the count of valid strings of length (n-1)
    int zero = cnt(n - 1);
    //if we place a 1 at the end,we will have to place a 0 before that so that we get the count of valid strings of length (n-2)
    int one = cnt(n - 2);
    return one + zero;
}

int main(){
    int n;
    cin>>n;
    cout<<cnt(n);
    return 0;
}
