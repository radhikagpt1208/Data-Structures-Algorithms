/* Problem Statement :
There are n circles arranged on x-y plane. All of them have their centers on x-axis.
You have to remove some of them, such that no two circles are overlapping after that.
Find the minimum number of circles that need to be removed.
-> Input Format :
First line contains a single integer, n, denoting the number of circles.
Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).
->Approach :
This question can be mapped to the activity selection problem. Hence we calculate the start point and end point of every circle
where start point = c - r ; end point = c + r.
We will then sort the array on the basis of end point and always pick the first circle because there will be no circle preceding
it,hence it will not overlap with any circle on its left.
We check for the rest of the circles,if the start point of the (i+1)th circle is greater than or equal to the end point of (i)th
circle, then we keep the circle,else we remove it. */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    int n, r, c, start, end;
    cin>>n;
    vector< pair<int,int> > v;
    for(int i = 0; i < n; i++){
        cin>>c>>r;
        start = c - r;
        end = c + r;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), compare);

    int cnt = 1;     //always keep the first circle
    int end_point = v[0].second;
    for(int i = 1; i <= n - 1 ; i++){
        if(v[i].first >= end_point){
            cnt++;
            end_point = v[i].second;
        }
    }

    int ans = n - cnt;       //subtract the number of non-overlapping circles from the total number of circles
    cout<<ans<<endl;

    return 0;
}

