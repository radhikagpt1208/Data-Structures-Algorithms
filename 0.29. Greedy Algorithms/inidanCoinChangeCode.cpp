#include<iostream>
#include<algorithm>
using namespace std;

int make_change(int *coins, int n, int amount){
    int cnt = 0;
    while(amount > 0){
        //we subtract the base address of the array to get the index(w/o doing this we will get the address)
        int idx = upper_bound(coins, coins + n, amount) - 1 - coins;
        cout<<coins[idx]<<" + ";
        amount = amount - coins[idx];
        cnt++;
    }
    cout<<endl;
    return cnt;
}

int main(){
    int amount;
    cin>>amount;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins)/sizeof(int);

    cout<<"The minimum number of coins required are : "<<make_change(coins, n, amount);
    return 0;
}
