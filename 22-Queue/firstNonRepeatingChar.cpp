/*APPROACH
1. Insert every character in the queue and update the frequency map simultaneously.
2. While inserting,look at the queue front. If it has a freq of 1 in the table,print it else  keep on popping the elements
   until you a char who's freq is 1 and then print it
   (if you subtract 'a' from the ascii value of a char,you will get an integer index) */

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<char> q;
    int freq[27] = {0};   //mapping of characters acc to the index

    //keep taking input a running stream of characters until you get a  '.'
    char ch;
    cin>>ch;
    while(ch != '.'){
        //insert the char in the queue
        q.push(ch);
        //update the freq table
        freq[ch - 'a']++;

        //handle the query
        while(!q.empty()){
            int idx = q.front() - 'a';  //to get an int index of the char at the front
            if(freq[idx] > 1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        //queue is empty and you did not find any char with freq 1
        if(q.empty()){
            cout<<"-1"<<endl;
        }

        cin>>ch;
    }

    return 0;
}
