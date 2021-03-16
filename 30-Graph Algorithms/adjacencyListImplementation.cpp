/*We will first find the number of vertexes V,and accordingly create an array of lists of size V,i.e, there are V number of arrays
  and each array will store its neighbors,i.e,the zeroth array stores the neighbors of the zeroth node,the first array stores
  neighbors of the first node and so on.... */

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;         //no. of vertexes
    list<int> *l;  //an array of list can be written as list<int> l[V] but during compile time of V is not known,so we keep a
                   //pointer to the array of list and we can initialize it once V is known to us(in the constructor)
public:
    Graph(int V){
        this->V = V;
        //l is a pointer of an array in which each element of the array is a list
        l = new list<int>[V];
    }

    //since there is an edge b/w 2 nodes and both of them are integers, we take x and y
    void addEdge(int x,int y){
        //if there is an edge from x to y(assuming it is a bidirectional edge)
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList(){
        //iterate over all the vertexes
        for(int i = 0; i < V; i++){
            cout<<"Vertex "<<i<<" -> ";
            for(int nbr : l[i]){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.printAdjList();
    return 0;
}
