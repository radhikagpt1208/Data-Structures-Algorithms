/* PROBLEM STATEMENT
  Given an array of words, find all shortest unique prefixes to represent each word in the given array.
  Assume that no word is prefix of another.

  APPROACH:
  Count the number of words that are starting from every given node
  If this count of words is exactly 1 or this node is a part of a word and the remaining branch forms only one word,
  then that node will be the prefix.

  ALGORITHM:
  1) Construct a Trie of all words. Also maintain frequency of every node.
     (Here frequency is number of times node is visited during insertion).
     Time complexity of this step is O(N) where N is total number of characters in all words.
  2) Now, for every word, we find the character nearest to the root with frequency as 1.
     The prefix of the word is path from root to this character. To do this, we can traverse Trie starting from root.
     For every node being traversed, we check its frequency.
     If frequency is one, we print all characters from root to this node and don't traverse down this node.
     Time complexity if this step also is O(N) where N is total number of characters in all words */

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    int cnt;

    Node(char d){
        data = d;
        terminal = false;
        cnt = 0;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node* temp = root;
        for(int i = 0 ; word[i] != '\0'; i++){
            char ch = word[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
                temp->cnt = temp->cnt + 1;
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->cnt = temp->cnt + 1;
            }
        }
        temp->terminal = true;
    }
};

string findPrefix(string word, Trie t){
    Node* temp = t.root;
    string ans = "";
    for(int i = 0 ; word[i] != '\0'; i++){
        char ch = word[i];
        if(temp->children[ch]->cnt == 1){
            ans = ans + word[i];
            return ans;
        }
        else{
            ans = ans + word[i];
            temp = temp->children[ch];
        }
    }
    ans = "-1";
    return ans;
}

int main(){
    Trie t;
    string words[] = {"cobra", "dog", "dove", "duck", "cobras"};
    int n = sizeof(words)/sizeof(words[0]);

    for(int i = 0; i < n; i++){
        t.insert(words[i]);
    }

    for(int i = 0; i < n; i++){
        cout<<findPrefix(words[i], t)<<" ";
    }
    return 0;
}
