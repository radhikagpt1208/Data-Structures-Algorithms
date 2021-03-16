#include<iostream>
using namespace std;

//you can take a jump of maximum size k

int ladder(int n , int k){
    //base case
    if(n == 0){
        return 1;     //one way to stand on the ground,i.e,at n=0
    }
    if(n < 0){
        return 0;
    }
    //rec case
    int ans = 0;
    for(int i = 1 ; i <= k ; i++){
        ans += ladder(n - i , k);
    }
    return ans;
}

int main(){
    int n , k;
    cin>>n>>k;
    cout<<ladder(n , k);
    return 0;
}

