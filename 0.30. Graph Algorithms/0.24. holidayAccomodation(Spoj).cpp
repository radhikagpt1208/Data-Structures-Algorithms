/*
-> Problem Statement :
Nowadays, people have many ways to save money on accommodation when they are on vacation. One of these ways is exchanging houses with other people.
Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use
someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:
    All the people should go to one of the other people's city.
    Two of them never go to the same city, because they are not willing to share a house.
They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city
he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.
Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.
-> Input :
The first line of input contains one integer T (1 ≤ T ≤ 10), indicating the number of test cases.
Each test case contains several lines. The first line contains an integer N (2 ≤ N ≤ 105), representing the number of cities.
Then the following N-1 lines each contains three integers X, Y, Z (1 ≤ X, Y ≤ N, 1 ≤ Z ≤ 106), means that there is a highway between city X and city Y,
and length of that highway.
You can assume all the cities are connected and the highways are bi-directional.
-> Output :
For each test case in the input, print one line: "Case #X: Y", where X is the test case number (starting with 1) and Y represents the largest total travel
distance of all people.

HINT:Since it is given that there are N cities and N-1 highways that connects the cities,it can be inferred that it is a WEIGHTED TREE(no cycle in the graph)

Approach 1:
To maximize the total distance traveled for all the people,we will use a greedy approach,i.e, we will try to maximize the distance through every edge.
This can be done by maximizing the no. of exchanges of people across a particular edge.
Suppose we have a graph and we consider an edge x,y with distance w and the number of nodes in both the components,i.e, Nx = 6 and Ny = 8.
Now to maximize the usage of the edge (x,y) we can pick 6 people from x component and swap them with any 6 people i y component.
Total number of people that can travel through this edge is min(6, 8) * 2 , i.e, 12 people(6 from x and 6 from y). Hence the distance traveled through
edge (x,y) is 12 * weight of (x,y) edge.
On doing this through every edge, we can ensure that we maximize the distance.

Algorithm 1:
1. Break the graph at every edge say (x,y) of weight w and you will get 2 components of the graph.
2. Get the maximum distance that can be traveled by using every edge.
3. For those 2 components find out the number of nodes in both the parts,i.e, find Nx and Ny using traversals such as BFS or DFs.
4. Find the max distance by the formula : 2 * min(Nx, Ny) * weight of (x,y) edge.
(The movement will happen twice on the same edge)
For eg: if you have n=4 cities, say A,B,C and D and you are given n-1=3 edges connecting these cities. Now for every edge, you have to
find what is the maximum distance that can be traveled on that edge. For instance, you have to find for the edge A->B.
This can be done by the formula as stated above where '2' indicates that the movement on the edge A-B will be twice,i.e, A will use the
edge A->B to reach B and B will use the edge B->A to reach A;
Nx and Ny will give the no. of cities on both the sides. Hence,
the number of movements that an take place will be the minimum of Nx and Ny. Suppose if you do it for the edge A-B, there is 1 city on the
left,i.e, A and 3 cities on the right,i.e, B,C and D. Hence, only one city out of the 3 cities(B,C,D)can travel to A;
the distance traveled for an edge will be the weight of the edge.
But the time complexity of this approach will be O(VE+E^2)

Approach 2:
The idea remains same. We break every edge of the graph and calculate the no. of nodes in both that parts. But we use DFS only once.
We make a DFS call on one part of the graph recursively and find the no. of nodes in this part (say Nx) and since the total no. of nodes are given,
no. of nodes on the other part will be total nodes - nodes on the part as calculated.
Hence for one edge, total distance traveled by the people through that edge will be 2 * min(Nx, N-Nx) * weight of (x,y)
When you do DFS, always return the size of the subgraph or size of the component from which you are returning.
Time Complexity : O(V+E) (complexity of DFS)   */

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    //Adj List
    list< pair<int, int> >*l;
public:
    Graph(int V){
        this->V = V;
        l = new list< pair<int, int> >[V];
    }

    void addEdge(int x, int y, int w){
        l[x].push_back(make_pair(y, w));
        l[y].push_back(make_pair(x, w));
    }

    //this function returns the no. of nodes for every sub graph and the total distance will be updated as it is passed by reference.
    int dfs_helper(int node, bool *visited, int *count, int &total_distance){
        //mark the node as visited and set the count as 1
        visited[node] = true;
        count[node] = 1;

        //go to all the neighbors
        for(auto nbr_pair : l[node]){
            int nbr = nbr_pair.first;
            int wt = nbr_pair.second;
            if(!visited[nbr]){
                //recursively return the count of children to the parent node
                count[node] += dfs_helper(nbr, visited, count, total_distance);
                //increment the contribution of this edge to the total distance because at this step you have visited the entire subgraph
                int nx = count[nbr];
                int ny = V - nx;
                total_distance += 2 * min(nx, ny) * wt;
            }
        }
        //just before leaving the parent node, return the count of this parent node to the it's parent
        return count[node];
    }

    int dfs(){
        bool *visited = new bool[V];
        int *count = new int[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
            count[i] = 0;
        }

        int total_distance = 0;
        dfs_helper(0, visited, count, total_distance);
        return total_distance;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);
    cout<<g.dfs()<<endl;
    return 0;
}





