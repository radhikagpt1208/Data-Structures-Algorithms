/* Algorithm:
The idea is to use min heap. Create a Min-Heap to store the elements.
Traverse the first row from start to end and build a min heap of elements from first row.
A heap entry also stores row number and column number.
Now Run a loop k times to extract min element from heap in each iteration
Get minimum element (or root) from Min-Heap.
Find row number and column number of the minimum element.
Replace root with the next element from same column and min-heapify the root.
Print the last extracted element, which is the kth minimum element.  */

#include<iostream>
#include<queue>
#include<map>
using namespace std;

typedef pair<int, pair<int, int>> node;

int kthSmallest(int arr[][4], int n, int k){
    if(k > n * n){
        return INT_MAX;
    }
    priority_queue<node, vector<node>, greater<node> > pq;
    map< pair<int, int>, bool> visited;

    for(int i = 0; i < n; i++){
        pq.push({ arr[0][i],{0, i} });
        visited[{0, i}] = true;
    }
    int result;
    while(k > 0){
        node smallest = pq.top();
        pq.pop();
        int value = smallest.first;
        int i = smallest.second.first;
        int j = smallest.second.second;
        if(k == 1){
            result = value;
            return result;
        }
        if(j+1 < n && visited[{i, j+1}] == false){
            pq.push({arr[i][j+1], {i,j+1} });
            visited[{i, j+1}] = true;
        }
        if(i+1 < n && visited[{i+1, j}] == false){
            pq.push({arr[i+1][j] , {i+1, j} });
            visited[{i+1, j}] = true;
        }
        k--;
    }
}

int main(){
    int arr[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout<<"7th smallest element is "<<kthSmallest(arr, 4, 7);
    return 0;
}
