#include<iostream>
#include<vector>
#include<algorithm>
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
public:
	Node* root;
	Trie(){
		root = new Node('\0');
	}

	void insert(string word){
		Node* temp = root;
		for(int i = 0; word[i] != '\0'; i++){
			char ch = word[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}
			else{
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}

    void print(vector<string> &v, string s, Node* temp){
		//if I have reached the end of the string,push it in the vector
		if(temp->terminal){
			v.push_back(s);
		}
		for(auto it = temp->children.begin() ; it != temp->children.end(); it++){
			s += it->second->data;
			print(v, s, it->second);
			s.pop_back();
		}
	}

	bool search(string s){
		Node* temp = root;
		for(int i = 0; s[i] != '\0'; i++){
			char ch = s[i];
			if(temp->children.count(ch) == 0){
				return false;
			}
			else{
				temp = temp->children[ch];
			}
		}
        //make a DFS call on the trie and store all the words when you come across a terminal node
		vector<string> v;
		print(v, s, temp);
		//print in lexiocographical order
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++){
        	cout<<v[i]<<endl;
    	}
    	return true;
	}
};

int main() {
	Trie t;
	int n;
	cin>>n;

	string s;
	while(n--){
		cin>>s;
		t.insert(s);
	}
	int q;
	cin>>q;
	while(q--){
		cin>>s;
		bool ans = t.search(s);
		if(!ans){
			cout<<"No suggestions"<<endl;
			//insert the word that is not present in the dictionary
			t.insert(s);
		}
	}
	return 0;
}
