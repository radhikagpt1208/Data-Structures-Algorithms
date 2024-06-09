/*This method assumes that the graph does not contain any self-loops.We can keep track of subsets in an array parent[].
  For each edge,make subsets using both the vertexes of the edge.
  Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset,i.e, the element itself).
  Now process all edges one by one. If union(edge1, edge2) is called,find the subsets in which vertexes edge1 and edge2 are.
  If they are in different subsets,we take the union of them.
  For taking the union, either make node edge1 as parent of node edge2 or vice-versa.
  If both the vertexes are in the same subset(or have the same parent), a cycle is found */

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

    //Find using DSU: worst time complexity is O(N)
    int findSet(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }
        return findSet(parent[i], parent);
    }

    //Union : worst time complexity is O(N)
    void union_set(int x, int y, int parent[]){
        //find in which set x and y lie(find the parent of x and y)
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        //if they don't lie in the same subset, merge them
        if(s1 != s2){
            parent[s1] = s2;
        }
    }

    bool detect_cycle(){
        //DSU logic to check
        //in the beginning,assume that each node is a set of its own
        int *parent = new int[V+1];
        for(int i = 0; i < V; i++){
            parent[i] = -1;
        }
        //iterate over the edge list
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if(s1 != s2){
                union_set(s1, s2, parent);
            }
            else{
                //both lie in the same set
                cout<<"Both have the same parents : "<<s1<<" and "<<s2<<endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    //g.addEdge(3, 0);

    cout<<g.detect_cycle();
    return 0;
}
