/* KOSARAJU'S ALGORTTHM for finding SCC in Directed Graphs
  A strongly Connected Component (SCC) is a component such that starting from any vertex of that component,you are able to reach all other vertexes in that
  component.
  We can find all SCC in O(V+E) time using Kosaraju’s algorithm.
  Algorithm :
  1. Do DFS traversal of the entire graph and get an ordering based on finish time.
     This basically means that in DFS, you try to visit as many vertexes as possible starting from a given vertex and once you start going back from a vertex
     that time is called as the finish time.
  2. Once you are returning back from a vertex, you can push that vertex into a vector or a stack such that the vertex which is finished at the last will be
     pushed into the vector at the end.
  3. If you end up at a vertex from where cannot go anywhere, you start DFS from any other vertex and repeat the same.
  4. Reverse the original graph,i.e, reverse all the edges of that graph. We will create a copy of the graph in which all edges have been reversed.
  5. Pick a vertex 'v'from the vector as created from right to left. Do DFS on vertex 'v' according to the reversed graph.
     After doing DFS on v,skip those vertexes in the vector that have already been visited while doing DFS on 'v' & do DFS on the next unvisited vertex  */

#include <bits/stdc++.h>
using namespace std;

void dfs_on_reverse_graph(vector<int> reverse_graph[], int i, bool *visited){
    //mark the vertex as visited
    visited[i] = true;
    cout<<i<<" ";
    //iterate over all the neighbors
    for(auto nbr : reverse_graph[i]){
        //if a nbr is unvisited, call dfs
        if(!visited[nbr]){
            dfs_on_reverse_graph(reverse_graph, nbr, visited);
        }
    }
}

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &ordering){
    //mark the vertex as visited
    visited[i] = true;
    //iterate over all the neighbors
    for(auto nbr : graph[i]){
        //if a nbr is unvisited, call dfs
        if(!visited[nbr]){
            dfs(graph, nbr, visited, ordering);
        }
    }
    //all function calls are complete, and you start going back and you push that vertex into the ordering vector
    ordering.push_back(i);
}

void SCC(vector<int> graph[], vector<int> reverse_graph[], int N){
    bool visited[N]{0};
    //Step 1: do DFS and store the vertexes according to DFS finish time and create a vector to store the ordering
    vector<int> ordering;
    for(int i = 0; i < N; i++){
        //call dfs on unvisited vertexes
        if(!visited[i]){
            dfs(graph, i, visited, ordering);
        }
    }
    //Step 2 : ordering of the graph and reversing the graph is done

    //Step 3 : Do DFS according to the new ordering vector from right to left
    //reset the visited array as 0 to perform DFS again
    memset(visited, 0, N);
    //by default first component is named as A
    char component_name = 'A';

    for(int i = ordering.size() - 1; i >=0; i--){
        int node = ordering[i];
        if(!visited[node]){
            cout<<"Component "<<component_name<<" ->";
            //if this node is unvisited, there is a component starting from this node and I make a DFs call that will visit thsi entire component
            dfs_on_reverse_graph(reverse_graph, node, visited);
            cout<<endl;
            component_name++;     //this will change the name of the further components
        }
    }
}

int main(){
    int N, M;     //N vertexes from 0-(N-1) and M edges
    cin>>N>>M;
    //array of vector for graph representation
    vector<int> graph[N];
    vector<int> reverse_graph[N];
    //while taking the input of the edges, construct a reverse graph as well.
    while(M--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        reverse_graph[y].push_back(x);
    }
    SCC(graph, reverse_graph, N);
    return 0;
}

/* Input :
   7 8
   2 1
   1 0
   0 2
   0 3
   3 5
   5 6
   6 3
   3 4
   Output :
   Component A -> 0 1 2
   Component B -> 3 6 5
   Component C -> 4
*/
