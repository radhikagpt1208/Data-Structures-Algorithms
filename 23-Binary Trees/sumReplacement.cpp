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

int sumReplace(node* root){
    if(root == NULL){
        return 0;
    }
    //leaf nodes
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int leftSum = sumReplace(root->left);
    int rightSum = sumReplace(root->right);

    int temp = root->data;

    root->data = leftSum + rightSum;

    return temp + root->data;
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
    cout<<endl;
    sumReplace(root);
    bfs(root);
    return 0;
}
