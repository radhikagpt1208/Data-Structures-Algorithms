/* Problem statement :
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Approach :
1. Using DFS/BFS
Let's say there are K number of components. Find the size of each component.
You have to find the no. of ways such that you pick up cities from different components.
Hence you can find the no. of ways of selecting the 2 cities from the same component and subtract it from the total ways.
Your final answer will be total number of ways of selecting 2 cities - number of ways in which you can select 2 cities from the same component
= NC2 - summation(from x = 0 to x = k) |s|C2 where |s| is the size of the k-th component.
2. Using DSU
This is based on the fact that we are required to select one node from one set and another node from a different set
After making the graph, find the number of options(number of nodes) each node has so that it can connect itself in the required manner.
You will get this as = (total number of nodes -  nodes in the connected component in which it lies) because the node can connect itself to any
other node except those which lie in its own component.
The no. of nodes a particular node can connect itself to can be found by = total no. of nodes - rank of super parent in the set in which it lies.
After doing this, every such pair that we find will repeat twice, hence we will divide the total ans by 2 */

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list< pair<int, int> > l;
public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int x, int y){
        l.push_back(make_pair(x, y));
    }

    int find_set(int i, int parent[]){
        if(parent[i] == -1){
            return i;
        }
        return parent[i] = find_set(parent[i], parent);
    }

    void union_set(int x, int y, int parent[], int rank[]){
        int s1 = find_set(x, parent);
        int s2 = find_set(y, parent);

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

    int pairing(){
        //DSU logic
        int *parent = new int[V];
        int *rank = new int[V];

        for(int i = 0; i < V; i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        //Code Logic
        for(auto edge : l){
            int i = edge.first;
            int j = edge.second;

            //find the set in which i and j lie
            int s1 = find_set(i, parent);
            int s2 = find_set(j, parent);

            union_set(s1, s2, parent, rank);
        }
        //go to all the nodes
        int ans = 0;
        for(int i = 0; i < V; i++){
            ans += V - rank[find_set(i, parent)];
        }

        delete [] parent;
        delete [] rank;
        return ans/2;
    }

};

int main(){
    int n, m;
    cin>>n>>m;

    Graph g(n);
    while(m--){
        int x, y;
        cin>>x>>y;
        g.addEdge(x, y);
    }

    cout<<g.pairing()<<endl;
    return 0;
}

/* Input :
   5 3
   0 1
   1 4
   2 3
   Output : 6
*/
