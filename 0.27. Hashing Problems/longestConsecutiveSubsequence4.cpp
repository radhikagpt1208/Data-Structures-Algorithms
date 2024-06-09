/* APPROACH 4: O(N) time and O(N) space
1. Store all the elements of the array in a set so that we can easily check for the presence of an element in the array
   as the elements are stored in sorted order in the set
2. Now start traversing the elements, if there is an element x which is a part of the streak but it is not the LB/starting point,
   then definitely the element (x-1) will exist.
   Hence we can ignore the case when I am at an element x for which x-1 exists and continue further as x can never be the LB
3. Else if I am at an element x for which x-1 does not exist, then definitely x is the LB/starting point for the streak
4. As soon as I get the LB for a streak, we will traverse over the set and run a loop to find the potential RB while
   incrementing the value of x by 1 and checking if x exists in the map along with increasing the count of the length of the streak
5. As soon as I find the RB as well,I will update the ans if required */

#include<iostream>
#include<unordered_set>
using namespace std;

int longestConsecutiveSubsequence(int *arr, int n){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }

    int ans = 0;
    //iterate over all the elements and target those which can start a new streak,i.e, can become the LB of a streak
    for(int i = 0; i < n; i++){
        if(s.find(arr[i] - 1) != s.end()){
            continue;
        }
        else{
            int cnt = 0;
            int x = arr[i];   //Potential LB
            //iterate to find the RB
            while(s.find(x) != s.end()){
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int ans = longestConsecutiveSubsequence(arr, n);
    cout<<ans<<endl;

    return 0;
}
