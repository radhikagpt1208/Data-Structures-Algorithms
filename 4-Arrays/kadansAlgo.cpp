#include <iostream>
using namespace std;
int main()
{
    int n , currentSum = 0 , maxSum = 0;
    cin>>n;
    int arr[1000];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    for(int i = 0; i<n; i++)
    {
        currentSum += arr[i];
        if(currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(currentSum , maxSum);
    }
    //print maximum Sum
    cout<<maxSum<<endl;
    return 0;
}

