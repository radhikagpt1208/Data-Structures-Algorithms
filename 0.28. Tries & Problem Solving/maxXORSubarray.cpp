/* Problem Statement : Given an array of integers. find the maximum XOR sub array value in given array.
                       Expected time complexity O(n). */

#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

class node{
public:
    node* left;   //for 0
    node* right;  //for 1

    node(){
    left = right = NULL;
    }
};

class trie{
public:
    node* root;
    trie(){
        root = new node();
    }
    void insert(int n){
        node* temp = root;
        for(int i = 31; i >= 0; i--){
            int bit = (n>>i)&1;
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else{
                //if bit is 1
                if(temp->right == NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    //this function finds that what is the max xor that you can create using one of the numbers that is passed in func
    //and one by one pairing it with the rest of the numbers inserted in the trie
    int max_xor_helper(int value){
        node* temp = root;
        int current_ans = 0;
        for(int j = 31; j >= 0 ; j--){
            int bit = (value>>j)&1;
            if(bit == 0){
                if(temp->right){
                    temp = temp->right;
                    //contribution of 1 will be 2^j =  1<<j
                    current_ans += (int)pow(2,j);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                //current bit is 1
                if(temp->left){
                    temp = temp->left;
                    current_ans += (int)pow(2,j);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor_subarray(int *arr, int n){
        //insert all the values of cum_xor calculated in the trie
        int max_subarray_xor = 0;
        int cum_xor = 0;
        for(int i = 0; i < n; i++){
            cum_xor = cum_xor ^ arr[i];
            insert(cum_xor);
            //find out what is the max xor you can make using this value
            int current_xor = max_xor_helper(cum_xor);
            if(current_xor > max_subarray_xor){
                max_subarray_xor = current_xor;
            }
        }
        return max_subarray_xor;
    }
};

int main(){
    trie t;
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<t.max_xor_subarray(arr, n);

    return 0;
}
