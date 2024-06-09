/* APPROACH:
 The idea is to use Min Heap.
 This MinHeap based solution has the same time complexity which is O(NK log K).
 The process must start with creating a MinHeap and inserting the first element of all the k arrays.
 Remove the root element of Minheap and put it in the output array and insert the next element from the array of removed element.
 To get the result the step must continue until there is no element in the MinHeap left.
 You will have to keep track of 3 things:
  (1)value of the element stored in the heap
  (2)array index from which the element has been taken
  (3)element index in the array from which it has been taken.
These are required because when you remove an element from the heap into the output array,you need to access the next element
to push it into the heap

 ALGORITHM:
1.Create a min Heap and insert the first element of all k arrays.
2.Run a loop until the size of MinHeap is greater than zero.
3.Remove the top element of the MinHeap(because it is the smallest element) and print the element.
4.Now insert the next element from the same array in which the removed element belonged.
5.If the array doesn’t have any more elements, then replace root with infinite.
6.After replacing the root, heapify the tree. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//In this pair, first int represents the element value, next two int represents its position in 2d vector i.e, x,y
typedef pair<int, pair<int, int> > node;     //to keep track of the 3 required values

//return type is a vector
vector<int> mergeKSortedArrays(vector<vector<int> >arr){
    vector<int> result;
    priority_queue<node, vector<node>, greater<node> > pq;    //min priority queue

    //insert the first element of every array into the priority queue
    for(int i = 0; i < arr.size(); i++){     //in this case,arr.size() = 3
        pq.push({arr[i][0] , {i,0}});        //insert the value of the element & a pair of the array index and the element index
    }

    //remove the elements one by one from the min heap and push in into the resultant vector
    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        //three values to be kept track of
        int element = current.first;    //value of element
        int x = current.second.first;   //array index
        int y = current.second.second;  //element index in that array

        result.push_back(element);

        //push the next element of the array into the pq from which the current element has been removed
        //to keep a check if there exists another element in that array
        if(y + 1 < arr[x].size()){
            pq.push({arr[x][y+1], {x, y+1}});
        }
    }
    return result;
}

int main(){
    vector< vector<int> > arr{ {2, 6, 12, 15},
                              {1, 3, 14, 20},
                              {3, 5, 8, 10} };

    vector<int> output = mergeKSortedArrays(arr);
    for(auto x : output){
        cout<<x<<" ";
    }
    return 0;
}
