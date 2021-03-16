#include<iostream>
#include<stack>
using namespace std;

//COMPLEXITY: O(N) because each element is pushed and popped only once

void stockSpan(int prices[], int n, int span[]){
    stack<int> s;
    //push the index of first day
    s.push(0);
    //explicitly mention the span of first day
    span[0] = 1;

    //loop for the rest of the days
    for(int i = 1; i < n; i++){
        int currentPrice = prices[i];
        //pop out all the elements smaller than the current price
        while(!s.empty() && prices[s.top()] <= currentPrice){
            s.pop();
        }
        if(!s.empty()){
            int prevHighest = s.top();
            span[i] = i - prevHighest;
        }
        //if the stack is empty, the span of the i-th day will be the number of day still now,i.e, i+1
        else{
            span[i] = i + 1;
        }
        //push this element into the stack
        s.push(i);
    }
}

int main(){
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);
    int span[100000] = {0};

    stockSpan(prices, n, span);
    for(int i = 0; i < n; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}
