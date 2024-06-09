/* SPANNING TREE : It is a subset of edges such that it forms a tree that connects all vertexes of the graph in a single connected component &
   if there are V vertexes,(V-1) edges are required in the tree to form the single component without any cycle.
   ->Minimum spanning tree for a weighted, connected and undirected graph is that spanning tree whose total cost,i.e,the sum of the weights of the edges in the subset should be minimum.
   ->A minimum spanning tree has (V - 1) edges where V is the number of vertexes in the given graph.
-> Kruskal's algo is a Greedy Algorithm(you choose a local minima at each step which leads you to a globally optimum solution)
   The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far.

Approach :
1. First consider all the nodes are independent,i.e, each node is in their own set.
2. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far,i.e,see if those edges are already connected and
   hence belong to the same component or no.
   If cycle is not formed, include this edge and join them in a single component. Else, discard it.
3. Repeat step2 until there are (V-1) edges in the spanning tree.

Time Complexity: O(ElogE) or O(ElogV).
Sorting of edges takes O(ELogE) time.
After sorting, we iterate through all edges and apply find-union algorithm. The find and union operations can take at most O(LogV) time.
So overall complexity is O(ELogE + ELogV) time. The value of E can be atmost O(V2), so O(LogV) are O(LogE) same.
Therefore, overall time complexity is O(ElogE) or O(ElogV)  */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//DSU data structure (implement is using Path Compression and Union By Rank)
class DSU{
    int *parent;
    int *rank;
public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        //in the beginning, all nodes belong to their own set and the rank of each node is 1,i.e, itself
        for(int i = 0; i < n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find_set(int i){
        if(parent[i] == -1){
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }

    void union_set(int x, int y){
        //find the sets in which the 2 nodes belong and unite them only if they are in diff sets
        int s1 = find_set(x);
        int s2 = find_set(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph{
    //create an edge list to stores the weight of every edge in an orderly manner along with the nodes that it connects
    //Edge List Implementation of Graph
    vector<vector<int> > edgelist;
    int V;
public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int x, int y, int w){
        //sorting will automatically be done on the basis of the first parameter,hence we store the weight first and then the nodes
        edgelist.push_back({w, x, y});
    }

    int kruksal_mst(){
        //sort all the edges based upon weight
        sort(edgelist.begin(), edgelist.end());
        //Initialize a DSU
        DSU s(V);

        int ans = 0;
        for(auto edge : edgelist){
            int weight = edge[0];
            int node1 = edge[1];
            int node2 = edge[2];

            //take this edge in the MST if it belong to different set and hence does not form a cycle
            if(s.find_set(node1) != s.find_set(node2)){
                //unite both these edges
                s.union_set(node1, node2);
                ans += weight;
            }
        }
        return ans;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    cout<<g.kruksal_mst()<<endl;
    return 0;
}
