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

void printPreOrder(node* root){
    if(root == NULL){
        return;
    }
    //otherwise,print the ROOT followed by LEFT sub-tree and then RIGHT sub-tree
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(node* root){
    if(root == NULL){
        return;
    }
    //otherwise,print the LEFT subtree followed by the ROOT and then the RIGHT subtree
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(node* root){
    if(root == NULL){
        return;
    }
    //otherwise,print the LEFT subtree followed by the RIGHT subtree and then the ROOT
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

//Height of the tree
int height(node* root){
    if(root == NULL){
        return 0;
    }
    //height of left subtree
    int ls = height(root->left);
    //height of right subtree
    int rs = height(root->right);
    //+1 for the root node
    return max(ls, rs) + 1;
}

void printKthLevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void printLevelOrder(node* root){
    int h = height(root);
    for(int i = 1 ; i <= h ; i++){
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}

int main(){
    node* root = buildTree();
    printPreOrder(root);
    cout<<endl;
    printInOrder(root);
    cout<<endl;
    printPostOrder(root);
    cout<<endl;

    cout<<height(root)<<endl;

    printKthLevel(root, 3);
    cout<<endl;

    printLevelOrder(root);

    return 0;
}
