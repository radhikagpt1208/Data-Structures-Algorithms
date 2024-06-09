#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;

    //if you encounter -1 as data,it means return NULL
    if(d == -1){
        return NULL;
    }

    //otherwise,make the root and then the left and right subtree
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}

//In this method,we keep returning the height and diameter of each node

class Pair{
public:
    int height;
    int diameter;
};

Pair diameter(node* root){
    Pair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = diameter(root->left);
    Pair right = diameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

int main(){
    node* root = buildTree();

    Pair p = diameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;

    return 0;
}

