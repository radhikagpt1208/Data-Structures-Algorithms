#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[] = "abcdefcghijkzyxz";
    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;

    int visited[256];
    //initialize the array with -1 to denote that no char has been visited even once
    for(int i = 0; i < 256; i++){
        visited[i] = -1;
    }

    //for the first char that is now visited once,we update in the visited array
    visited[a[0]] = 0;

    //for the remaining characters
    for(int i = 1; i < n; i++){
        //check the last occ of that char
        int last_occ = visited[a[i]];

        //Expansion case: if the char has not occurred even once and is not a part of the current window
        if(last_occ == -1 || last_occ < i - current_len){
            current_len += 1;
        }
        //Expansion + Contraction : if the char has occurred,you will shrink the window
        else{
            if(current_len > max_len){
                max_len = current_len;
            }
            current_len = i - last_occ;
        }
        //when you are going to the next pos,you have to update the visited arr for the current index
        visited[a[i]] = i;
    }
    if(current_len > max_len){
        max_len = current_len;
    }
    cout<<max_len<<endl;

    return 0;
}
