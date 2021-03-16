//COMPLEXITY : time to build a max heap + time to remove every element is logN(hence to remove N elements,it will be (NlogN)
//Hence, TIME COMPLEXITY OF HEAP SORT: O(N) + O(NlogN) = O(NlogN)

//ALGORITHM
/* 1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1.
   Finally, heapify the root of the tree.
3. Repeat step 2 while size of heap is greater than 1.  */

#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &v, int i, int size){
    int left = 2*i;
    int right = left + 1;

    int largest = i;
    int last_idx = size - 1;

    if(left <= last_idx && v[left] > v[i]){
        largest = left;
    }
    if(right <= last_idx && v[right] > v[largest]){
        largest = right;
    }

    //you have found another element which is greater than i
    if(largest != i){
        swap(v[i], v[largest]);
        //Recursively heapify the affected sub-tree
        heapify(v, largest, size);
    }
}

void buildHeap(vector<int> &v){
    for(int i = (v.size()-1/2) ; i >= 1; i--){
        heapify(v, i, v.size());
    }
}

void heapSort(vector<int> &v){
    //build max heap
    //start from the first non leaf node
    buildHeap(v);

    int n = v.size();

    //remove n-1 elements from the heap
    //One by one extract an element from heap and move it to the end
    while(n > 1){
        swap(v[1], v[n-1]);
        //shrink the size of the heap to call heapify on the reduced heap(remove that element from the heap)
        n--;
        //we have to pass the size of the heap that we want to be heapified because we want to heapify only the reduced heap
        heapify(v, 1, n);
    }
}

void print(vector<int> &v){
    for(int x = 1; x < v.size() ; x++){
        cout<<v[x]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(-1);

    int n;
    cin>>n;
    int temp;
    for(int i = 0 ; i < n ; i++){
        cin>>temp;
        v.push_back(temp);
    }
    heapSort(v);
    print(v);
    return 0;
}
