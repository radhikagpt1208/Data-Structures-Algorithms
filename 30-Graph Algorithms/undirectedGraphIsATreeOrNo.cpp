/* An undirected graph is tree if it has following properties :
1) There is no cycle.
2) The graph is connected.
   Approach :
   We can either use BFS or DFS.
   For every visited vertex 'v', if there is an adjacent 'u' such that u is already visited and u is not parent of v, then there is a cycle
   in graph. If we don't find such an adjacent for any vertex, we say that there is no cycle.
(We check,if we can visit a node by more than one path then it has a cycle and hence it is not a tree.
Using bfs,if we come back to the same node that is already visited, we return false.
We also keep a check that if the visited node is the parent of the node you are currently visiting,in that case,you have to ignore the case)*/

#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool isTree(){
        bool *visited = new bool[V];
        int *parent = new int[V];
        queue<int> q;
        //no node is visited in the beginning
        for(int i = 0; i < V; i++){
            visited[i] = false;
            //we keep updating the parent array
            parent[i] = i;
        }
        int src = 0;
        q.push(src);
        visited[src] = true;

        //pop out each node from the queue and visit its neighbors
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr : l[node]){
                if(visited[nbr] == true && parent[node] != nbr){
                    //there is a cycle present
                    return false;
                }
                //if the node is not visited, go visit it
                else if(visited[nbr] != true){
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
   // g.addEdge(0, 3);

    if(g.isTree()){
        cout<<"It is a tree";
    }
    else{
        cout<<"It is not a tree";
    }
    return 0;
}
