#include<iostream>
using namespace std;
int main()
{   int val=0,n;
    cout<<"Enter the number of rows:\t";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout<<val;
            val=1-val;

        }
        cout<<"\n";
    }
    return 0;
}
