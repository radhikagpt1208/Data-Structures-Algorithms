//Convert array(or vector) into Heap(in place),i.e, you cannot use another heap object to insert elements in the heap.

#include<iostream>
#include<vector>
using namespace std;

//O(NlogN) : TOP TO BOTTOM APPROACH
//convert the  vector into heap in place
void buildHeap(vector<int> &v){
    //root does not have a parent node,hence we start iterating from the second element of the vector,i.e,child of the root
    //and fix the position of each and every element
    for(int i = 2; i < v.size(); i++){
        int idx = i;
        int parent = i/2;

        //for max heap
        while(idx > 1 && v[idx] > v[parent]){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent/2;
        }
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
