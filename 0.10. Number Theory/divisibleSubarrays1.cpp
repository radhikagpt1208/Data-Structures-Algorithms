#include<iostream>
using namespace std;

#define ll long

ll divisibleSubarray(ll arr[] , int n){
    ll cum_sum[100005] = {0};
    ll mod_arr[100005];
    ll count_arr[100005] = {0};
    ll ans = 0;

    //Generating a cumulative sum array
    for(int i = 1 ; i <= n ; i++){
        cum_sum[i] = cum_sum[i-1] + arr[i-1];
    }

    //Generating a modulo array
    for(int i = 0 ; i <= n ; i++){
        mod_arr[i] = ((cum_sum[i] % n) + n) % n;
    }

    for(int i = 0 ; i <= n ; i++){
        count_arr[mod_arr[i]]++;
    }

    for(int i = 0 ; i < n ; i++){
        if(count_arr[i] >= 2){
            ll m = count_arr[i];
            ans += (m*(m-1))/2;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    ll arr[100005];
    while(t--){
        int n;
        cin>>n;
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<divisibleSubarray(arr , n)<<endl;;
    }
    return 0;
}
