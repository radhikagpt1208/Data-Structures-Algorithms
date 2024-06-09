/* BFS of a graph is similar to that of a tree, i.e, we keep pushing nodes into a queue and then pop it out and print it and push
   its neighbors(only unvisited neighbors) into the queue. However, graphs unlike trees, might contain a cycle so there is a chance
   of us coming back to the same node, hence we use a boolean 'visited' array(we can use a map) to mark those nodes as visited
   that have been pushed into the queue once */

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

    //src(source) is the starting node
    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;

        //push the source node in the queue and mark it as visited
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";

            //check all the neighbors of this node
            for(auto nbr : l[node]){
                //check if that neighbor is already visited,if it is not then push it in the queue and mark it as visited
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    cout<<"Following is Breadth First Traversal starting from vertex 0 \n";
    g.bfs(0);

    return 0;
}
