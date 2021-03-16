/* Prim's algorithm is a greedy algorithm for a weighted undirected graph.
   Approach:
    It starts with an empty spanning tree. The idea is to maintain two sets of vertexes.
    The first set contains the vertexes already included in the MST which is the MSTSet[] .
    The other set contains all the vertexes in the graph which is the set V[].
    Now start from any source vertex(Say vertex1) & select all the active edges for this vertex.
    Active edge is an edge that connects a vertex in MST[] to a vertex in set V[].
    Pick the minimum weight edge from these all the edges selected. The minimum edge can be picked up by either iterating over the array which
    will take O(N) time. So we use a min heap that takes O(ElogE) time to select edges for all the vertexes.
    Select the edge in a way that the vertex connected by this edge is not already included in the MSTSet[].
    After picking the correct edge, move to the other end point of the edge and insert the vertex(say vertex2) that this edge connects into
    the MSTSet[] and then add the active edges of this vertex2 into the active edges list and repeat the process until all the vertexes are not
    included in the MSTSet[].  */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    //Adj List using array of vectors such that every index of array stores a node which contains a vector of a pair that has its adj nodes
    //along with the weight of the edge that connects the nodes
    vector< pair<int, int> > *l;
    int V;
public:
    Graph(int n){
        V = n;
        l = new vector< pair<int, int> >[n];
    }

    //x and y are the vertexes and w is the weight of the edge connecting them
    void addEdge(int x, int y, int w){
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst(){
        //to find the min weight edge,we use a Min Heap which will contain the weight of the edge & the vertex that it is connected to
        priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
        //visited array initialized with 0 that denotes whether a vertex has been included in the MST or not
        bool *visited = new bool[V]{0};
        int ans = 0;

        //start from the source node
        pq.push({0, 0});    //denotes the weight and the vertex
        while(!pq.empty()){
            //pick the edge with min weight
            auto min_edge = pq.top();
            pq.pop();

            //node to which this edge is directed to
            int node = min_edge.second;
            //weight of the edge
            int weight = min_edge.first;

            //if the node to which this edge is directed is already visited, discard that node
            if(visited[node]) {
                //discard and continue
                continue;
            }
            //else take the current edge
            ans += weight;
            visited[node] = 1;

            //add the new edges to the queue
            for(auto x : l[node]){
                if(visited[x.first] == 0){
                    pq.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main(){
    int n , m;      //n is the no.of nodes ; m is the no. of edges
    cin>>n>>m;

    Graph g(n);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin>>x>>y>>w;
        g.addEdge(x-1, y-1, w);   //in the code, there is 0 based indexing,hence we subtract 1
    }
    cout<<g.prim_mst();
    return 0;
}

/* Input :
   4 6
   1 2 1
   1 3 2
   1 4 2
   2 3 2
   2 4 3
   3 4 3
   Output : 5
*/
