/* The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.  Time Complexity: O(V^3)
The problem is to find shortest distances between every pair of vertexes in a given edge WEIGTED DIRECTED GRAPH.
We initialize the distance matrix same as the input graph matrix as a first step.
Then we update the distance matrix by considering all vertexes as an intermediate vertex.
The idea is to one by one pick all vertexes and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path.
When we pick vertex number k as an intermediate vertex, we already have considered vertexes {0, 1, 2, .. k-1} as intermediate vertexes.
For every pair (i, j) of the source and destination vertexes respectively, there are two possible cases.
1)k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
2)k is an intermediate vertex in shortest path from i to j.We update the value of dist[i][j] as dist[i][k]+dist[k][j] if dist[i][j]>dist[i][k]+dist[k][j]  */

#include<iostream>
#include<vector>
using namespace std;
#define INF 99999

vector< vector<int> > floyd_warshall(vector< vector<int> > graph){
    vector< vector<int> > dist(graph);
    int V = graph.size();
    //iterate over the phases(in kth phase include vertexes (1, 2,3...k) as intermediate vertexes)
    for(int k = 0; k < V; k++){
        //for each phase,iterate over entire 2D matrix
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                //check if we can minimize the distance by including the intermediate vertexes
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main(){
    //diagonal elements are 0 and the case where we don't have any direct edge, we initialize as INT_MAX
    vector< vector<int> > graph = {
                                    {0, INF, -2, INF},
                                    {4, 0, 3, INF},
                                    {INF, INF, 0, 2},
                                    {INF, -1, INF, 0}
                                   };
    auto distance = floyd_warshall(graph);
    for(int i = 0; i < distance.size(); i++){
        for(int j = 0; j < distance.size(); j++){
            if (distance[i][j] == INF)
                cout<<"INF"<<" ";
            else
                cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
