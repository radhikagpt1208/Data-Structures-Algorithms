#include<iostream>
using namespace std;

int tiles(int length){
    //base case
    //if length is 0,there is no way to build the wall
    if(length < 1){
        return 0;
    }
    //if length is <= 3,there is only one way to build the wall,i.e,vertically
    if(length <= 3){
        return 1;
    }
    //if length is 4,there are 2 ways,i.e,vertically and horizontally
    if(length == 4){
        return 2;
    }
    //rec case
    return tiles(length - 1) + tiles(length - 4);
}

int main(){
    int length;
    cin>>length;
    cout<<tiles(length);
    return 0;
}
