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

void print(node* root, int k1, int k2){
	if(root == NULL){
		return;
	}
	if(k1 < root->data){
		print(root->left, k1, k2);
	}
	if(k1 <= root->data && k2 >= root->data){
		cout<<root->data<<" ";
	}
	if(k2 > root->data){
		print(root->right, k1, k2);
	}
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
	cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		node* root = NULL;

		int arr[n];
		for(int i = 0 ; i < n ; i++){
			cin>>arr[i];
			root = insertInBST(root, arr[i]);
		}
		cout<<"# Preorder : ";
		preorder(root);

		cout<<endl;

		int k1, k2;
		cin>>k1>>k2;
		cout<<"# Nodes within range are : ";
		print(root, k1, k2);
	}
	return 0;
}
