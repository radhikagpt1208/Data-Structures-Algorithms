#include<iostream>
#include<string>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* insert(){
	int d;
	string value;
	cin>>d>>value;
	node* root = new node(d);
	if(value == "true"){
		root->left = insert();
	}
	cin>>value;
	if(value == "true"){
		root->right = insert();
	}
	return root;
}

bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }

    bool isSameVal = root1->val==root2->val;
    bool ls = isSameTree(root1->left, root2->left);
    bool rs = isSameTree(root1->right, root2->right);

    return isSameVal && ls && rs;
}

int main() {
	node* root1 = NULL;
	node* root2 = NULL;
	root1 = insert();
	root2 = insert();

	if(isSameTree(root1, root2)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}

