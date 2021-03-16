#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    for(int i = 1; i <= 5; i++){
        q.push(i);
    }

    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    while(!q.empty()){
        cout<<q.front()<<"<-";
        q.pop();
    }
    return 0;
}
