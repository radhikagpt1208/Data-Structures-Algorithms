#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char d){
        data = d;
        terminal = false;
    }
};

class Trie{
    Node* root;
    int cnt;    //denotes how many words inserted in the trie
public:
    Trie(){
        root = new Node('\0');
        cnt = 0;
    }

    //If the input key is new or an extension of the existing key,we need to construct non-existing nodes of the key,
    //and mark end of the word for the last node.
    //If the input key is a prefix of existing key in Trie,we simply mark the last node of the key as the end of word.
    void insert(char *w){
        Node* temp = root;
        for(int i = 0; w[i] != '\0'; i++){
            //check whether the current char is present or no
            char ch = w[i];
            //if the current char exists,move to that char
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                //create a new node for the char
                Node* n = new Node(ch);
                //store the address of this node in the hash map
                temp->children[ch] = n;
                temp = n;
            }
        }
        //we have reached the last node
        temp->terminal = true;
    }

    bool search(char *w){
        Node* temp = root;
        for(int i = 0; w[i] != '\0'; i++){
            //check whether the current char is present or no
            char ch = w[i];
            //if it is not present,return false
            if(temp->children.count(ch) == 0){
                return false;
            }
            else{
                //if it is present, go to that node and search for the next char
                temp = temp->children[ch];

            }
        }
        //at whatever node I'm ending,return true or false depending on if the node is terminal or no
        return temp->terminal;
    }
};


int main(){
    Trie t;
    char words[][10] = {"a", "hello", "not", "news", "apple"};
    char w[10];
    cin>>w;

    for(int i = 0; i < 5; i++){
        t.insert(words[i]);
    }

    if(t.search(w)){
        cout<<"Present";
    }
    else{
        cout<<"Not present";
    }

    return 0;
}
