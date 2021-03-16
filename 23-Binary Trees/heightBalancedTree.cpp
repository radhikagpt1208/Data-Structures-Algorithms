#include<iostream>
#include<cmath>
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
    if(d == -1){
        return NULL;
    }
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

//we will return the height as well as if the respective node is balanced or no in the following bottom up approach
class Pair{
public:
    int height;
    bool balance;
};

Pair isBalanced(node* root){
    Pair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);

    p.height = max(left.height, right.height) + 1;

    if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }

    return p;
}

int main(){
    node* root = buildTree();
    if(isBalanced(root).balance){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
    return 0;
}
