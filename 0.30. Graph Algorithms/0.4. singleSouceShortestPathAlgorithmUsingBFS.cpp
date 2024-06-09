/*Distance calculated by level order traversal is the shortest distance in case of an UNWEIGHTED GRAPH(level of a node is the
  distance of that node from the source)
  Time Complexity : O(V + E)*/

#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<climits>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > l;
public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        //stores whether the given node is visited or no and the distance of that node from the source
        map<T, int> dist;
        queue<T> q;

        //as no path is yet constructed all other nodes (except source node) that are not visited will have infinity dist
        for(auto node_pair : l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        //distance from source to itself should be 0
        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int nbr : l[node]){
                //if the neighboring node is visited for the first time,push it in the queue and update its distance
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        //print the distance for every node
        for(auto node_pair : l){
            T node = node_pair.first;
            int d = dist[node];
            cout<<"Node "<<node<<" is at a distance "<<d<<" from the source "<<endl;
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);

    return 0;
}

