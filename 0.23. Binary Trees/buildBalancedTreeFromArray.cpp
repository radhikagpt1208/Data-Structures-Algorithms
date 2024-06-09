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

node* buildTreeFromArray(int *arr, int s, int e){
    //when s>e,you have reached the leaf node
    if(s > e){
        return NULL;
    }

    int mid = (s + e)/2;
    node* root = new node(arr[mid]);
    root->left = buildTreeFromArray(arr, s, mid-1);
    root->right = buildTreeFromArray(arr, mid+1, e);

    return root;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    node* root = buildTreeFromArray(arr, 0, n-1);
    bfs(root);
    return 0;
}
