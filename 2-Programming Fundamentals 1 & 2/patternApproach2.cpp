#include<iostream>
using namespace std;
int main()
{   int n;
    cout<<"Enter the number of rows:\t";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            for(int j=0; j<=i; j++)
            {
                if(j%2==0)
                {
                    cout<<0;
                }
                else
                {
                    cout<<1;
                }
            }
            cout<<"\n";
        }
        else if(i%2!=0)
        {
            for(int j=0; j<=i; j++)
            {
                if(j%2==0)
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
