#include<iostream>
#include<list>
using namespace std;

//TEMPLATE + ITERATOR
//search function using iterators with the return type of a forward iterator
//class ForwardIterator:depends on the type of container used ; class T: depends on the data-type
template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){
    while(start != end){
        if(*start == key){
            return start;
        }
        start++;
    }
    return end;
}

int main(){
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);

    auto it = search(l.begin() , l.end(), 5);
    if(it == l.end()){
        cout<<"Element not present";
    }
    else{
        cout<<*it<<endl;
    }
    return 0;
}

