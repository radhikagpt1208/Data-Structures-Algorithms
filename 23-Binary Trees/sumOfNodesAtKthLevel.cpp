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
	int data, cnt;
	cin>>data>>cnt;

	node* root = new node(data);
	if(cnt == 0){
		return root;
	}
	else if(cnt == 1){
		root->left = buildTree();
	}
	else if(cnt == 2){
		root->left = buildTree();
		root->right = buildTree();
	}
	return root;
}

int sumOfNodesAtKlevel(node* root, int k){
	if(root == NULL){
		return 0;
	}
	queue<node*> q;
	q.push(root);

	int curr_level = 0, sum = 0;

	while(!q.empty()){
        // Calculate the number of nodes in the current level
		int size = q.size();
		// Process each node of the current level and enqueue their left and right child to the queue
		while(size--){
			node* temp = q.front();
			q.pop();

			if(curr_level == k){
				sum += temp->data;
			}
			else{
				if(temp->left){
					q.push(temp->left);
				}
				if(temp->right){
					q.push(temp->right);
				}
			}
		}
		curr_level++;
	}
	return sum;
}

int main() {
	node* root = buildTree();
	int d, cnt, level;
	cin>>level;

	int sum = sumOfNodesAtKlevel(root, level);
	cout<<sum;
	return 0;
}
