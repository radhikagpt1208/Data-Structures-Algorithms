 /*
-> Problem Statement:
A group of cows grabbed a truck and ventured on an expedition deep into the jungle.Being rather poor drivers,the cows unfortunately
managed to run over a rock & puncture the truck's fuel tank.The truck now leaks one unit of fuel every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road.
On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can
stop to acquire additional fuel (1..100 units at each stop).
The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum
possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large
that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has
P units of fuel (1 <= P <= 1,000,000).
Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.
-> Input :
The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case
has the following form:
    Line 1 : A single integer, N
    Lines 2.. N+1 : Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from
                  the town to the stop; the second is the amount of fuel available at that stop.
    Line N+2 : Two space-separated integers, L and P

-> Output :
For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town.
If it is not possible to reach the town, output -1.

->Approach :
The first observation is, if you want to reach the city, say, point L, you have to ensure that every single point between the
current position and city must also be reachable. Now, the task is to minimize the number of stoppages for fuel, which is at most
10000. So, we sort the fuel stations, and start from current position.
For every fuel station, if we want to reach it, we must have fuel f more than or equal to the distance d.
Also, using the larger capacities will always reduce the number of stations we must stop.
So we keep on moving and we keep storing the fuel stops that we pass by in a priority queue. If at some point, we are short of fuel
to move forward, we will use the fuel stops that have already passed by which are saved in the priority queue and we will pick the
fuel stop with the max capacity of fuel and then keep on moving.  */

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    //comparing two fuel stations based upon their distance from the town(dist that is closer to the town will be farther away
    //from the truck, so the vector will be sorted in a way that we have distances closer to the truck first)
    return p1.first > p2.first;
}

int main(){
    int t, n, dist, fuel_capacity, D, F, prev, x;
    cin>>t;

    while(t--){
        int flag = 0, ans = 0;     //ans denotes how many stops you have visited
        //store fuel stations and capacities
        vector< pair<int, int> > v;
        //store the capacity of the fuel stations that are passing by
        priority_queue<int> pq;

        cin>>n;     //number of stops

        for(int i = 0; i < n; i++){
            //for n stops, read the location of the fuel station and its capacity
            cin>>dist>>fuel_capacity;
            v.push_back(make_pair(dist, fuel_capacity));
        }

        //Logic
        //sort fuel stations acc to their location
        sort(v.begin(), v.end(), compare);

        //read the initial dist D and the initial capacity of the truck F
        cin>>D>>F;

        //update the distance of the fuel station from the truck
        for(int i = 0; i < n; i++){
            //the vector will store the dist of the fuel station wrt truck in increasing order(i.e,fuel stations nearer to
            //the truck are in the starting of the vector
            v[i].first = D - v[i].first;
        }

        //prev denotes the previous station that we have visited
        prev = 0;
        //current stations that I'm at
        x = 0;

        while(x < n){
            //if we have enough fuel to go to the next town
            if(F >= (v[x].first - prev)){
                //go to the next stop and reduce the capacity by the distance traveled
                F = F - (v[x].first - prev);
                //push the capacity of the stop that you have reached
                pq.push(v[x].second);
                //now you are standing on the next stop
                prev = v[x].first;
            }
            else{
                //if we cannot reach the next stop with the current capacity
                //check if we have any fuel stops already visited(i.e, is there any stop in the priority queue)
                if(pq.empty()){
                    //it is not possible to move forward
                    flag = 1;
                    break;
                }
                //else refuel the truck at the station with the highest capacity
                //add the fuel of the stop having highest capacity to the truck
                F += pq.top();
                //since we can use a stop only once,remove that fuel station from pq
                pq.pop();
                ans = ans + 1;
                continue;
            }
            x++;  //you were able to reach the next stop
        }
        //you have traveled through n fuel stations and now you have to reach the town from the last fuel station
        if(flag == 1){
            cout<<-1<<endl;
            continue;
        }
        //otherwise check if we can reach the town
        D = D - v[n-1].first;
        //if you have enough fuel to cover this distance
        if(F >= D){
            cout<<ans<<endl;
            continue;
        }
        //otherwise, check if we can refuel the truck and reach the town
        while(F < D){
            //if there is no fuel stop left, you can''t reach the town
            if(pq.empty()){
                flag = 1;
                break;
            }
            //else, refuel the truck
            F += pq.top();
            pq.pop();
            ans = ans + 1;
        }

        if(flag == 1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}















