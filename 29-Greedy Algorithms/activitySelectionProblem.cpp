/* Problem : You are given n activities with their start and finish times. Select the maximum number of activities that can be
             performed by a single person, assuming that a person can only work on a single activity at a time.
Greedy Approach :
1. The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and
   the start time is more than or equal to the finish time of previously selected activity.
2. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing
   time activity. */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// A utility function that is used for sorting activities according to finish time
bool compare(pair<int, int>A1, pair<int, int>A2){
    return A1.second < A2.second;
}

int main(){
    //n : no. of activities each given with its start and end time
    int t, n, start, finish;
    cin>>t;

    vector< pair< int, int> > v;

    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>start>>finish;
            v.push_back(make_pair(start, finish));
        }

        //Sort acc to finish time
        sort(v.begin(), v.end(), compare);

        //Start picking activities
        //always have to pick the first activity
        int cnt = 1;    //stores the number of activities that can be done
        int fin = v[0].second;

        //iterate over the remaining activities
        for(int i = 1; i < n; i++){
            if(v[i].first >= fin){
                fin = v[i].second;
                cnt++;
            }
        }
        cout<<cnt<<endl;
        v.clear();
    }

    return 0;
}

