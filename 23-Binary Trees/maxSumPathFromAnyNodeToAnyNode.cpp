/* Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree */

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

class Pair{
public:
    //return 2 things to the next node: (1) max sum that can be formed. (2) max branch sum that can be formed
    //branch sum:the sum of a branch,i.e,starting from the root to any node in the left or the right subtree
    int branchSum;
    int maxSum;

    Pair(){
        branchSum = maxSum = 0;
    }
};

Pair maxSumPath(node* root){
    Pair p;
    //if you have crossed the leaf nodes,the max and branch sum will be 0
    if(root == NULL){
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    //calculate the max path sum for the given root node,i.e,cases for the max sum to pass through the root
    //1.if the sum from both the subtrees come out to be negative,it is better to just take the root
    int option1 = root->data;
    //2.if the sum from the right subtree is -ve
    int option2 = root->data + left.branchSum;
    //3.if the sum from the left subtree is -ve
    int option3 = root->data + right.branchSum;
    //if sum of both the subtrees is +ve
    int option4 = root->data + right.branchSum + left.branchSum;

    int current_ans_through_root = max(option1, max(option2, max(option3, option4)));

    //calculate the branch sum to return to the current root node
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

    return p;
}

int main(){
    node* root = buildTree();

    cout<<"Maximum sum path "<< maxSumPath(root).maxSum << endl;
    return 0;
}

