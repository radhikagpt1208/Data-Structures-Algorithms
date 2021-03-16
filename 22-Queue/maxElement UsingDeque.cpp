//Given an array and an integer k, find the maximum for each and every contiguous sub array of size k
#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n, k;
    cin>>n;
    int a[100000];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>k;

    //Process ONLY the first k elements separately
    deque<int> Q(k);
    int i;
    for(i = 0; i < k; i++){
        //if the element at the current index in the array is greater than the last element in the dequeue currently
        while(!Q.empty() && a[i] > a[Q.back()]){
            Q.pop_back();
        }
        //pushing index in the dequeue
        Q.push_back(i);
    }

    //Process the remaining elements starting from wherever 'i' is currently
    for(; i < n; i++){
        //print the maximum element for the first k elements as calculated above
        cout<<a[Q.front()]<<" ";
            //1.Remove the elements which are not a part of the window(Contraction)
        //contract the dequeue from the front side by removing those index stored in the dequeue which are <= i-k
        while(!Q.empty() && Q.front() <= i-k){
            Q.pop_front();
        }

        //2.Remove the elements which are in the window but not useful
        while(!Q.empty() && a[i] > a[Q.back()]){
            Q.pop_back();
        }

        //3.Add the new elements(Expansion)
        Q.push_back(i);
    }
    //print the last largest element for the last window
    cout<<a[Q.front()]<<endl;

    return 0;
}
