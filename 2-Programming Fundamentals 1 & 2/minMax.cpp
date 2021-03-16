#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter how many numbers: \n";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers: \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        else if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    cout<<"Maximum number is:\t"<<max<<endl;
    cout<<"Minimum number is:\t"<<min;
    return 0;
}
