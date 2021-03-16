#include<iostream>
using namespace std;

int main(){
    int i, N, sum=0;
    cout<<"Enter the number till which you want to find the sum \t";
    cin>>N;
    for(i=2; i<N; i+=2)
    {
        sum+=i;
    }
    cout<<"Sum of even numbers is"<<"\t"<<sum;
    return 0;
}
