/*
-> Problem Statement :
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell.
The player has total control over outcome of dice throw(he can decide what number to throw and there is no double turn on getting a six)and wants to find
out minimum number of throws required to reach last cell. Find the shortest path as well.
-> Input Format :
First line contains integer t as number of test cases.
Each test case contains following input.
First line contains three integers n, l, s which represents the number of cells of board, number of ladders and number of snakes.
Next l lines contains two integers each x & y denoting there is a ladder from x to y.
Next s lines contains two integers each x & y denoting there is a snake from x to y.

Approach : Every number in the board is a vertex ,i.e, we have 0 - n vertexes. For eg: if the size of the board is 6, we will have 0-36 vertexes.
For every vertex numbered i , you can have an edge up to (i+1),(i+2),...(i+6). But it is possible that you reach up to this point and it has a ladder or a
snake that is connecting this vertex to some other vertex. Hence after rolling the dice you might end up at a vertex which has a jump which can either be
positive(if it has a ladder) or negative(if it has a snake). Hence we can say that for every turn, we can calculate where will we end up by using the
formula : vertex you are currently at(i) + number on dice(d) + jump. This jump can be calculated by knowing if there is a snake or a ladder at position that
we're ending up after throwing the dice (at position i+d). For example, if we are currently at 16 and we get 1 on the dice, that means we will reach 16+1=17
Now we will have to check if there is a snake or a ladder at this position. Suppose there is a snake at 17 that takes you back to 4. For this, we will make
an array ,say board[] and I can say that board[17] will have a negative jump of 13,i.e, board[17] = -13. Hence by using the formula, we can calculate where
will we finally land if we are currently on 16 and get 1 on the dice which is : 16 + 1 + (-13). This is how there will be an edge created from 16 to 4.
So the formula is : (i + d + board[i+d]). This will create an edge from i to the final position that we end up at.
Now this graph is an unweighted graph as every edge has the same cost which is equal to 1 dice throw. If we want to go from one vertex to the neighboring
vertex, we actually need one dice throw and the distance b/w those two vertexes does not matter.
Hence this problem comes out to be a problem of unweighted graph where you have to find the shortest path from source(0) to the destination(n).
*/


#include<iostream>
#include<list>
#include<map>
#include<climits>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > l;
public:
    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    int bfs(T src, T dest){
        //stores whether the given node is visited or no and the distance of that node from the source
        map<T, int> dist;
        map<T, T> parent;  //stores the parent of every node to help while printing the shortest path
        queue<T> q;

        //as no path is yet constructed all other nodes (except source node) that are not visited will have infinity dist
        for(auto node_pair : l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        //distance from source to itself should be 0
        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int nbr : l[node]){
                //if the neighboring node is visited for the first time,push it in the queue and update its distance
                if(dist[nbr] == INT_MAX){
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }

        //print the shortest path from source to destination
        T temp = dest;
        while(temp != src){
            cout<<temp<<" <--";
            temp = parent[temp];
        }
        cout<<src<<endl;
        return dist[dest];
    }
};


int main(){
    int n, l, s;
    cin>>n>>l>>s;

    int board[110] = {0};
    for(int i = 0; i < l; i++){
        int x, y;
        cin>>x>>y;
        //if there is a ladder that starts at x and ends at y, then there will be a positive jump of (y-x)
        board[x] = y - x;
    }
    for(int i = 0; i < s; i++){
        int x, y;
        cin>>x>>y;
        //if there is a snake at 17 that takes you to 4,there will be a negative jump of -(17-4) = -13.
        board[x] = -1 * (x - y);
    }

    //Add all edges to the graph
    Graph<int> g;
    for(int i = 1; i < 100; i++){
        //at every i, I can throw a dice between 1-6
        for(int dice = 1; dice <= 6; dice++){
            //from ith vertex I can go to some jth vertex
            int j = i + dice;
            //also add the jump
            j += board[j];
            if(j <= n){
                //unweighted directed edge
                g.addEdge(i, j);
            }
        }
    }
    //this will tell the graph that there is a vertex n*n also and we have to consider it
    g.addEdge(n, n);
    //find the shortest path from starting of the board to the last cell
    int ans = g.bfs(1, n);
    if(ans != INT_MAX){
           cout<<ans<<endl;
    }
    else{
           cout<<"-1"<<endl;
    }

    /* int board[50] = {0};
     board[2] = 13;
     board[5] = 2;
     board[9] = 18;
     board[18] = 11;
     board[17] = -13;
     board[20] = -14;
     board[24] = -8;
     board[25] = 10;
     board[32] = -2;
     board[34] = -22;

     Graph<int> g;
     for(int i = 0; i <= 36; i++){
         for(int dice = 1; dice <= 6; dice++){
             int j = i + dice;
             j += board[j];

             if(i <= 36){
                 g.addEdge(i, j);
             }
         }
     }
    g.addEdge(36, 36);
    cout<<g.bfs(0, 36);   */
    return 0;
}

/* Input :
    30 4 4
    3 22
    5 8
    11 26
    20 29
    17 4
    19 7
    21 9
    27 1

   Output :
    30 <--24 <--22 <--1
    3
*/
