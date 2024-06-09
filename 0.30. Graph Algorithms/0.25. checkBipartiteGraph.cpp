/* A Bipartite Graph is a graph whose vertexes can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from
U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U.
We can also say that there is no edge that connects vertexes of same set.
-> A bipartite graph is possible if the graph coloring is possible using two colors such that vertexes in a set are colored with the same color.
   The neighboring(or adjacent) nodes of a given vertex should be assigned a different color wrt the node, so that they lie in diff sets.
-> Note that it is possible to color a cycle graph with EVEN cycle using two colors.
-> It is NOT possible to color a cycle graph with ODD cycle using two colors.
-> Hence, for a bipartite graph check if the graph contains a cycle and that cycle has odd number of nodes then it is not a bipartite graph OR check if
   the graph has a cycle and if from a node you are going to another node which has the same color, then it is not a bipartite graph

Simple algorithm to find out whether a given graph is bipartite or not using Breadth First Search (BFS).
1. Assign color 1 to the source vertex (putting into set U).
2. Color all the neighbors with color 2(putting into set V).
3. Color all neighbor's neighbor with color 1(putting into set U).
4. This way, assign color to all vertexes such that it satisfies all the constraints of m way coloring problem where m = 2.
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex,then the graph cannot be colored with 2 vertexes
(or graph is not Bipartite) */

#include<iostream>
#include<vector>
using namespace std;

//color variable tells that what color has to be assigned to the current node
//parent variable is made to ensure that when you find the nbrs of a node, you should not go back to the parent of that node which is already visited
bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color){
    //when visit a node, you mark it with the color it has been assigned to (both 1 and 2 mean visited)
    visited[node] = color;
    for(auto nbr : graph[node]){
        //if nbr is not visited, call dfs
        if(visited[nbr] == 0){
            int sub_problem = dfs_helper(graph, nbr, visited, node, 3 - color);//if current node has color 1,then 3-1 = 2,i.e,nbr has to be colored 2 and vice versa
            //if the sub problem returns that it has found an odd length cycle,i.e, it is not a bipartite graph
            if(sub_problem == false){
                return false;
            }
        }
        //while finding nbrs of a node, you don't have to go back to the parent node & the color of the current node and neighboring node should not be same
        //case of odd length cycle
        else if(nbr != parent && color == visited[nbr]){
            return false;
        }
    }
    return true;
}

//Using DFS
//color nodes at each step(if current node ha color 1, nbr should have color 2)
bool bipartite(vector<int> graph[], int N){
    //we can make 2 arrays, one for the visited nodes and the other one to store the color of the nodes. However, we will combine
    //all the 3 cases into one array.
    int visited[N] = {0};    //0 denotes vertex is not visited,1 denotes vertex is visited and is colored 1,2 denotes node is visited and is colored 2

    //set the color of starting node
    int color = 1;
    int ans = dfs_helper(graph, 0, visited,-1, color);

    //print all the colors
    for(int i = 0; i < N; i++){
        cout<<i<<" - Color "<<visited[i]<<endl;
    }
    return ans;
}

int main(){
    int N, M;
    cin>>N>>M;

    //Graph represented as a Adj List
    vector<int> graph[N];
    while(M--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(bipartite(graph, N)){
        cout<<"Bipartite Graph";
    }
    else{
        cout<<"Not a bipartite graph";
    }
    return 0;
}

