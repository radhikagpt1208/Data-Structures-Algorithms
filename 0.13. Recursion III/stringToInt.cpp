#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char *a , int len){
    //base case
    if(len == 0){
        return 0;
    }
    //rec case
    int digit = a[len - 1] - '0';     //we get the last digit by subtracting the ascii values
    int small_ans = stringToInt(a , len - 1);
    return small_ans * 10 + digit;
}

int main(){
    char a[] = "1234";
    int len = strlen(a);

    cout<<stringToInt(a , len);
}
