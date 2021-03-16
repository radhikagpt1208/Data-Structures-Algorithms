#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool directed = true){
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }
    }

    bool detect_cycle_helper(int node, bool *visited, int parent){
        visited[node] = true;
        for(auto nbr : l[node]){
            if(visited[nbr] == true && nbr != parent){
                return true;
            }
            else if(!visited[nbr]){
                //go and recursively visit the neighbor
                //it is possible that nbr may lead to a node that leads to a cycle
                bool is_cycle_present = detect_cycle_helper(nbr, visited, node);
                if(is_cycle_present){
                    return true;
                }
            }
        }
        return false;
    }

    bool detect_cycle(){
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        //assuming that there is a single component in the graph
        //if there are multiple components,you can make a call to dfs helper func for every component once
        return detect_cycle_helper(0, visited, -1);   //instead of making a parent array,pass the parent of 0 as -1 and then for every other node we will keep updating the parent
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    //g.addEdge(4, 0);


    if(g.detect_cycle()){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is not present";
    }
    return 0;
}
