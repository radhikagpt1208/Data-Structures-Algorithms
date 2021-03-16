#include <iostream>
using namespace std;

void submatrixSum(int a[][1000] , int R , int C)
{
    //Generating prefix sum array
    int psa[R][C];
    int sum = 0;
    psa[0][0] = a[0][0];

    // Filling first row and first column
    for (int i = 1; i < C; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < R; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];

    // updating the values in the cells
    // as per the general formula
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++){
            // values in the cells of new
            // array are updated
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1]
                        - psa[i - 1][j - 1] + a[i][j];
        }
    }

    //top right of psa
    for(int ti = 0 ; ti < R ; ti++){
        for(int tj = 0 ; tj < C ; tj++){
            //bottom right of psa
            for(int bi = ti ; bi < R ; bi++){
                for(int bj = tj ; bj < C ; bj++){
                    sum = psa[bi][bj];
                    if(ti > 0){
                        sum = sum - psa[ti-1][bj];
                    }
                    if(tj > 0){
                        sum = sum - psa[bi][tj-1];
                    }
                    if(ti > 0 && tj > 0){
                       sum =  sum + psa[ti-1][tj-1];
                    }
                }
            }
        }
    }
    cout<<sum;
 }

int main()
{
    int R,C;
    cin>>R>>C;
    int a[1000][1000];
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j  < C ; j++){
            cin>>a[i][j];
        }
    }
    submatrixSum(a , R , C);

    return 0;
}
