#include<iostream>
#include<queue>
using namespace std;

int main(){
    //BY DEFAULT,THIS TYPE OF A PRIORITY QUEUE IS BASED ON MAX HEAP:YOU WILL GET THE ELEMENTS IN DECREASING ORDER
    //you can also convert it into min heap by passing an inbuilt comparator : greater<int>
    priority_queue<int, vector<int>, greater<int> > pq;    //min priority queue
    //priority_queue<int> pq;                              //max priority queue
    //push elements in the priority queue
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int no;
        cin>>no;
        pq.push(no);    //O(logN) where N is the no of elements present in the heap at that time
    }

    //remove elements from the priority queue
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
