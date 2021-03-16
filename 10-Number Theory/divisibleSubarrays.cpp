#include<iostream>
using namespace std;

int subarray(int arr[] , int n){
	int sum = 0 , count = 0;
	for(int i = 0 ; i < n ; i++){
		sum = 0;
		for(int j = i ; j < n ; j++){
			sum += arr[j];
			if(sum % n ==0){
				count++;
			}
		}
	}
	return count;
}

int main() {
	int t;
	cin>>t;
	for(int i = 0 ; i < t ; i++){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0 ; i < n ; i++){
			cin>>arr[i];
		}
		cout<<subarray(arr , n)<<endl;
	}

	return 0;
}
