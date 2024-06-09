/* This algorithm is used to find the single source shortest path for WEIGHTED GRAPHS with NO negative weight cycle
   Time Complexity : O(ElogV) */

#include<iostream>
#include<unordered_map>
#include<climits>
#include<set>
#include<list>
using namespace std;

template<typename T>
class Graph{
    //store the graph in the form of a map where the key represents a node and the value part is a list of pairs that contain
    //the neighboring/adjacent nodes of a vertex along with its weight
    unordered_map<T, list< pair<T, int> >> m;
public:
    void addEdge(T u, T v, int dist, bool bidirection = true){
        m[u].push_back(make_pair(v, dist));
        if(bidirection){
            m[v].push_back(make_pair(u, dist));
        }
    }

    void printAdjList(){
        for(auto p : m){
            T node1 = p.first;
            list< pair<T, int> > nbrs = p.second;
            cout<<node1<<" -> ";
            for(auto nbr : nbrs){
                T node2 = nbr.first;
                int dist = nbr.second;
                cout<<node2<<" , "<<dist<<"   ";
            }
            cout<<endl;
        }
    }

    void dijkstraSSSP(T src){
        //store the distance of nodes in a map where key is the node and value is the given distance
        unordered_map<T, int> dist;
        //set the distance of all nodes wrt the source to infinity
        for(auto j : m){
            dist[j.first] = INT_MAX;
        }
        //make a set to find out the node with min distance(by default,this set is ordered on the basis of the first parameter)
        //set is a pair with distance of a node wrt the source and the node itself
        set<pair<int, T> > s;
        //distance of the source is zero
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){
            //find the pair at the front(which will by default have the min dist)
            auto p = *(s.begin());
            T node = p.second;
            int node_dist = p.first;
            //erase this node
            s.erase(s.begin());
            //iterate over neighbors of the current node
            for(auto nbr : m[node]){
               //update their distance wrt to the source node if it is minimum
               if(node_dist + nbr.second < dist[nbr.first]){
                    //direct updating a particular node is not possible so we have to first remove the old pair and then insert
                    //the new pair
                    T destination = nbr.first;
                    auto f = s.find(make_pair(dist[destination], destination));
                    if(f != s.end()){
                        s.erase(f);
                    }
                    //insert the new pair
                    dist[destination] = node_dist + nbr.second;
                    s.insert(make_pair(dist[destination], destination));
               }
            }
        }
        //print the distance of all nodes from the source
        for(auto d : dist){
            T node = d.first;
            int dist = d.second;
            cout<<node<<" is located at a distance "<<dist<<" from the source"<<endl;
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);

    g.printAdjList();
    g.dijkstraSSSP(1);
    return 0;
}
