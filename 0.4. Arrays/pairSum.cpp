#include <iostream>
using namespace std;

int main()
{
    int n, sum = 16;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int start = 0;
    int end = n-1;
    while(start < end)
    {
        int currentSum = arr[start] + arr[end];
        if(currentSum==sum){
            cout<<arr[start]<<","<<arr[end]<<endl;
            start++;
            end--;
        }
        else if(currentSum > sum){
            end--;
        }
        else if(currentSum < sum){
            start++;
        }
    }
    return 0;
}
