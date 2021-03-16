#include<iostream>
using namespace std;

//you can take a jump of maximum size 3

int ladder(int n){
    //base case
    if(n == 0){
        return 1;     //one way to stand on the ground,i.e,at n=0
    }
    if(n < 0){
        return 0;
    }
    return ladder(n - 1) + ladder(n - 2) + ladder(n - 3);
}

int main(){
    int n;
    cin>>n;
    cout<<ladder(n);
    return 0;
}
