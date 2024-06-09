#include <iostream>
using namespace std;

int submatrixSum(int a[][1000] , int m , int n){
    int sum = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            //sum = value of the element at i,j * contribution of that element in the final sum
            //where contribution of each element = number of sub-matrices the element will be a part of = tl * br
            //x = number of top left candidates
            //y = number of bottom right candidates
            int tl = (i + 1) * (j + 1);
            int br = (m - i) * (n - j);
            sum += a[i][j] * tl * br;
        }
    }
    return sum;
}

int main()
{
    int m , n;
    cin>>m>>n;
    int a[1000][1000];
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j  < n ; j++){
            cin>>a[i][j];
        }
    }
    cout<<submatrixSum(a , m , n);

    return 0;
}
