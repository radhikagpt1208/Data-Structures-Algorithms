/* DFS can be used to detect a cycle in a Graph.
There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself(self-loop)
or one of its ancestors produced by DFS.
To detect a back edge, keep track of vertexes currently in the recursion stack of function for DFS traversal.
If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree.
The edge that connects the current vertex to the vertex in the recursion stack is a back edge.
Use recStack[] array to keep track of vertexes in the recursion stack.
Algorithm:
Create a recursive function that initializes the current index or vertex, visited, and recursion stack.
Mark the current node as visited and also mark the index in recursion stack.
Find all the vertexes which are not visited and are adjacent to the current node. Recursively call the function for those vertexes.
If the recursive function returns true, return true.
If the adjacent vertexes are already marked in the recursion stack then return true.
Create a wrapper class, that calls the recursive function for all the vertexes and if any function returns true return true.
Else if for all vertexes the function returns false return false.  */

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

    bool detect_cycle_helper(int node, bool *visited, bool *stack){
        //when you visit a node:
        //1.mark it as true
        visited[node] = true;
        //2.make it a part of the current path
        stack[node] = true;
        //for every node, ask its neighbor whether there is a cycle present or no(rec func)
        for(int nbr : l[node]){
            //2 cases
            //1. if the nbr is present in the stack array,it is the case of a back edge
            if(stack[nbr] == true){
                return true;
            }
            //else if that neighbor is not visited, but it may lead to a cycle
            //then make a rec call on the next node and ask that node whether a cycle is present or no
            else if(visited[nbr] == false){
                bool is_cycle_present = detect_cycle_helper(nbr, visited, stack);
                if(is_cycle_present == true){
                    return true;
                }
            }
        }

        //when you leave a node,i.e you go back from that node,it remains visited but is removed from the stack array
        stack[node] = false;
        return false;

    }

    bool detect_cycle(){
        bool *visited = new bool[V];
        //make a stack array to store the current path
        bool *stack = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = stack[i] = false;
        }
        return detect_cycle_helper(0, visited, stack);
    }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    //g.addEdge(4, 2);

    if(g.detect_cycle()){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is not present";
    }
    return 0;
}
