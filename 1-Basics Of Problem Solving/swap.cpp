#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    cout<<"Enter first number:\t";
    cin>>a;
    cout<<"Enter second number:\t";
    cin>>b;

    a=a+b;
    b=a-b;
    a=a-b;

    cout<<"After Swapping:\n"<<a<<" "<<b;
    return 0;
}
