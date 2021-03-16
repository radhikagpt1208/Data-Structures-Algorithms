#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num, temp, sum=0;
    cout<<"Enter the number: \t";
    cin>>num;
    int x=abs(num);

    while(x>0)
    {
        temp = x%10;
        sum = sum+temp;
        x = x/10;

    }
    cout<<"Sum of digits is:\t"<<sum;
    return 0;
}

