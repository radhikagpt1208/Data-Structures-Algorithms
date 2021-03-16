/* Given N Cartesian points, find the number of axis parallel rectangles that can be formed by them.
Approach: If the coordinates of the diagonal elements(say p1 and p2) are known to us, the coordinates of the other two vertexes(say p3 and p4)
will be known automatically by simple geometry.
We will iterate over all the pairs of points given, and choose 2 diagonal vertexes(p1 and p2) in N ways.
So we will have N^2 options to build a rectangle but all of them are not valid. A rectangle will be valid only if p3 and p4 exist.
The existence of the points p3 and p4 can be done through a hashmap.
(You can insert all the points in a set and check for the existence of the points)
To avoid double counting of rectangles, reduce the final ans by a factor of 2. */

#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(){
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class Compare{
public:
    bool operator()(Point p1, Point p2){
        if(p1.x == p2.x){
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }
};

int count_rectangles(vector<Point> coords){
    int n = coords.size();
    //when you create a set of a custom object, you have to pass a comparator that internally uses a tree like structure and it
    //needs to compare whether the point should go in the left or in the right
    set<Point, Compare> s;
    //insert all points in the set
    for(auto p : coords){
        s.insert(p);
    }

    int ans = 0;

    //it should stop at the second last index
    for(auto it = s.begin(); it != prev(s.end()); it++){
        //to move an iterator to the next step, use the 'next' function
        //jt = it+1 cannot be done because set is not linearly indexed
        for(auto jt = next(it); jt != s.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;

            //if you get p1 and p2 such that they lie on the same axis(i.e, either their x or y coordinates are the same),
            //then they cannot be valid points for a diagonal
            //hence, skip all those points that lie in the same horizontal or vertical line for a given point
            if(p1.x == p2.x || p1.y == p2.y){
                continue;
            }
            //once you get the diagonals, create the other 2 vertexes
            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);

            if(s.find(p3) != s.end() && s.find(p4) != s.end()){
                //you have found 4 potential points for a rectangle
                ans++;
            }
        }
    }
    return ans/2;
}

int main(){
    int m;
    cin>>m;
    //store all points in a vector
    vector<Point> coordinates;
    while(m--){
        int x, y;
        cin>>x>>y;
        Point p(x, y);
        coordinates.push_back(p);
    }
    cout<<count_rectangles(coordinates);
}

/* Input:
    8
    0 0
    0 1
    1 1
    1 0
    2 1
    2 0
    3 1
    3 0
    Output:
     6
*/
