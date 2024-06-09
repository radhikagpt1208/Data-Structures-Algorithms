#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    //this variable keeps track if the user wants a min heap or a max heap
    bool minHeap;

    /*function to check for the condition of min heap and max heap
    compare the element with its parent to check if the element is inserted at the correct position
    case of min heap:keep pushing to the top till you reach the root or stop midway if the element is smaller than the parent element
    case of max heap:keep pushing to the top till you reach the root or stop midway if the element is larger than the parent element
    a : current element, b : parent */
    bool compare(int a, int b){
        if(minHeap){
             return a < b;
        }
        else{
            return a > b;
        }
    }

    //take the index of the element to be heapified
    void heapify(int idx){
        int left  =2*idx;
        int right = 2*idx + 1;

        int min_idx = idx;
        int last_idx = v.size() - 1;
        //left child exists only if its index is <= last index of the array.
        //Check if left node is smaller than current node,update the min_idx
        if(left <= last_idx && compare(v[left], v[idx])){
            min_idx = left;
        }
        //right child exists only if its index is <= last index of the array.
        //Check if right node is smaller than current min_idx node,update its value
        if(right <= last_idx && compare(v[right], v[min_idx])){
            min_idx = right;
        }

        //if replacement has taken place
        if(min_idx != idx){
            swap(v[idx], v[min_idx]);
            //make a recursive call
            heapify(min_idx);
        }
    }

public:
    Heap(int default_size = 10, bool type = true){
        v.reserve(default_size);
        //block the 0th index
        v.push_back(-1);
        //if the type is true,we build a min heap. If type is false,max heap is built.
        minHeap = type;
    }

    //O(logN)
    void push(int d){
        //insert the element at the end
        v.push_back(d);

        //index at which the element is inserted
        int idx = v.size() - 1;
        int parentIdx = idx/2;

        while(idx > 1 && compare(v[idx],v[parentIdx])){
            //according to the condition of min heap and max heap, swap the 2 elements
            swap(v[idx], v[parentIdx]);
            //update the 2 indexes
            idx = parentIdx;
            parentIdx = parentIdx/2;
        }
    }

    //O(1)
    //returns the top most element of the heap
    int top(){
        return v[1];
    }

    //O(logN)
    void pop(){
        //delete the smallest element in case of min heap or the largest element in case of max heap
        //hence the root has to be removed in both the cases
        //1. swap the first and the last element
        int last_idx = v.size() - 1;
        swap(v[1], v[last_idx]);
        //2. remove the last element,i.e,the root is deleted
        v.pop_back();
        //run heapify operation from the root node
        heapify(1);
    }

    bool empty(){
        return v.size() == 1;
    }
};

int main(){
    Heap h(10, false);    //by default,it is a min heap
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        h.push(num);
    }

    //remove elements of the heap one by one
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}
