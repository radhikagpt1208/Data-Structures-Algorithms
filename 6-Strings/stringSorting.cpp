#include<iostream>
#include<string>
#include<algorithm>   //for inbuilt sort
using namespace std;

//To compare lexicographically
int main(){
    int n;
    cin>>n;
    cin.get();   //to consume extra new line

    string s[1000];

    for(int i=0; i<n; i++){
        getline(cin , s[i]);   //for string class
    }

    sort(s, s+n);

    for(int i=0; i<n; i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
