#include<iostream>
using namespace std;

int f(int n){
    //base case
    if(n == 0 || n == 1){
        return 1;
    }
    //rec case
    //if a person goes single,there will be (n-1) people left
    int single = 1 * f(n - 1);
    //if a person goes with another friend,he first chooses out of the (n-1) people,and then (n-2) people are left
    int couple = (n - 1) * f(n-2);
    return single + couple;
}

int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
