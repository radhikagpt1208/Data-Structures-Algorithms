/* Path Compression Optimization : reduces time complexity of find function from O(N) to O(1)
   The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned.
   The find() operation traverses up from x to find root which may take O(N) time in the worst case
   The idea of path compression is to make the found root as parent of x so that we don't have to traverse all intermediate nodes again.
   If x is root of a subtree, then path (to root) from all nodes under x also compresses.
   Hence, the basic idea that every time we get a query of find() function, we try to reduce the path length from that node to the root node by
   making those nodes as the direct children of the root node
//Union By Rank : reduces time complexity of union function
    The idea is to always attach smaller depth tree under the root of the deeper tree.
    The term rank is preferred instead of height because if path compression technique is used, then rank is not always equal to height.
    To do this,we have to maintain the rank_value of each node. Most importantly, we need the rank value of the leader of the set because
    when we have to merge the 2 sets, we should know which one is smaller and which one is bigger
After doing these 2 optimizations,complexity comes out to be approximately O(1)*/

#include<iostream>
#include<list>
using namespace std;

//Cycle Detection in an Undirected Graph Using DSU
class Graph{
    //representing a graph using edge list(not adj list)
    int V;
    list<pair<int, int> > l;
public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int u, int v){
        l.push_back(make_pair(u, v));
    }

    //Optimized Find using DSU:
    int findSet(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }
        //update the value of parent[i]  with the parent returned by the recursive call
        //find root and make root as parent of i (path compression)
        //all the nodes that came in the path from bottom will have the same root
        return parent[i] = findSet(parent[i], parent);
    }

    // Optimized Union
    void union_set(int x, int y, int parent[], int rank[]){
        //find in which set x and y lie(find the parent of x and y)
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        /* if they don't lie in the same subset, merge them
        if(s1 != s2){
            parent[s1] = s2;
        }  */
        //Attach smaller rank tree under root of high rank tree(Union by Rank)
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];   //rank is the size of the set, if you merge s1 to s2, the size of s2 will increase
            }
            else{
                parent[s2]= s1;
                rank[s1] += rank[s2];
            }
        }
    }

    bool detect_cycle(){
        //DSU logic to check if there is a cycle present
        //in the beginning,assume that each node is a set of its own
        //initially, there are V number of sets and each node is a set in itself
        int *parent = new int[V+1];
        int *rank = new int[V];
        for(int i = 0; i < V; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        //iterate over the edge list
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2){
                union_set(s1, s2, parent, rank);
            }
            else{
                return true;
            }
        }
        //print the final parent and rank array
        for(int i = 0; i < V; i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < V; i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;

        delete[] parent;
        delete[] rank;
        return false;
    }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(2, 5);
    //g.addEdge(2, 6);

    cout<<g.detect_cycle();
    return 0;
}
