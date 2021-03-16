#include<iostream>
#include<string>
using namespace std;

string replacePi(string str , int i){
    //base case
    if(str.length() <= i+1){
        return str;
    }
    //check for pi
    if(str[i]=='p' && str[i + 1] == 'i'){
        //'substr' func copies the string upto the given index,i.e,if substr(0,i) then it will copy from 0 to i-1
        str = str.substr(0 , i) + "3.14" + str.substr(i + 2);
    }
    //if you don't get pi
    string res = replacePi(str , i + 1);
    return res;
}

int main(){
    string str;
    getline(cin , str);
    str = replacePi(str , 0 );
    cout<<str<<endl;
    return 0;
}

