#include<iostream>
using namespace std;

int main()
{
    int num,p;
    float ans=0, inc=1.0;
    cout<<"Enter a number:\t";
    cin>>num;
    cout<<"Upto how many decimal places:\t";
    cin>>p;

    for(int i=0; i<=p; i++)
    {
        //finalizes the correct digit for the current place
        while(ans*ans<=num)
        {
            ans=ans+inc;
        }
        ans=ans-inc;
        //updates the increment for the next decimal place
        inc=inc/10;
    }

    cout<<"Square root of "<<num<<" is: "<<ans;

    return 0;
}
