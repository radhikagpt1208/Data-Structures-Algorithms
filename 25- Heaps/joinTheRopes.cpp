/*PROBLEM STATEMENT : There are given n ropes of different lengths, we need to connect these ropes into one rope.
The cost to connect two ropes is equal to the sum of their lengths. We need to connect the ropes with minimum cost.

APPROACH:
1. First build a min heap of the sizes of the ropes.
2. Pick the first 2 smallest ropes from the min heap to join first and then remove them from the heap.
3. Add their cost to the previous cost
4. Insert the new rope in the priority queue.
5. Repeat until you get a single rope */

//O(nlogn)assuming that we use a O(nLogn) sorting algorithm.
//Note that heap operations like insert and extract take O(Logn) time.
//O(n) space to store the values in a min heap

#include<iostream>
#include<queue>
using namespace std;

int join_ropes(int ropes[], int n){
    //to make it a min heap, we use the inbuilt comparator
    //initialize the priority queue with ropes array.
    priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);

    int cost = 0;
    //till you get a single rope
    while(pq.size() > 1){
        //extract the first 2 shortest ropes
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int new_rope_cost = (A + B);
        cost += new_rope_cost;
        //add the newly created rope into the priority queue so that it can be joined when the other 2 ropes are extracted
        pq.push(new_rope_cost);
    }
    return cost;
}

int main(){
    int ropes[] = {4, 3, 2, 6};
    int n = 4;

    cout<<join_ropes(ropes, n);
    return 0;
}
