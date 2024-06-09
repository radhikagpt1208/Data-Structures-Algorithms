#include<iostream>
#include<climits>
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

node* insertInBST(node* root, int data){
    if (root == NULL){
        return new node(data);
    }
    if(data <= root->data){
        root->left = insertInBST(root->left, data);
    }
    else{
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node* buildBST(){
    int d;
    cin>>d;

    node* root = NULL;

    while(d != -1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//the root can have values from (-infinity,+infinity)
bool isBST(node* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    //otherwise,check for every node
    //for a node in the left subtree,it should lie between (-infinity,root)
    //for a node in the right subtree,it should lie between (root,+infinity)
    if(root->data >= min && root->data <= max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max)){
        return true;
    }
    return false;
}

int main(){
    node* root = buildBST();
    inOrder(root);
    cout<<endl;
    if(isBST(root)){
        cout<<"Binary Search Tree";
    }
    else{
        cout<<"Not a BST";
    }
    return 0;
}

//WRONG APPROACH: For each node,check if the left node of it is smaller than the node and right node of it is greater than the node.
//METHOD 1 (Correct but not efficient)
//For each node,check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.
//that is,for each node,the value of node should lie between the max value in the left subtree and min value in the right subtree
//METHOD 2:
//write a utility helper function isBSTUtil(=node* root, int min, int max) that traverses down the tree keeping track
//of the narrowing min and max allowed values as it goes, looking at each node only once.
// The initial values for min and max should be INT_MIN and INT_MAX, they narrow from there.



