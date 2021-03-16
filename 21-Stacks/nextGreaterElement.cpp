#include<iostream>
#include<stack>
using namespace std;

void printNGE(int arr[], int n) {
	stack<int> s;
	//to store the next greater element
	int arr1[n];

	// iterating from the end
	for (int i = n - 1; i >= 0; i--) {
		/*We will pop till we get the greater element on top or stack gets empty*/
		while (!s.empty() && s.top() <= arr[i]){
			s.pop();
		}

		//if stack is empty means there is no element on right which is greater than the current element.
		//if not empty then the next greater element is on top of stack
		if (s.empty()){
			arr1[i] = -1;
		}
		else{
			arr1[i] = s.top();
		}
		s.push(arr[i]);
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

