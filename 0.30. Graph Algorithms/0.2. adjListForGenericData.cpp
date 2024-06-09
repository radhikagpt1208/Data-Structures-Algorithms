//For a weighted graph, where the vertexes are not integers but a string of characters, and for each edge the weights are given,
//we can implement the graph using an adj list by making a hash map where the key is the node which is a string and we will
//map each key with the value is : list<pair<string, int>>,i.e,a pair where the first value is a string and denotes the neighbor
//and the second value is an int value that denotes the weight of a particular edge joining the node and its respective neighbor

#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>
using namespace std;

class Graph{
    //Adj list
    unordered_map<string, list<pair<string, int> > > l;
public:
    //x and y are the two nodes, dir denotes whether the edge is bidirectional(true) or unidirectional(false)
    void addEdge(string x, string y, bool dir, int weight){
        //we push the node that is connected with x along with the weight of the edge in the value part of the map
        l[x].push_back(make_pair(y, weight));
        //assuming it is a bidirectional edge
        if(dir){
            l[y].push_back(make_pair(x, weight));
        }
    }

    void printAdjList(){
        for(auto p : l){
            string node1 = p.first;
            list< pair<string, int> > nbrs = p.second;
            cout<<node1<<" -> ";
            for(auto nbr : nbrs){
                string node2 = nbr.first;
                int wt = nbr.second;
                cout<<node2<<" "<<wt<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);

    g.printAdjList();

    return 0;
}
