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

node* createTreeFromTrav(int *pre, int *in, int s, int e){
    //static pointer is used for traversing over the pre order array so that whenever the function is called,i is initialized
    //with the last value of i,rather than 0
    static int i = 0;
    //base case
    if(s > e){
        return NULL;
    }
    //Rec case
    node* root = new node(pre[i]);

    //for traversing in the in-order array
    int inIndex = -1;
    for(int j = s ; j <= e ; j++){
        if(in[j] == pre[i]){
            inIndex = j;
            break;
        }
    }
    //to increment the index in the pre-order array
    i++;
    root->left = createTreeFromTrav(pre, in, s, inIndex-1);
    root->right = createTreeFromTrav(pre, in, inIndex+1, e);

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
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int n = sizeof(pre)/sizeof(pre[0]);

    node* root = createTreeFromTrav(pre, in, 0, n-1);
    bfs(root);

    return 0;
}

//HINT:
//In a Preorder sequence, leftmost(first element)element is the root of the tree.
//By searching this element which is the root of the tree in Inorder sequence,
//we can find out all elements on left side of the root are in left subtree and elements on right are in right subtree.

/*ALGORITHM:
1) Pick an element from Preorder. Increment the Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the piked element's index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode. */


