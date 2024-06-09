//APPROACH 1
//The distance between two nodes can be obtained in terms of lowest common ancestor with the following formula:
//= distance from the root to n1 plus the distance from the root to n2 minus twice the distance from the root to their lca
//Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)

//APPROACH 2: Better Solution
//We first find LCA of two nodes. Then we find distance from LCA to two nodes and the sum of the 2 path length is the answer

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

node* LCA(node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a || root->data == b){
        return root;
    }
    node* left_ans = LCA(root->left, a, b);
    node* right_ans = LCA(root->right, a, b);

    if(left_ans != NULL && right_ans != NULL){
        return root;
    }
    if(left_ans != NULL){
        return left_ans;
    }
    return right_ans;
}

//Returns level of key k if it is present in tree, otherwise returns -1
int findLevel(node* root, int k, int level) {
    if(root == NULL){
        return -1;
    }
    if(root->data == k){
        return level;
    }
    //search for the node in the left and right subtree
    int left = findLevel(root->left, k, level+1);
    if (left != -1){
        return left;
    }
    //if the node is not found in the left subtree,find in the right subtree
    return findLevel(root->right, k, level+1);
}

int shortestDistance(node* root, int a, int b) {
    node* lca = LCA(root, a , b);

    //find the distance from lca to the 2 nodes
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);

    return d1 + d2;
}

int main(){
    node* root = buildTree();

    cout<<"Distance between 4 and 7 is : " <<shortestDistance(root, 4, 7)<<endl;
    cout<<"Distance between 6 and 9 is : " <<shortestDistance(root, 6, 9);

    return 0;
}

