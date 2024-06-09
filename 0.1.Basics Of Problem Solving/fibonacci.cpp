#include<iostream>
using namespace std;

int main(){
    int n, term1=0, term2=1, nextTerm=0;
    cout<<"Enter the number:\t";
    cin>>n;

    nextTerm = term1+term2;
    if(n==term1  || n==term2)
    {
        cout<<n<<" is a part of Fibonacci Series";
    }
    else
    {
        while(nextTerm<n)
        {
            term1=term2;
            term2=nextTerm;
            nextTerm=term1+term2;
        }
        if(nextTerm==n)
        {
            cout<<n<<" is a part of Fibonacci Series";
        }
        else
        {
            cout<<n<<" is not a part of Fibonacci Series";
        }
    }
    return 0;
}
