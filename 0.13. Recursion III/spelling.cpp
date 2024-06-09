//Convert number to its corresponding spelling

#include<iostream>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print_spellings(int n){
    //base case
    if(n == 0){
        return;
    }
    print_spellings(n/10);
    int digit = n % 10;
    cout<<words[digit]<<" ";
}

int main(){
    int n;
    cin>>n;
    print_spellings(n);
    return 0;
}
