/*UNDIRECTED GRAPH
  We simply need to do either BFS or DFS starting from every unvisited vertex, and we get all strongly connected components.
  Using DFS:
  1) Initialize all vertexes as not visited.
  2) Do following for every vertex 'v'.
       (a) If 'v' is not visited before, call DFS(v)
       (b) Print new line character
  DFS(v)
  1) Mark 'v' as visited and print 'v'
  2) Do following for every adjacent 'u' of 'v':
     If 'u' is not visited, then recursively call DFS(u)  */

#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename T>
class Graph{
    //Adj list : T is the data type of the vertexes
    map<T, list<T> > l;
public:
    //assuming edges are bidirectional
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited){
        //print wherever you are standing at and mark it visited
        cout<<src<<" ";
        visited[src] = true;
        //go to all its neighboring nodes that are not visited
        for(T nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(){
        map<T, bool> visited;
        //mark all the nodes as not visited in the beginning
        for(auto p : l){
            T node = p.first;
            visited[node] = false;
        }
        //iterate over all the vertexes and initiate a dfs call if the vertex is not visited
        int cnt = 0;
        for(auto p : l){
            T node = p.first;
            if(!visited[node]){
                cout<<"Component "<<cnt<<" -> ";
                dfs_helper(node, visited);
                cnt++;
                cout<<endl;
            }
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.dfs();

    return 0;
}




