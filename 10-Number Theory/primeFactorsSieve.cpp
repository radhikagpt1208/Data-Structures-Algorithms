#include<iostream>
using namespace std;
#define ll long long

int * primeSieve(int *arr , int  n){
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

    int k = 0;
    int * primes = new int[n];
    for(int i = 0 ; i <= n ; i++){
        if(arr[i] == 1){
            primes[k] = i;
            k++;
        }
    }
    return primes;
}

int * factorize(int num , int *primes , int &i){
    int * factors = new int[num];
    int p = primes[0];
    int j=0;
    while(p <= num){
        if(num % p == 0){
            factors[i] = p;
            i++;
            while(num % p == 0){
                num = num/p;
            }
        }
        //go to the next position
        p = primes[j++];
    }
    return factors;
}

int main(){
    int n = 1000000;
    //Initialize all the elements of the array as 0
    int arr[n] = {0};
    int * primes = primeSieve(arr , n);

    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        int i = 0 ;
        int * factors = factorize(num , primes , i);

        //print the factors of the number
        for(int j = 0 ; j < i ; j++){
            cout<<factors[j]<<endl;
        }
    }
    return 0;
}
