/* Topological sort cannot be done for cyclic graphs because there is no particular node to start from. It is only possible for
   Directed Acyclic Graphs(DAG)
   It is a linear ordering of vertexes such that for every directed edge from u to v,vertex u comes before v in the ordering.
   The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
    In topological sorting, we use a temporary stack. We don't print the vertex immediately, we first recursively call topological
    sorting for all its adjacent vertexes, then push it to a stack. Finally, print contents of stack.
    Note that a vertex is pushed to stack only when all of its adjacent vertexes(and their adjacent vertexes and so on)are already
    in stack. */

#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > l;
public:
    //assuming edges are unidirectional
    void addEdge(T x, T y){
        l[x].push_back(y);
    }

    //rec func that will traverse the graph
    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){
        visited[src] = true;
        //go to all its neighboring nodes that are not visited
        for(T nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited, ordering);
            }
        }
        //before returning, push the ordering of the node in the front
        ordering.push_front(src);
        return;
    }

    //make a visited array and mark all nodes as false
    void dfs(){
        map<T, bool> visited;
        list<T> ordering;       //to store the linear ordering
        for(auto p : l){
            T node = p.first;
            visited[node] = false;
        }
        //call dfs from all possible nodes
        for(auto p : l){
            T node = p.first;
            if(!visited[node])
                dfs_helper(node, visited, ordering);
        }
        //finally print the list
        for(auto node : ordering){
            cout<<node<<endl;
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("Dataset", "FaceRecogn");

    g.dfs();

    return 0;
}






