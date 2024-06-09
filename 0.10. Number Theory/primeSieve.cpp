#include<iostream>
using namespace std;
#define ll long long

void primeSieve(int *arr , int  n){
    //mark all odd nos as prime
    for(int i = 3 ; i <= n ; i+=2){
        arr[i] = 1;
    }
    //Mark non-prime nos as 0
    //Iterate only over Odd Nos.
    for(ll i = 3 ; i <= n ; i+=2){
        if(arr[i] == 1){
            //mark all the multiples of i as not prime,i.e,0
            for(ll j = i*i ; j <= n ; j += i){
                arr[j] = 0;
            }
        }
    }
    //special case
    arr[2] = 1;
    arr[0] = arr[1] = 0;
}

int main(){
    int n;
    cin>>n;
    //Initialize all the elements of the array as 0
    int arr[1000000] = {0};
    primeSieve(arr , n);
    //Print the resultant array of prime nos up to range n
    for(int i = 0; i <= n ; i++){
        if(arr[i] == 1){
            cout<<i<<" ";
        }
    }
    return 0;
}
