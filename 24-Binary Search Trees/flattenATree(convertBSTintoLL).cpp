/* Basically we have to make a linked list from the left subtree and the right subtree and join the tail of the LL made from the
left subtree and the head of the LL made from right subtree to the root of the tree.
So we will return the head and the tail node of the LL made from the subtrees and join it to the root.
Case 1: Right subtree does not exist:In this case,make a LL from the left subtree and return the head and tail node. Join the
        root node to the tail of the LL such that effectively the new tail of the final LL is the root.
Case 2: Left subtree does not exist:In this case,make a LL from the right subtree and return the head and tail node. Join the
        root node to the head of the LL such that effectively the new head of the final LL is the root.
Case 3: If you have only a single node(leaf node): In this case, both the head and the tail of the LL will point to this node.
Case 4: You have both left and right subtrees. Make LL from both the subtrees and return the head and tail from both the LL formed.
        Join the root to the tail of the left one and the head of the right one.
Hence, we do a postorder traversal,we first go to the left and make a LL, then go to the right and make a LL and then go to root.
*/
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

node* insertInBST(node* root, int data){
    if (root == NULL){
        return new node(data);
    }
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

//return head and tail from the recursive calls of left and right subtrees
//so we make a class to return a pair
class Pair{
public:
    node* head;
    node* tail;
};

Pair flattenTree(node* root){
    Pair p;

    //case of an empty tree
    if(root == NULL){
        p.head = p.tail = NULL;
        return p;
    }

    //case of a leaf node: both head and tail point to the leaf node
    if(root->left == NULL && root->right == NULL){
        p.head =  p.tail = root;
        return p;
    }

    //when right subtree is null
    if(root->left != NULL && root->right ==NULL){
        //convert left subtree into a linked list
        Pair leftLL = flattenTree(root->left);
        //connect the tail of the link list(made from the left subtree) to the root of the tree
        leftLL.tail->right = root;

        p.head = leftLL.head;
        p.tail = root;

        return p;
    }

    //when left subtree is null
    if(root->left == NULL && root->right != NULL){
        //convert right subtree into a linked list
        Pair rightLL = flattenTree(root->right);
        //connect the root of the tree to the head of the link list(made from the right subtree)
        root->right = rightLL.head;

        p.head = root;
        p.tail = rightLL.tail;

        return p;
    }

    //when none of the subtrees are not null
    //make a linked list from the left as well as from the right subtree
    Pair leftLL = flattenTree(root->left);
    Pair rightLL = flattenTree(root->right);

    //connect the tail of the leftLL to the root and the head of the rightLL to the root
    leftLL.tail->right = root;
    root->right = rightLL.head;

    //make the head of the leftLL the head of the final LL and tail of the rightLL as the tail of the final LL
    p.head = leftLL.head;
    p.tail =  rightLL.tail;

    return p;
}

int main(){
    node* root = buildBST();
    inOrder(root);
    cout<<endl;
    bfs(root);
    cout<<endl;

    Pair p = flattenTree(root);
    node* temp = p.head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    return 0;
}
