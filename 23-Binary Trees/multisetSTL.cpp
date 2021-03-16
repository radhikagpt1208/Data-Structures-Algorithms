#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;

int main() {

    int arr[] = {10,20,30,20,10,10};
    multiset<int> m(arr,arr+6);

    //3. Erase
    cout<<m.erase(20) <<endl;

    //1. Iterator
    for(int x:m){
        cout<<x<<",";
    }
    cout<<endl;
    //2. Count Function
    m.insert(78);
    cout<< m.count(78) <<endl;

    //4. Find
    auto it = m.find(30);
    cout<<(*it)<<endl;

    for(int x:m){
        cout<<x<<",";
    }
    cout<<endl;

    //5. Equal Range
    //the first It points to the first occurrence of 10 and the second It points to the last occurrence of 10
    pair<It,It> range = m.equal_range(10);
    for(auto it = range.first;it!=range.second;it++){
        cout<<*it<<endl;
    }

    //Lower Bound and Upper Bound
    for(auto it=m.lower_bound(10);it!=m.upper_bound(77);it++){
        cout<<*it<<",";
    }

    return 0;
}

