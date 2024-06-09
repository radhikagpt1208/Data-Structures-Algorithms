#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Car{
public:
    string name;
    int x, y;

    Car(){
    }

    Car(string n, int x, int y){
        name = n;
        this->x = x;
        this->y = y;
    }

    int dist(){
        //return square of distance from origin
        return x*x + y*y;
    }

};
//take input of 2 cars at a time
bool compare(Car A, Car B){
    int dA = A.dist();
    int dB = B.dist();

    if(dA == dB){
        return A.name.length() < B.name.length();
    }
    return dA < dB;
}

int main(){
    int n;
    cin>>n;
    //create a vector that has x and y coordinate of a cab
    vector<Car> v;

    for(int i = 0 ; i < n ; i++){
        int x , y;
        string name;
        cin>>name>>x>>y;
        Car temp(name, x, y);    //make a car object
        v.push_back(temp);
    }

    sort(v.begin() , v.end() , compare);

    for(auto c : v){
        cout<<"Car "<<c.name<<" Distance "<<c.dist()<<" Location "<<c.x<<","<<c.y<<endl;
    }
    return 0;
}

