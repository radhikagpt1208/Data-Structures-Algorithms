#include<iostream>
using namespace std;

void generate_permutations(char *input, int i){
    //i denotes the index till which the process of permutations is completed
    //base case
    if(input[i] == '\0'){
        cout<<input<<",";
        return;
    }
    //rec case
    for(int j = i; input[j]!= '\0'; j++){
        swap(input[i], input[j]);
        generate_permutations(input, i + 1);
        //BACKTRACKING
        //to restore the original array,swap again
        swap(input[i], input[j]);
    }
}

int main(){
    char input[100];
    cin>>input;
    generate_permutations(input, 0);
    return 0;
}

//EXAMPLE:
//if the string is abc,i is at a and j also starts from a
//now swap a with a,and permute the rest of the elements,i.e,b and c
//now j moves to b
//swap a with b and permute the remaining elements,i.e,a and c and so on....
