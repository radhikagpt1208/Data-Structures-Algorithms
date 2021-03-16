#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num , cnt = 0;
    cin>>num;
    //Naive Approach
    for(int i = 1 ; i <= num ; i++){
        if(num % i == 0){
            cnt++;
        }
    }
    cout<<cnt;

    //Optimized Approach
    int cnt = 0;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            // If divisors are equal,(because of square root)
            // count only one
            if (num / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    cout<<cnt;

    return 0;
}





