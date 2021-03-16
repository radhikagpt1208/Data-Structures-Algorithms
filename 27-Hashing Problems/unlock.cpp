/* Problem Statement :
   Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code.
   He is given a number N and a number K. And he is also given permutation of first N natural numbers .
   The defusal code is the largest permutation possible by doing at most K swaps among a pair of the given permutation.
   Help him to find the final permutation.

APPROACH:
1. Since the numbers that are given in the permutation are the first N natural nos, hence it can be derived that the permutation
   will have nos ranging from [1,N].
2. Also, it can be derived that if K was equal to N, then the largest permutation possible is the arrangement of the given nos.
   in decreasing order.
3. We first store the values mapped with their current index at which they are stored (in the given permutation) in a hash map.
4. Now, we have to perform at the most K swaps to get the required permutation. Hence, we have to put the elements in their
   best positions.
5. The best position of a number 'num' is given by (N-num) where N is the no. given in the question
6. Hence we will traverse a loop from N->1 & extract the best position of every element & swap the element by extracting
   the current index given in the hash map  and also update the index of the element in the hash map after swapping it with
   its best position. */

/* Problem Statement :
   Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code.
   He is given a number N and a number K. And he is also given permutation of first N natural numbers .
   The defusal code is the largest permutation possible by doing at most K swaps among a pair of the given permutation.
   Help him to find the final permutation.

APPROACH:
1. Since the numbers that are given in the permutation are the first N natural nos, hence it can be derived that the permutation
   will have nos ranging from [1,N].
2. Also, it can be derived that if K was equal to N, then the largest permutation possible is the arrangement of the given nos.
   in decreasing order.
3. We first store the values mapped with their current index at which they are stored (in the given permutation) in a hash map.
4. Now, we have to perform at the most K swaps to get the required permutation. Hence, we have to put the elements in their
   best positions.
5. The best position of a number 'num' is given by (N-num) where N is the no. given in the question
6. Hence we will traverse a loop from N->1 & extract the best position of every element & swap the element by extracting
   the current index given in the hash map  and also update the index of the element in the hash map after swapping it with
   its best position. */

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int N, K;
    cin>>N>>K;

    unordered_map<int, int> m;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin>>arr[i];
        m[arr[i]] = i;
    }

    for(int i = N; i > 0; i--){
        if(K > 0){
            int curr_idx = m[i];
            int best_idx = N - i;

            if(best_idx != curr_idx){
                swap(arr[best_idx], arr[curr_idx]);
                K--;
                m[arr[curr_idx]] = curr_idx;
                m[arr[best_idx]] = best_idx;
            }
        }
    }

    for(int i = 0; i < N; i++)
        cout<<arr[i]<<" ";

    return 0;
}
