#include<iostream>
using namespace std;

int main(){
    int i, N, check=0;
    cout<<"Enter the number\t";
    cin>>N;

    for(i=2; i<N/2; i++)
    {
        if(N%i==0)
        {
            check=1;
            break;
        }
    }
    if(check==0 && N!=1)
    {
         cout<<N<<" is a prime number";
    }
    else
    {
        cout<<N<<" is not a prime number";
    }
    return 0;
}
