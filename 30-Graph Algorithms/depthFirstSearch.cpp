/* Approach:
   The algorithm starts at some arbitrary node as the root node and explores as far as possible along each branch before
   backtracking. So the basic idea is to start from any arbitrary node and mark the node and move to the adjacent unmarked node
   and continue this loop until there is no unmarked adjacent node.
   Then backtrack and check for other unmarked nodes and traverse them. Finally print the nodes in the path.
Algorithm:
   Create a recursive function that takes the index of node and a visited array.
   Mark the current node as visited and print the node.
   Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.  */

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

    //we want the visited array to be the same for all the recursive calls,i.e,we don't want to make a copy of the map,
    //hence,passed by reference
    //this is a rec func that will traverse the graph
    void dfs_helper(T src, map<T, bool> &visited){
        //print wherever you are at standing mark it visited
        cout<<src<<" ";
        visited[src] = true;
        //go to all its neighboring nodes that are not visited
        for(T nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }

    //the goal of this func is only to make a visited array and mark all nodes as false
    void dfs(T src){
        map<T, bool> visited;
        //mark all the nodes as not visited in the beginning
        for(auto p : l){
            T node = p.first;
            visited[node] = false;
        }
        dfs_helper(src, visited);
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 0);

    cout<<"Following is Depth First Traversal\n";
    g.dfs(0);

    return 0;
}



