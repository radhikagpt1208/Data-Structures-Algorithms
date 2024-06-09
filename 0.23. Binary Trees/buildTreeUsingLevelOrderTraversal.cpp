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
	queue<node*> q;
	node* root = NULL;

	int d;
	cin>>d;
	if(d == -1){
		return root;
	}
	root = new node(d);
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		cin>>d;

		if(d != -1){
			temp->left = new node(d);
			q.push(temp->left);
		}
		else{
			temp->left = NULL;
		}
		cin>>d;
		if(d != -1){
			temp->right = new node(d);
			q.push(temp->right);
		}
		else{
			temp->right = NULL;
		}
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

int main() {

	node* root = buildTree();

	bfs(root);
	return 0;
}
