#include<iostream>
using namespace std;

int main(){
    int arr[100000];
    int count_arr[100000];

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        count_arr[100000] = {0};
        count_arr[0] = 1;

        int sum = 0;
        //read the array
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];

            sum = sum + arr[i];
            sum = sum % n ;
            //to handle negative cases
            sum = (sum + n)  % n;
            count_arr[sum]++;
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(count_arr[i] >= 2){
                int m = count_arr[i];
                ans += (m*(m-1))/2;
            }
        }
        cout<<ans;
    }
    return 0;
}
