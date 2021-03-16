#include<iostream>
using namespace std;

bool isPrime(int n)
{
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

void allPrimes(int n)
{
    for(int i=2; i<=n; i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int n;
    cin>>n;
    /*if(isPrime(n))
    {
        cout<<"Prime";
    }
    else
    {
        cout<<"Not Prime";
    }*/
    allPrimes(n);
    return 0;
}

