//Array(or vector) in Heap in O(N) time

#include<iostream>
#include<vector>
using namespace std;

bool minHeap = false;   //max heap will be built

bool compare(int a, int b){
        if(minHeap){
             return a < b;
        }
        else{
            return a > b;
        }
    }

void heapify(vector<int> &v, int idx){
    int left  = 2*idx;
    int right = 2*idx + 1;

    int min_idx = idx;
    int last_idx = v.size() - 1;
    if(left <= last_idx && compare(v[left], v[idx])){
        min_idx = left;
    }
    if(right <= last_idx && compare(v[right], v[min_idx])){
        min_idx = right;
    }

    if(min_idx != idx){
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

//O(N)-BOTTOM UP OPTIMIZED APPROACH
//start from the first non-leaf node because if you consider the leaf node,it is already a heap
//fix the node at the correct place by pushing it upwards
//index of first non-leaf node = n/2(where n is the total number of nodes)
void buildHeap(vector<int> &v){
    for(int i = (v.size()-1/2) ; i >= 1; i--){
        heapify(v, i);
    }
}

void print(vector<int> v){
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    //block the 0th index of the vector
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    buildHeap(v);
    print(v);
    return 0;
}
