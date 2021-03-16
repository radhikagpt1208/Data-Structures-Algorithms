#include<iostream>
using namespace std;
#define ll long long

void primeSieve(int *arr , int N){
    //mark all odd nos as prime
    for(int i = 3 ; i <= N ; i+=2){
        arr[i] = 1;
    }
    //Mark non-prime nos as 0
    //Iterate only over Odd Nos.
    for(ll i = 3 ; i <= N ; i+=2){
        if(arr[i] == 1){
            //mark all the multiples of i as not prime,i.e,0
            for(ll j = i*i ; j <= N ; j += i){
                arr[j] = 0;
            }
        }
    }
    //special case
    arr[2] = 1;
    arr[0] = arr[1] = 0;
}

int main(){
	int N = 1000000;
    ll num;
    cin>>num;
    //Initialize all the elements of the array as 0
    int arr[N] = {0};
    primeSieve(arr , N);
    //Print the nth prime number
	ll n , i = 0 , ans , c = 0;
	while(c<num){
		if(arr[i]==1){
			ans = i ;
			c++;
		}
		i++;
	}
	cout<<ans;

    return 0;
}

