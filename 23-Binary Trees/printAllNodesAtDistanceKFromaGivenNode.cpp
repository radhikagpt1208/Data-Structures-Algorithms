/* APPROACH
There are two types of nodes to be considered.
1.Nodes that lie below the target node at a distance k(Nodes in the subtree rooted with target node)
  For these nodes,Just traverse subtrees rooted with the target node and decrement k in recursive call.
  When the k becomes 0, print the node currently being traversed by calling the function as printNodesBelowThisNode().
2.Other nodes, may be an ancestor of target, or a node in some other subtree(in which the target node does not lie)
  For the output nodes not lying in the subtree with the target node as the root, we must go through all ancestors.
  For every ancestor,we find how far is the target node present in a subtree of the ancestor from the root node of that subtree.
  let this distance be d.
  Now we go to other subtree(if target was found in left subtree, then we go to right subtree and vice versa) of the ancestor and
  find all nodes at (k-d-2)distance from the ancestor.
  -2 because we know that the root of the subtree of the ancestor lies at a distance 1 from the ancestor and the root of the
  other subtree in which we will find the nodes will also be at a distance 1 from the ancestor.
  The final node we get might be the ancestor itself(if d+1==k)or a node in the subtree. */

#include<iostream>
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

node* buildTree(int *pre, int* inorder, int s, int e){
	static int i = 0;
	if(s > e){
		return NULL;
	}
	node* root = new node(pre[i]);

	int idx = -1;
	for(int j = s; j <= e ; j++){
		if(pre[i] == inorder[j]){
			idx = j;
			break;
		}
	}
	i++;
	root->left = buildTree(pre, inorder, s, idx - 1);
	root->right = buildTree(pre, inorder, idx + 1, e);

	return root;
}

void printNodesBelowThisNode(node* root, int k){
	if(root == NULL || k < 0){
		return;
	}

	if(k == 0){
		cout<<root->data<<" ";
	}

	printNodesBelowThisNode(root->left, k-1);
	printNodesBelowThisNode(root->right, k-1);
}

int printNodesAtDistanceK(node* root, int d, int k ){
	if(root == NULL){
		return -1;
	}
	//target node is found
	if(root->data == d){
		printNodesBelowThisNode(root, k);
		//return the distance of the target node to the root node of the subtree to the parent
		//(dist b/w the root node of this subtree and the target node)
		//when root == target node, we know that the distance of the target node from the root of the subtree will be 0.
		//so we will return a distance of 0 to the parent of the target node because 0 will denote that in the subtree of the parent,
		//the target node is present at 0 distance from the root of the subtree
		return 0;
	}

    //now we are going back to the ancestors
    //ask the ancestor to find the target node in the left and right subtrees
    //dl = distance of target node in the left subtree
	int dl = printNodesAtDistanceK(root->left, d, k);
	//if target node is present in the left subtree
	if(dl != -1){
		//2 cases:either the ancestor itself be the ans or you need to go to the right of the ancestor
		if(dl + 1 == k){
            cout<<root->data<<" ";
		}
		else{
            printNodesBelowThisNode(root->right, k - 2 - dl);
		}
		//return distance of the target node to the parent
		return 1 + dl;
	}
	//dr = distance of target node in the right subtree
	int dr = printNodesAtDistanceK(root->right, d, k);
	if(dr != 1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesBelowThisNode(root->left, k - 2- dr);
        }
        //return distance of the target node to the parent
        return 1 + dr;
	}
	//Target node was not present in left or right subtree
	return -1;
}

int main() {
	int n;
	cin>>n;
	int pre[n];
	for(int i = 0 ; i < n ; i++){
		cin>>pre[i];
	}
	int inorder[n];
	for(int j = 0 ; j < n ; j++){
		cin>>inorder[j];
	}
	node* root = buildTree(pre, inorder, 0, n-1);

	int t;
	cin>>t;

	while(t--){
		int target , k;
		cin>>target>>k;
		printNodesAtDistanceK(root, target, k );

		cout<<endl;
	}
	return 0;
}
