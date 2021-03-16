#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printRightView(node* root, int level, int &maxLevel){
    if(root == NULL){
        return;
    }

    if(level > maxLevel){
        //we are on a new level and hence on moving from right to left,the current node that we are on is the right most node
        cout<<root->data<<" ";
        //update the value of max level
        maxLevel = level;
    }
    //otherwise,traverse in the following manner: root,right,left
    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
}

int main(){
    node* root = buildTree();
    int maxLevel = -1;
    printRightView(root, 0, maxLevel);

    return 0;
}

//APPROACH:
//keep track of level of a node by passing a parameter to all recursive calls.
//keep track of maximum level also.
//traverse the tree in a manner that right subtree is visited before left subtree.
//Whenever we see a node whose level is more than maximum level so far,
//we print the node because this is the last node in its level
//(Note that we traverse the right subtree before left subtree).

