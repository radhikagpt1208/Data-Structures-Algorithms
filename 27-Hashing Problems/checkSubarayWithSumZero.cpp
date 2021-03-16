/* APPROACH: Use Hashing.
1. Iterate through the array and for every element arr[i], calculate sum of elements form 0 to i (this can simply be done as sum += arr[i]).
2. Hence a prefix sum(or cumulative sum array) has been made
3. Now for same values of sum in the prefix array, we know that if the first occurrence of the repeated sum value is i and
   second occurrence is j,then all elements in the original array from index i+1 to j will form a sub array of sum zero with
   length of the sub array as (j - i)
4. Also if the sum value is zero in the prefix array,then all elements upto that index also forms a sub array of sum 0
   with length of the sub array as i + 1 (i: index where sum zero occurs in the prefix sum array)
5. Hence,If the current sum has been seen before, then there is a zero sum array.
6. Hashing is used to store the sum values, so that we can quickly store sum and find out whether the current sum is seen before or not. */

#include<iostream>
#include<unordered_set>
using namespace std;

bool checkSum(int arr[], int n){
    unordered_set<int> s;

    //compute running prefix sum and storing the sum values in the set(not building a prefix sum array)
    int pre = 0;
    for(int i = 0; i < n; i++){
        pre += arr[i];
        //if you get a sum = 0 or the current sum already exists in the set
        if(pre == 0 or s.find(pre) != s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    if(checkSum(arr, n)){
        cout<<"Sub array with sum zero exists"<<endl;
    }
    else{
        cout<<"Sub array with zero sum does NOT exist"<<endl;
    }
    return 0;
}
