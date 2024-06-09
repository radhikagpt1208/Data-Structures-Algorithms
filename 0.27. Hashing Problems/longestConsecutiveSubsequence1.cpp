/* APPROACH 1: O(nlogn)
1. Sort the elements of the given array
2. Keep 2 variables, count(initialized as 1) and ans(initialized as 0)
3. Now traverse the array and keep checking if the next element is just 1 greater than the previous element or no.
4. i.e, if(arr[i] == arr[i-1]+1) is the case, the  increase the count
5. Else if this is not the case,then update ans = max(ans, count) and then make count = 1 again to check for the
   length of next subsequence. */

#include <iostream>
using namespace std;

int findLongestConseqSubseq(int arr[], int n) {
	int ans = 0, count = 1;
	sort(arr, arr + n);

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1] + 1){
			count++;
		}
		else{
    		ans = max(ans, count);
    		count  = 1;
		}
	}
	return ans;
}

int main() {
	int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
	int n = sizeof arr / sizeof arr[0];
	cout << "Length of the Longest contiguous subsequence is "<< findLongestConseqSubseq(arr, n);
	return 0;
}



