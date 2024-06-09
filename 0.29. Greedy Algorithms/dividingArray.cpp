/* Approach :
-> Minimum value of difference b/w the arrays is obtained after sorting the array adjacent elements are present in different
   arrays.
-> Maximum value of difference is obtained when after sorting,first n/2 element remain in array A sorted in ascending order and
    last n/2 elements in array B sorted in descending order then take the difference of both these arrays to get max value */

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        //if there is only one element in the array,both max and min value will be equal to that element
        if(n == 1){
            cout<<arr[0]<<" "<<arr[0];
        }
        else{
            sort(arr, arr + n);
            int min_value = 0, max_value = 0;

            for(int i = 0; i < n; i += 2){
                min_value += abs(arr[i] - arr[i + 1]);
            }

            int start = 0, end = n-1;
            while(start <= end){
                max_value += abs(arr[start] - arr[end]);
                start++;
                end--;
            }
            cout<<min_value<<" "<<max_value<<endl;
        }
    }
    return 0;
}
