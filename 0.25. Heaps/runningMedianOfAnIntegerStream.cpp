#include<iostream>
#include<queue>
using namespace std;

int main(){
    //create the 2 heaps
    priority_queue<int> leftHeap;      //by default,it is a max heap
    priority_queue<int, vector<int>, greater<int> > rightHeap;   //min heap

    int d;
    cin>>d;
    leftHeap.push(d);
    //initially,median will be the first element itself
    float med = d;
    cout<<"Median : "<<med<<endl;

    cin>>d;
    //input all elements
    while(d != -1){
        //case1(left side heap has more elements)
        if(leftHeap.size() > rightHeap.size()){
            if(d < med){
                //new data will go in the left heap
                //to balance,first pop the top element from the left heap and push it in the right heap
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else{
                //new data will go in the right heap(no need to balance)
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top())/2.0;
        }
        //case2(both heaps are balanced)
        else if(leftHeap.size() == rightHeap.size()){
            if(d < med){
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else{
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }
        // case3(right side heap has more elements)
        else if(leftHeap.size() < rightHeap.size()){
            if(d < med){
                //new data will go in the left heap(no need to balance)
                leftHeap.push(d);
            }
            else{
                //new data will go in the right heap
                //to balance,first pop the top element from the right heap and push it in the left heap
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top())/2.0;
        }

        cout<<"Median : "<<med<<endl;
        cin>>d;
    }

    return 0;
}
