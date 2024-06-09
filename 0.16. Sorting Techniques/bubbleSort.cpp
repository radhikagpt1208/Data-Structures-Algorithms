#include<iostream>
using namespace std;

void bubble_sort(int a[], int n) {
	//N-1 large elements to the end
	for (int itr = 1 ; itr <= n - 1 ; itr++) {
		//Pairwise swapping in the unsorted part of the array
		// Last i elements are already in place
		for (int j = 0 ; j <= (n - itr - 1) ; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j] , a[j + 1]);
			}
		}
	}
}

//Iteration+Recursion
void bubbleSort(int *arr, int n){
    //base case : if there is only one element in the array, it is always sorted.
    if(n == 1){
        return;
    }
    //rec case
    //move the largest element to the end of the array by pairwise swapping
    for(int j = 0; j < n-1; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
    //recursively sort the first n-1 elements
    bubbleSort(arr, n-1);
}

void bubbleSortRec(int *arr, int n, int j){
    //n and j are controlling the outer and inner loop respectively
    //base case
    if(n == 1){
        return;
    }
    if(j == n-1){
        //single iteration is done,i.e, the largest element has reached the end of the array
        //hence,sort the first n-1 elements
        bubbleSortRec(arr, n-1, 0);
    }
    //rec case
    //to complete the first pass
    if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
    }
    bubbleSortRec(arr, n, j+1);
    return;
}

int main() {
	int n, key;
	cin >> n;
	int a[1000];
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	/* bubble_sort(a, n);
	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << ",";
	}
	cout<<endl; */
 	bubbleSortRec(arr, n, 0);
	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << ",";
	}
	return 0;
}
