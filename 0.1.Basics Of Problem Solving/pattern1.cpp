#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    cout<<"Enter the number of rows";
    cin>>n;

    for(i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            for(j=0; j<i; j++)
            {
                cout<<1;
            }
            cout<<"\n";
        }
        else
        {
            for(j=0; j<i; j++)
            {
                if(j==0 || j==(i-1))
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}
