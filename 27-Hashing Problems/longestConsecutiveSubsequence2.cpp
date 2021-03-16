/* APPROACH 2: O(min - max)
1. Create an empty hash and insert all the elements of the array
2. Find the min and max element in the array and keep 2 variables, count=0 and ans=0
3. Run a loop from the min to the max element
4. For every element,check if it exists in the map,if yes,then keep increasing the count
5. If the element is not present,then update ans = max(ans, count) and set count = 0 to check for the length of the next
   subsequence */

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n) {
	unordered_set<int> S;
	int ans = 0, count = 0;

	// Hash all the array elements
	for (int i = 0; i < n; i++)
		S.insert(arr[i]);

    int minEle = *min_element(arr, arr + n);
    int maxEle = *max_element(arr, arr + n);

	for (int i = minEle; i <= maxEle; i++) {
		if (S.find(i) != S.end()) {
		    count++;
		}
		else{
		    ans = max(ans, count);
		    count = 0;
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
