//APPROACH
//The first element of preorder traversal is always root. We first construct the root.
//Then we find the index of first element which is greater than root. Let the index be ‘i’.
//The values between root and i will be part of left subtree
//The values between i+1 and n-1 will be part of right subtree.
//Divide given pre[] at index 'i' and recur for left and right sub-trees.

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

node* buildBSTFromPre(int *pre, int s, int e){
    static int i = 0; //to traverse the pre array
    if(s > e){
        return NULL;
    }

    // The first node in preorder traversal is root.
    //So take the node at index 'i' from pre[] and make it root
    node* root = new node(pre[s]);

    //find the next just larger element that the root
    int j;
    for(j = s; j <= e; j++){
        if(pre[j] > root->data){
            break;
        }
    }

    //increment the pointer to traverse the pre array further
    //i++;

    root->left = buildBSTFromPre(pre, s + 1, j - 1);
    root->right = buildBSTFromPre(pre, j , e);

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
    int pre[] = {5, 3, 1, 7, 6, 8};
    int n = sizeof(pre)/sizeof(int);

    node* root = buildBSTFromPre(pre, 0, n-1);
    cout<<"Inorder traversal of the BST formed by preorder traversal array"<<endl;
    inOrder(root);

    return 0;
}
