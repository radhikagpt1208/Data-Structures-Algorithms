#include<iostream>
using namespace std;

void generateSubsets(char *input , char *output , int i , int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    //rec case
    //option 1:include the current character
    output[j] = input[i];
    generateSubsets(input , output , i + 1 , j + 1);
    //option 2:exclude the current character
    generateSubsets(input , output , i + 1 , j);
}

int main(){
    char input[1000];
    cin>>input;
    char output[1000];
    generateSubsets(input , output , 0 , 0);
    return 0;
}
