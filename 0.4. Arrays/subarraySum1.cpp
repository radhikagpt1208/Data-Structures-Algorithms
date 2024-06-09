#include <iostream>
using namespace std;

int main()
{
    int n,currentSum=0,maxSum=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int left=-1;
    int right=-1;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            currentSum=0;
            for(int k=i; k<=j; k++)
            {
                currentSum+= arr[k];
            }
            if(currentSum>maxSum)
            {
                maxSum=currentSum;
                left=i;
                right=j;
            }
        }
    }
    //print maximum Sum
    cout<<maxSum<<endl;
    //print the subarray with maximum sum
    for(int k=left; k<=right; k++)
    {
        cout<<arr[k]<<" ";
    }
    return 0;
}
