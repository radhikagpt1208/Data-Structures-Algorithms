#include<iostream>
using namespace std;

int main(){
    int n , arr[1000][1000] , sum = 0;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>arr[i][j];
        }
    }

    //Extract all possible top left coordinates
    for(int ti = 0 ; ti < n ; ti++){
        for(int tj = 0 ; tj < n ; tj++){
            //Extract all possible bottom right coordinates w.r.t. current top left coordinate
            for(int bi = ti ; bi < n ; bi++){
                for(int bj = tj ; bj < n ; bj++){
                    //sum of the current sub-matrix formed
                    for(int i = ti ; i <= bi ; i++){
                        for(int j = tj ; j <= bj ; j++){
                            sum += arr[i][j];
                        }
                    }

                }
            }
        }
    }
    cout<<sum;
    return 0;
}
