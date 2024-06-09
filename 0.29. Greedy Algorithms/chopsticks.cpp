/* Problem :
Given N sticks of length L[1],L[2],..,L[N] & a positive integer D(two sticks in a pair of chopsticks need not be of same length)
A pair of sticks can be used to eat as long as the difference in their length is at most D.
The Chef has N sticks in which the ith stick is L[i] units long. A stick can't be part of more than one pair of chopsticks.
Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.
Input :
The first line contains two space-separated integers N and D. The next N lines contain one integer each, the ith line giving the
value of L[i].
Output :
Output a single line containing the maximum number of pairs of chopsticks the Chef can form.
Constraints :
    1 ≤ N ≤ 100,000 (10 5 )
    0 ≤ D ≤ 1,000,000,000 (10 9 )
    1 ≤ L[i] ≤ 1,000,000,000 (10 9 ) for all integers i from 1 to N

Greedy Approach:
1. Sort the list of sticks according to their lengths.
2. If L[1] and L[2] cannot be paired,L[1] is useless  because if it cannot be paired with the nearest chopstick,it can't be
   paired with the rest of them because the difference in length keeps on increasing. So move forward by i = i + 1
3. Else pair L[1] and L[2] and remove them from the list. Move forward by i = i + 2
4. Repeat steps 2-3 till the list become empty. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n, d, data;
    cin>>n>>d;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin>>data;
        v.push_back(data);
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    for(int i = 0; i < n - 1;){
        if(v[i + 1] - v[i] <= d){
            cnt++;
            i = i + 2;
        }
        else{
            i = i + 1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}




