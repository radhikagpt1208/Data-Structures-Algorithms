/* The approach is based on the below fact:
   A DAG has at least one vertex with in-degree 0 and one vertex with out-degree 0.
   Algorithm:
    1.Compute in-degree for each of the vertex present in the DAG
    2.Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
    3.Remove a vertex from the queue (Dequeue operation) and then:
        Decrease in-degree by 1 for all its neighboring nodes.
        If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
    5.Repeat Step 3 until the queue is empty.  */

#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        //directed graph
        l[x].push_back(y);
    }

    void topological_sort(){
        //create an array to calculate indegree
        int *indegree = new int[V];
        //initialize all vectors with 0 indegree
        for(int i = 0; i < V; i++){
            indegree[i] = 0;
        }
        //update indegree by traversing edges x->y
        //if there is an edge from x->y that means y has at least one dependency
        for(int i = 0; i < V; i++){
            for(auto y : l[i]){
                indegree[y]++;
            }
        }
        //bfs
        queue<int> q;
        //1. find nodes with 0 indegree and push it in the queue
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //2.start removing elements from queue & decrease the indegree of its neighbors & if the degree of the neighbor = 0,push it the queue
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            //iterate over its neighbors and decrement their indegree by 1
            for(auto nbr : l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topological_sort();

    return 0;
}
