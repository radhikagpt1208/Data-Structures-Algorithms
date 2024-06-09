#include<iostream>
#include<stack>
using namespace std;

void printNGE(int arr[], int n) {
	stack<int> s;
	//to store the next greater element
	int arr1[n];

	for (int i = 2 * n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] <= arr[i % n]){
			s.pop();
		}

		arr1[i % n] = (s.empty() ? -1 : arr[s.top()]);

		s.push(i % n);
	}

	for (int i = 0; i < n; i++)
		cout<<arr1[i] <<" ";
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin>>arr[i];
	}
	printNGE(arr, n);
	return 0;
}
