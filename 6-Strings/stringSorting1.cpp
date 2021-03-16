#include<iostream>
#include<string>
#include<algorithm>   //for inbuilt sort
using namespace std;

//To compare on the basis of length
bool compare(string a,string b){
    if(a.length()==b.length()){
        return a<b;   //to compare lexicographically
    }
    return a.length()>b.length();
}

int main(){
    int n;
    cin>>n;
    cin.get();   //to consume extra new line

    string s[1000];

    for(int i=0; i<n; i++){
        getline(cin , s[i]);   //for string class
    }

    sort(s, s+n, compare);

    for(int i=0; i<n; i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
