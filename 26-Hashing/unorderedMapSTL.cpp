#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main(){
    unordered_map<string, int> m;

    //1. 3 ways to Insert in a map
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    m["Banana"] = 20;

    //2. Search
    string key;
    cin>>key;

    //3. update the value
    m[key] += 20;

    //this will return an iterator to the key
    //data-type of it = map<string,int> :: iterator(you can write auto instead of the datatype)
    unordered_map<string,int>::iterator it = m.find(key);
    //if key is present in the map
    if(it != m.end()){
        cout<<"Price of "<<key<<" is "<<m[key]<<endl;
    }
    else{
        cout<<key<<" Not Present"<<endl;
    }

    //another way to find a particular key
    //map stores unique keys only once
    //count function will either return 0(key not present) or 1(key is present)
    if(m.count(key)){
        cout<<"Price of "<<key<<" is "<< m[key]<<endl;
    }
    else{
        cout<<key<<" not found"<<endl;
    }

    //4. erase a key
    m.erase(key);

    m["Litchi"] = 60;
    m["Pineapple"] = 80;

    //4. iterate over all the key value pairs
    for(auto it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" -> "<<it->second<<endl;
    }

    /*for each loop
    for(auto p : m){
        cout<<p.first<<" -> "<<p.second<<endl;
    } */
    return 0;
}

