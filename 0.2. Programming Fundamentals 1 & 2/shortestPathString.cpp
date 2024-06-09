#include<iostream>
using namespace std;

int main(){
    char ch;
    ch = cin.get(); //reads a single character
    int x = 0 , y = 0;
    while(ch != '\n'){
        if(ch == 'N' || ch == 'n'){
            y++;
        }
        else if(ch == 'S' || ch == 's'){
            y--;
        }
        else if(ch == 'E' || ch == 'e'){
            x++;
        }
        else if(ch == 'W' || ch == 'w'){
            x--;
        }

        ch = cin.get();
    }
    cout<<"Final displacement is "<<x<<" and "<<y<<endl;

    return 0;
}
