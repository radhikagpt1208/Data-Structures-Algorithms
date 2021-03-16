#include<iostream>
#include<string>
#include<set>
using namespace std;

void generate_permutations(char *input, int i, set<string>&s){
    //base case
    if(input[i] == '\0'){
        //cout<<input<<",";
        //initialize the string t with the current output and insert it in the set
        string t(input);
        s.insert(t);
        return;
    }
    //rec case
    for(int j = i; input[j]!= '\0'; j++){
        swap(input[i], input[j]);
        generate_permutations(input, i + 1, s);
        //BACKTRACKING:to restore the original array,swap again
        swap(input[i], input[j]);
    }
}

int main(){
    char input[100];
    cin>>input;
    set<string> s;
    generate_permutations(input, 0, s);
    //after the permute function is over,all the strings are inserted in the set and only unique ones are stored
    //loop over the set
    for(auto str:s){
        cout<<str<<",";
    }
    return 0;
}
