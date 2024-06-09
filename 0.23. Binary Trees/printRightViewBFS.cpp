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

void printRightView(node* root){
    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        //no. of nodes at the current level
        int n = q.size();
        //traverse all nodes of current level
        for(int i = 1; i <= n; i++){
            node* temp = q.front();
            q.pop();

            // Print the right most element at the level
            if(i == n){
                cout<<temp->data<<" ";
            }
            //push the children of temp
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

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

int main(){
    node* root = buildTree();
    bfs(root);
    printRightView(root);
    return 0;
}
