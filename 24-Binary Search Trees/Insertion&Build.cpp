#include<iostream>
#include<queue>
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

//INSERTION
//accepts the old root node and data and return a new root node
node* insertInBST(node* root, int data){
    if (root == NULL){
        //place the first element as the root
        return new node(data);
    }
    //otherwise,check if d is >,< or = root
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

//SEARCHING
bool search(node* root, int data){
    //if data does not exist
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    //rec call on left and right subtrees depending on whether data is > = or <
    if(data <= root->data){
        bool left = search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

//DELETION
node* deleteNode(node* root, int data){
    //if the node does not exists
    if(root == NULL){
        return NULL;
    }
    //search for the data to be deleted
    if(data < root->data){
        root->left = deleteNode(root->left, data);
        return root;
    }
    //if you have found the node
    else if(data == root->data){
        //there might be 3 cases
        //1. node to be deleted has 0 children,i.e,the case of leaf node
        if(root->left == NULL && root->right == NULL){
            //delete the node and return NULL to its parent node
            delete root;
            return NULL;
        }

        //2.node to be deleted has 1 child
        //a. left child exists,right child does not
        if(root->left != NULL && root->right == NULL){
            //copy the child in temp,delete the node and return temp to the parent node to attach the child to correct position
            node* temp = root->left;
            delete root;
            return temp;
        }
        //b. left child does not exist,right child exists
        if(root->left == NULL && root->right != NULL){
            //copy the child in temp,delete the node and return temp to the parent to attach the child to the correct position
            node* temp = root->right;
            delete root;
            return temp;
        }

        //3. node to be deleted has 2 children
        //after deleting the root with 2 children,you have to choose an appropriate node to become the root so that the
        //binary tree remains the same
        //2 options of choosing the node to become the root:
        //(1)max element in left subtree: move to the left of the root and then keep moving right until you reach the leaf node
        //(2)min element in right subtree: move to the right of the root and then keep moving left until you reach leaf node
        //follow step (2.2)
        node* replace = root->right;
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        //delete the node that has replaced now
        //right side of the newly made root will point to a new subtree which does not contain the replaced node
        root->right = deleteNode(root->right, replace->data);
        return root;
    }
    else{
        //search in the right subtree
        root->right = deleteNode(root->right, data);
        return root;
    }
}

//level order print
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();

            //check if 'f' has children or no
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
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
    node* root = buildBST();
    inOrder(root);
    cout<<endl;
    bfs(root);

    int key;
    cin>>key;
    if(search(root, key)){
        cout<<"Present";
    }
    else{
        cout<<"Not Present";
    }

    int del;
    cin>>del;
    root = deleteNode(root, del);
    inOrder(root);
    cout<<endl;
    bfs(root);

    return 0;
}
