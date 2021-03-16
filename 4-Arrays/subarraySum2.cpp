#include <iostream>
using namespace std;

int main()
{
    int n,currentSum=0,maxSum=0;
    cin>>n;
    int arr[1000],cumSum[1000];
    cin>>arr[0];
    cumSum[0]=arr[0];;
    for(int i=1; i<n; i++){
        cin>>arr[i];
        cumSum[i]=cumSum[i-1]+arr[i];
    }
    int left=-1;
    int right=-1;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            currentSum=0;
            currentSum=cumSum[j]-cumSum[i-1];
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
