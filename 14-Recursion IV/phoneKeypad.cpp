#include<iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_char(char *input , char *output, int i, int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    //extract the current digit
    int digit = input[i] - '0';    //to convert char to int,subtract 0
    //if the digit is 1 or 0,it will not extract any char,and hence return
    if(digit == 0 || digit == 1){
        generate_char(input, output, i + 1, j);
    }
    //extract the characters associated with the current digit
    for(int k = 0; keypad[digit][k]!= '\0'; k++){
        //make 3 calls
        //place the first char of that digit and make a rec call for the rest
        output[j] = keypad[digit][k];
        generate_char(input, output, i + 1, j + 1);
    }
    return;
}

int main(){
    char input[10];
    cin>>input;
    char output[100];
    generate_char(input, output, 0, 0);
    return 0;
}
