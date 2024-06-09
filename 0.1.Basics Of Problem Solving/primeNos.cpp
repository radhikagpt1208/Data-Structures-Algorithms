#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,check=0;
    cout<<"Find prime numbers upto:\t";
    cin>>n;

    cout<<"Prime numbers between 1 and "<<n<<" are:\t";
    for(int i=2; i<n; i++)
    {
        for(int j=2; j<=i/2; j++)
        {
             if(i%j==0)
            {
                check=1;
                break;
            }
        }
        if(check==0 && n!=1)
        {
            cout<<i;
        }
        check=0;
    }
    return 0;
}
