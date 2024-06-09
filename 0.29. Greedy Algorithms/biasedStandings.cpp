/* Problem Statement :
Usually,results of competitions are based on the scores of participants.However,we are planning a change for the next year of IPSC.
During the registration each team will be able to enter a single positive integer : their preferred place in the rank list.
We would take all these preferences into account, and at the end of the competition we will simply announce a rank list that would
please all of you.
But wait. How would that rank list look like if it won't be possible to satisfy all the requests?
Suppose that we already have a rank list. For each team, compute the distance between their preferred place and their place in the
rank list. The sum of these distances will be called the badness of this rank list.
Problem Specification :
Given team names and their preferred placements find one rank list with the minimal possible badness.
Input specification :
The first line of the input file contains an integer T specifying the number of test cases.
Each test case looks as follows: The first line contains N : the number of teams participating in the competition.
Each of next N lines contains team name(string of letters & numbers)and its preferred place(an integer between 1 and N,inclusive). No two team names will be equal.
Output specification :
For each of the test cases output a single line with a single integer : the badness of the best rank list for the given teams.
 */

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    int arr[100000] = {0};
    int t, n;
    cin>>t;

    while(t--){
        //for each test case reset the frequency array to 0
        memset(arr, 0, sizeof(arr));
        cin>>n;
        string name;
        int rank;  //preferred rank of the team
        for(int i = 0; i < n; i++){
            cin>>name>>rank;
            //update the freq array
            arr[rank]++;
        }
        //Assign the team the nearest rank available
        int actual_rank = 1;
        int sum = 0;
        //go to every bucket and while it does not become empty
        for(int i = 1; i <= n; i++){
            while(arr[i]){
                sum += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;    //so that the this rank is not available for next team
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
