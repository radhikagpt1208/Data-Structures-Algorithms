/* Bellman Ford Algorithm For SSSP
This is an algorithm to find single source shortest path in a WEIGHTED DIRECTED GRAPH. It also works for NEGATIVE WEIGHT CYCLE, unlike Dijsktra's algorithm.
Time Complexity : O(VE)
Dijkstra’s algorithm is a Greedy algorithm and time complexity is O(VLogV).
Dijkstra does not work for Graphs with negative weight edges, Bellman-Ford works for such graphs.
Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems.
But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

-> Algorithm :
Input: Graph and a source vertex source
Output: Shortest distance to all vertexes from source.
If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.

1) Initialization of distances of all vertexes :
  This step initializes distances from the source to all vertexes as infinite and distance to the source itself as 0.
   Create an array dist[] of size |V| with all values as infinite except dist[source] where source is source vertex.
2) Relax all edges V-1 times :
   This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertexes in given graph.
    a) Do following for each edge u-v
        If dist[v] > dist[u] + weight of edge uv, then update dist[v]
        dist[v] = dist[u] + weight of edge uv
3) Detects whether the graph contains a negative weight cycle :
   This step reports if there is a negative weight cycle in graph.
   Do following for each edge u-v (iterate over the edges Vth time) & if the distances change in this iteration, that means there is a negative weight
   cycle in the graph because V-1 iterations ensure that you will get the required answer.
   If dist[v] > dist[u] + weight of edge uv, then "Graph contains negative weight cycle"
   The idea of step 3 is, step 2 guarantees the shortest distances if the graph does not contain a negative weight cycle.
   If we iterate through all edges one more time,i.e, Vth time and get a shorter path for any vertex, then there is a negative weight cycle as you will
   end up reducing distances infinitely.

-> How does this work?
Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner.
It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on.
After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V|-1 edges in any simple path,
that is why the outer loop runs |V| - 1 times.
The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges
guarantees to give shortest path with at-most (i + 1) edges  */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Bellman Ford Algorithm
vector<int> bellman_ford(int V, int src, vector< vector<int> > edgelist){
    //create a vector and set all distance to infinity
    vector<int> dist(V + 1, INT_MAX);
    dist[src] = 0;

    //Relax all edges V-1 times
    for(int i = 0; i < V-1; i++){
        for(auto edge : edgelist){
            int x = edge[0];
            int y = edge[1];
            int weight = edge[2];

            //condition of possible overflow also included, (if dist[x] is infinite)
            if(dist[x] != INT_MAX && dist[x] + weight < dist[y]){
                dist[y] = dist[x] + weight;
            }
        }
    }
    //negative weight cycle
    for(auto edge : edgelist){
        int x = edge[0];
        int y = edge[1];
        int weight = edge[2];

        if(dist[x] != INT_MAX && dist[x] + weight < dist[y]){
            cout<<"Negative Weight Cycle Found";
            exit(0);
        }
    }
    return dist;
}

int main(){
    int N, M;
    cin>>N>>M;
    //Edge List Representation of Graph
    //create a vector of triplets to store the edges and the weight
    vector< vector<int> > edgelist;
    for(int i = 0; i < M; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        edgelist.push_back({x, y, wt});
    }
    int src;
    cin>>src;
    //assuming nodes are numbered from 1-N
    vector<int> distances = bellman_ford(N, src, edgelist);
    for(int i = 1; i <= N; i++){
        cout<<"Node "<<i<<" is at distance "<<distances[i]<<" from the source"<<endl;
    }
    return 0;
}

/* Input 1 :
    3 3
    1 2 3
    2 3 4
    3 1 -10
    1
   Output 1 : Negative Weight Cycle Found

   Input 2 :
    3 3
    1 2 3
    2 3 4
    1  3 -10
    1
    Output 2 :
    Node 1 is at a distance 0 from the source
    Node 2 is at a distance 3 from the source
    Node 3 is at a distance -10 from the source
*/
