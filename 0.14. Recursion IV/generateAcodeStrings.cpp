#include<iostream>
using namespace std;

void generate_strings(char *input, char *output, int i, int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    //1st option: pick one digit at a time
    int digit = input[i] - '0';
    //convert the digit into corresponding character
    char ch = digit + 'A' - 1;
    output[j] = ch;
    generate_strings(input, output, i + 1, j + 1);

    //2nd option: pick two digits at a time
    if(input[i+1] != '\0'){
        int second_digit = input[i+1] - '0';
        int number = digit*10 + second_digit;
        if(number <= 26){
            ch = number + 'A' - 1;
            output[j] = ch;
            generate_strings(input, output, i + 2, j + 1);
        }
    }
    return;
}

int main(){
    char input[100];
    cin>>input;
    char output[100];
    generate_strings(input, output, 0, 0);
    return 0;
}
