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
         left = NULL;
         right = NULL;
     }
};

node* buildBSTFromPre(int pre[], int min, int max, int n){
    static int i = 0;   //traverse the pre array
    if(i >= n){
        return NULL;
    }
    node* root = new node(pre[i]);
    i++;
    if(pre[i] >= min && pre[i] <= root->data){
        root->left = buildBSTFromPre(pre, min, root->data, n);
    }
    if(pre[i] >= root->data && pre[i] <= max){
        root->right = buildBSTFromPre(pre, root->data, max, n);
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

int main(){
    int pre[] = {8,5,1,7,10,12};
    int n = sizeof(pre)/sizeof(int);

    node* root = buildBSTFromPre(pre,INT_MIN, INT_MAX, n);
    cout<<"Inorder traversal of the BST formed by preorder traversal array"<<endl;
    inOrder(root);

    return 0;
}
