/*APPROACH:
 We can do preorder traversal of the given Binary Tree. While traversing the tree, we can recursively calculate HDs.
 We initially pass the horizontal distance as 0 for root.
 For left subtree, we pass the Horizontal Distance as Horizontal distance of root minus 1.
 For right subtree, we pass the Horizontal Distance as Horizontal Distance of root plus 1.
 For every HD value, we maintain a list of nodes in a hash map.
 Whenever we see a node in traversal, we go to the hash map entry and add the node to the hash map using HD as a key in a map */

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node *left, *right;

    node(int d){
    data = d;
    left = right = NULL;
    }
};

//STL containers are passed by value,by default and will make a copy of the map
//so we will have to pass the map STL by reference
void printVerticalOrder(node* root, int d, map<int, vector<int> > &m){
    //base case
    if(root == NULL){
        return;
    }
    // Store current node in map m
    m[d].push_back(root->data);
    // Store nodes in left subtree
    printVerticalOrder(root->left, d-1, m);
    // Store nodes in right subtree
    printVerticalOrder(root->right, d+1, m);
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    //key: distance, value: nodes
    map<int, vector<int> > m;
    int hd = 0;

    cout << "Vertical order traversal"<<endl;
    printVerticalOrder(root, hd, m);

    //keys are sorted
    map<int, vector<int> > :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
            //cout<<it->first<<" : ";
        for(int i = 0 ; i < it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
