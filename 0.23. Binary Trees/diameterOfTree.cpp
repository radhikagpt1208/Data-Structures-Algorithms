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

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    //left sub-tree
    int h1 = height(root->left);
    int h2 = height(root->right);

    //Case 1:if the diameter passes through the root
    int option1 = h1 + h2;
    //Case 1:if the diameter passes through the left subtree
    int option2 = diameter(root->left);
    //Case 1:if the diameter passes through the right subtree
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

int main(){
    node* root = buildTree();
    cout<<diameter(root);
    return 0;
}
