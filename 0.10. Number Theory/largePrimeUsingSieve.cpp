#include<iostream>
using namespace std;
#define ll long long

int * primeSieve(int *arr , int  n){
    int k = 0;
    int * primes = new int[n];
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

    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 1){
            primes[k] = i;
            k++;
        }
    }
    return primes;
}

bool isPrime(int n , int * arr , int * primes , ll int num){
    if(num <= n){
        if(arr[num] == 1){
            return true;
        }
        return false;
    }
    for(ll i = 0 ; primes[i]*(long long)primes[i] <= num ; i++){
        if(num % primes[i] == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 10000000;
    //Initialize all the elements of the array as 0
    int * arr = new int[n];
    int * primes = primeSieve(arr , n);

    int t;
    cin>>t;
    while(t--){
        ll int num;
        cin>>num;
        if(isPrime(n , arr , primes , num)){
            cout<<"It is a prime number";
        }
        else{
            cout<<"It is not a prime number";
        }
    }
    return 0;
}
