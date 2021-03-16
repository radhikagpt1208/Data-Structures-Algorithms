/* APPROACH 3: O(N) time complexity and O(N) space complexity
1. Streak is a term used for all the consecutive subsequences we can make in an array
2. For any streak to be unique, we can define that streak with 2 parameters: Left Boundary and Right Boundary
3. So a streak can be uniquely identified as well as generated using these 2 parameters
4. Starting from the first element,build a streak by using a hash map,say m,in which for every element,
   we store the length of the streak that exists for that element.
5. For every element arr[i] in the array,check if there is any element for which arr[i] might become the new RB or the new LB
   i.e, if m.get(arr[i]-1) exists,then arr[i] can become the new RB and if m.get(arr[i]+1) exists,then arr[i] can become LB for
   that particular element.
6. Hence,the new streak length = 1+ len1 + len2 where len1:length by becoming the new RB ; len2:length by becoming new LB
7. Update the hash map by inserting the current element with the new streak length
8. If we are updating the current value with the new streak length ,then we will have to update the length of original
   LB and RB as well by getting the value of len1 and len2
9. If an element arr[i] becomes the new RB fro a streak, then we will have to update the value of the original LB also which will
   be = (currentElement-len1) For eg: if we get an element 7 and 6 and 5 are already present in the map,
   then 7 will become the new RB for this streak and we will first insert 7 with value 3 and then we will update the
   length of 5 as well with the new streak length(no need to update the streak length of 6)
10.If an element arr[i] becomes the LB, then we will have to update the value of the original RB also which will
   be = (currentElement+len2)
   NOTE : In some cases for arr[i],it is possible that both arr[i]-1 and arr[i]+1 exist. For such a case, we will have to update
   the length of both the original LB as well as RB.
11. Finally traverse the map and find the max value of length stored */

#include<iostream>
#include<unordered_map>
using namespace std;

int longestConsSubseq(int arr[], int n){
    //key:element and value: streak length of the element
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        int ele = arr[i];
        int left = ele - 1;
        int right = ele + 1;
        //if neither n-1 nor n+1 is present
        if(m.find(left) == m.end() && m.find(right) == m.end()){
            //n will become a new streak of length 1
            m[ele] = 1;
        }
        //if the number is n, then n-1 and n+1 both are present
        else if(m.find(left) != m.end() && m.find(right) != m.end()){
            int left_streak_len = m[ele-1];
            int right_streak_len = m[ele+1];
            int new_streak_len = left_streak_len + 1 + right_streak_len;
            //increment the streak length of the LB and the RB(nos. in between don't matter)
            m[ele - left_streak_len] = new_streak_len;
            m[ele + right_streak_len] = new_streak_len;
        }
        //if only n-1 is present
        else if(m.find(left) != m.end() && m.find(right) == m.end()){
            int left_streak_len = m[ele-1];
            //update the streak len of the no.
            m[ele] = left_streak_len + 1;
            //update the streak len of the LB (nos. in between don't matter)
            m[ele - left_streak_len] = left_streak_len + 1;;
        }
        //if only n+1 is present
        else if(m.find(left) == m.end() && m.find(right) != m.end()){
            int right_streak_len = m[ele+1];
            //update the streak len of the no.
            m[ele] = right_streak_len + 1;
            //update the streak len of the RB (nos. in between don't matter)
            m[ele + right_streak_len] = right_streak_len + 1;;
        }
    }
    int largest = 0;
    for(auto p : m){
        largest = max(largest, p.second);
    }
    return largest;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<longestConsSubseq(arr, n)<<endl;
}
