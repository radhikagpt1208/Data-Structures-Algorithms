#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    //key: string ; value: vector of phone numbers
    unordered_map<string, vector<string> > phonebook;
    phonebook["Rahul"].push_back("123");
    phonebook["Rahul"].push_back("1234");
    phonebook["Rahul"].push_back("12345");

    phonebook["Riya"].push_back("321");
    phonebook["Riya"].push_back("4321");
    phonebook["Riya"].push_back("54321");

    for(auto p : phonebook){
        cout<<"Name : "<<p.first<<endl;
        //iterate over the phone numbers of a particular person
        for(string s : p.second){
            cout<<s<<",";
        }
        cout<<endl;
    }

    //query
    string name;
    cin>>name;

    if(phonebook.count(name) == 0){
        cout<<"Name not present";
    }
    else{
        for(string s : phonebook[name]){
            cout<<s<<endl;
        }
    }
    return 0;
}

