#include<iostream>
using namespace std;

//source,helper,destination:3 towers
void moveDisks(int n , char src , char helper , char des){
    //base case
    if(n == 0){
        return;
    }
    //rec case
    //move n-1 disks from src to helper
    moveDisks(n - 1 , src , des , helper);
    //move the first disk from src to des
    cout<<"shift disk "<<n<<" from "<<src<<" to "<<des<<endl;
    //move n-1 disks from src to helper
    moveDisks(n - 1 , helper , src , des);
}

int main(){
    int n;     //no. of disks
    cin>>n;

    moveDisks(n , 'A' , 'B' , 'C');
    return 0;
}
