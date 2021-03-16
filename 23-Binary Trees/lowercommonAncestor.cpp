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
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

//assuming both a and b are present in the tree and all keys are unique
node* lca(node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    //if root itself contains a or b,then it is the lca
    if(root->data == a || root->data == b){
        return root;
    }

    //otherwise search in left and right subtree
    node* left_ans = lca(root->left, a, b);
    node* right_ans = lca(root->right, a, b);

    //if you are getting a non-null value,i.e,an address from both left and right subtree,then that particular root is the lca
    if(left_ans != NULL && right_ans != NULL){
        return root;
    }
    if(left_ans != NULL){
        return left_ans;
    }
    return right_ans;
}

int main(){
    node* root = buildTree();

    cout<<"LCA of 4 and 7 is : "<<lca(root, 4, 7)->data<<endl;
    cout<<"LCA of 6 and 9 is : "<<lca(root, 6, 9)->data<<endl;

    return 0;
}

/*
INPUT
1 2 4 6 -1 -1 7 -1 -1 5 8 -1 -1 9 -1 -1 3 11 -1 -1 10 -1 -1
*/

//APPROACH
//traverse the tree starting from root.
//If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming that both keys are present).
//If root does not match with any of the keys, we recur for left and right subtree.
//The node which has one key present in its left subtree and the other key present in right subtree is the LCA,i.e,
//for a node to be LCA of 2 given nodes,one key should be in the left subtree of that node and the other key should be in the
//right subtree of that node.
// If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.

