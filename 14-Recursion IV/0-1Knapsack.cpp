#include<iostream>
using namespace std;

int profit(int *price, int *weights, int N, int C){
    //base case
    if(N == 0 || C == 0){
        return 0;
    }
    //rec case
    //pick or reject the last item and make (n-1) items as the subproblem
    int ans, include_profit = 0, exclude_profit = 0;
    //option 1: if I include the item,profit will be: price of that item + price of remaining items
    if(weights[N-1] <= C){
        include_profit = price[N-1] + profit(price, weights, N - 1, C - weights[N-1]);
    }
    //option 2: if I exclude the item,profit will be: 0(no profit from the excluded item) + price of remaining items
    exclude_profit = profit(price, weights, N - 1, C);

    ans = max(include_profit, exclude_profit);
    return ans;
}

int main(){
    int price[] = {40, 20, 30, 100};
    int weights[] = {1, 2, 3, 5};
    int no_of_items = 4;
    int capacity = 7;
    cout<<profit(price, weights, no_of_items, capacity);
    return 0;
}
