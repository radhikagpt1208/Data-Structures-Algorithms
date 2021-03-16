#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num , count;
    cin>>num;
    for(int i = 2 ; i <= sqrt(num) ; i++){
        if(num % i ==0){
            count = 0;
            while(num % i ==0){
                num = num/i;
                count++;
            }
            cout<<i<<"^"<<count<<endl;
        }
    }
    if(num != 1){
        //whatever is left is a prime number itself
        cout<<num;
    }
    return 0;
}


