/*Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
This problem can be solved using Dynamic Programming.
Let a[i] be no. of binary strings of length i which don't contain any two consecutive 1s & which end in 0 & b[i] be the no. of such strings which end in 1.
We can append either 0 or 1 to a string ending in 0(because we can have consecutive 0s as well as a combination of 0s and 1s),but we can only append 0 to
a string ending in 1(as no consecutive 1s are allowed).
This yields the recurrence relation:
a[i] = a[i - 1] + b[i - 1]
b[i] = a[i - 1]
The base cases of above recurrence are a[1] = b[1] = 1(i.e, 0 and 1) The total number of strings of length i is just a[i] + b[i].
Also, here indexes start from 0. So a[i] represents the number of binary strings for input length i+1. Similarly, b[i] represents binary strings for input
length i+1.
Time complexity of above solution is O(n)
If we take a closer look at the pattern, we can observe that the count is actually (n+2)th Fibonacci number for n >= 1.
The Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141,..
n = 1, count = 2  = fib(3)
n = 2, count = 3  = fib(4)
n = 3, count = 5  = fib(5)
n = 4, count = 8  = fib(6)
n = 5, count = 13 = fib(7)......
Therefore we can count the strings in O(Log n) time also using the method of Fibonacci series.
*/

#include<iostream>
using namespace std;

long long int count_binary_strings(long long int n){
    long long int a[n], b[n];
    //Base Case
    a[0] = b[0] = 1;
    for(int i = 1; i < n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		cout<<count_binary_strings(n)<<endl;
	}
    return 0;
}

