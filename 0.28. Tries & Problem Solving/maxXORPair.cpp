/* PROBLEM STATEMENT:
 Given an array Arr of non-negative integers of size N. The task is to find the pair which has the maximum value of XOR

 APPROACH:
 The goal is to have maximum number of 1's in the ans that you're getting after calculating XOR from left to right
 (from MSB's to LSB's),i.e, more number of 1's are required at MSB positions because on going left, the powers of 2 increases
 and hence the value of the number increases.
 For every number inserted in the array, we will match it with such an element such that the XOR value has max no of 1's
 from left to right */

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    //no need to explicitly save data
    Node* left;    //every time I got to the left,it will signify that the node contains data 0
    Node* right;   //every time I got to the right,it will signify that the node contains data 1
};

class trie{
public:
    Node* root;

    trie(){
        root = new Node();
    }

    //insert all the bits of a particular number starting from the MSB to LSB in the trie
    void insert(int n){
        Node* temp = root;
        //assuming 32 bits integers
        for(int i = 31; i >= 0; i--){
            //to extract the i-th bit from right from the binary representation of a number
            int bit = (n>>i)&1;
            if(bit == 0){
                //you have to insert in the left,but it is also possible that 0 already exists in the left
                //if left node does not exist
                if(temp->left == NULL){
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else{
                //bit is 1
                if(temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    //helper function to find max xor
    int max_xor_helper(int value){
        Node* temp = root;
        //this function finds that what is the max xor that you can create using one of the numbers as the value passed in func
        //and pairing it with the rest of the numbers
        int current_ans = 0;
        for(int j = 31; j >= 0 ; j--){
            int bit = (value>>j)&1;
            //while calculating xor,if the bits are diff(eg: 0 and 1 or 1 and 0) then ans will be 1 and if the bits are
            //same the ans will be 0
            if(bit == 0){
                //find a complementary value,i.e, 1 so that the ans comes out to be 1
                if(temp->right != NULL){
                    //if the right node is not null,i.e, there is a 1, you go to that node
                    temp = temp->right;
                    //contribution of 1 will be 2^j =  1<<j
                    current_ans += (1<<j);
                }
                else{
                    //if the right node is not 1,you go the left and take a node with data 0.
                    //However this node does not contribute to the ans as 0^0 = 0
                    temp = temp->left;
                }
            }
            else{
                //current bit is 1
                //find a complementary value,i.e, 0 so that the ans comes out to be 1
                if(temp->left != NULL){
                    //if the left node is not null,i.e, there is a 0, you go to that node
                    temp = temp->left;
                    current_ans += (1<<j);
                }
                else{
                    //if the left node is not 0,you go the right and take a node with data 1.
                    //However this node does not contribute to the ans as 1^1 = 0
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor(int *input, int n){
        int max_xor = 0;
        for(int i = 0; i < n; i++){
            int val = input[i];
            insert(val);
            //find out what is the max xor you can make using this value
            int current_xor = max_xor_helper(val);
            cout<<current_xor<<" ";
            max_xor = max(current_xor, max_xor);
        }
        cout<<endl;
        return max_xor;
    }
};

int main(){
    int input[] = {3, 10, 5, 25, 2, 8};
    trie t;
    cout<<t.max_xor(input, 6)<<endl;
    return 0;
}
