#include<iostream>
using namespace std;

int fact(int n){
    //Base case
    if(n == 0){
        return 1;
    }

    //Recursive case
    int sub_ans = fact(n-1);
    int ans = n * sub_ans;
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<fact(n)<<endl;
    return 0;
}
