#include<iostream>
using namespace std;
#define ll long long

void primeSieve(int *arr){
	for(int i = 3 ; i <= 1000000 ; i +=2){
		arr[i] = 1;
	}

	for(ll i = 3 ; i <= 1000000 ; i +=2){
		if(arr[i] == 1){
			for(ll j = i*i ; j <= 1000000 ; j += i){
				arr[j] = 0;
			}
		}
	}
	//special cases
	arr[0] = arr[1] = 0;
	arr[2] = 1;
}

int main() {
	int t , a , b;
	cin>>t;
	int arr[1000005] = {0};

	primeSieve(arr);

	int csum[1000005] = {0};
	//precompute the primes upto index i
	for(int i = 1 ; i < 1000000 ; i++){
		csum[i] = csum[i-1] + arr[i];
	}

	while(t--){
		cin>>a>>b;
		cout<<csum[b] - csum[a-1]<<endl;
	}


	return 0;
}
