/* Find subsequences/subsets of a given string.
Input : abc
Output : " " a b a ab ac bc abc
Approach :
1. If S has n elements in it then it will have 2^n (1<<n) subsets.
2  Loop for binary counter from 0 to 2^n - 1
     (a) Iterate over all the bits of the current counter.
          (i) If i-th bit in counter is set,print i-th element from string for this subset.*/

#include<iostream>
#include<cstring>
using namespace std;

void filterChar(int n, char a[]){
    int j = 0;
    while(n > 0){
        int last_bit = (n & 1);
        //if bit is set, then print the character
        if(last_bit == 1){
            cout<<a[j]<<" ";
        }
        j++;
        n = n >> 1;
    }
    cout<<endl;
}

void printSubsets(char a[]){
    int n = strlen(a);
    for(int i = 0; i < (1<<n); i++){
        filterChar(i, a);
    }
    return;
}

int main(){
    char a[100];
    cin>>a;

    printSubsets(a);

    return 0;
}
