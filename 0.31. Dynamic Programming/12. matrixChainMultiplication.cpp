/* Problem Statement :
You are given a set of matrices, and you have to decide the order to multiply these matrices so that total operations is minimized.
If you are given 2 matrices, A(r1 X c1) & B(r2 X c2),then Matrix Multiplication is possible only when c1 = r2.
The cost of computing one element of the resultant matrix will be the summation of c1 multiplications. Hence, the total cost will be
= the cost of computing for one element  * total no. of elements to be computed(= r1 * c2 = dimension of the resultant matrix)
Hence,cost of multiplying 2 matrices is :(r1 * c1 * c2).
Now,given a sequence of matrices, we have to find the most efficient way to multiply these matrices.
Suppose we have A,B,C,D..G matrices, then matrix chain multiplication of all these matrices will give me a result Z independent of the order you multiply
the matrices. However, the cost to compute Z may vary according to the order in which matrices are multiplied.
Now since, it is ensured that for every matrix to get multiplied, we have rows(i) = columns(i-1)th matrix or col(i-1)th matrix = row(i)th matrix
because for matrix multiplication to occur, no. of columns in the preceding matrix should be equal to the no. of rows in the following matrix.
Hence,if we have  sequence of 4 matrices as A1(4 X 2),A2(2 X 3),A3(3 X 1),A4(1 x3), then we only require the no. of rows in each matrix and the no of rows and no. of columns in the last matrix for the
input array. Hence for n matrices gives, we only require (n+1) dimensions and for the above example, input = 4, 2, 3, 1, 3.
The dimension of the columns of all the matrices can be known by the dimension of the rows given.
Recursion says that we can break the matrices at every point and recursively compute the answer for the remaining matrices.
To solve this question using DP, we will form a matrix of dimension n X n where n is the no. of matrices and matrix[i][j] denotes the minimum cost of
multiplying matrices from Ai to Aj, i.e, element [2][4] of the matrix gives the min cost to multiply the matrices A2,A3,A4.
To solve a dp, we require answer for shorter ranges first. Now,(i,j) represents (j-i+1) matrices which is a sub array array of matrices.
Let us consider the diagonal elements(where i==j)in the dp matrix as the base case.These elements will obviously return 0 because the cost of multiplying
matrices that lie in the range (i,j),i.e,(i,i) will be 0. Now to compute the min cost for the remaining cells of the dp matrix, we will choose a pivot
point k which is a matrix of dimension A[k-1][k].
To compute an answer for(x,y)th position in the dp matrix(i.e, the cost of multiplying all matrices from x ot y),consider k(which runs b/w x to y-1)
as the pivot point such that first the[x,k]th matrix is multiplied and then [k+1,y]th matrix is multiplied & then we multiply these 2 matrices.
The recurrence formula for this problem can be written as :
dp[x][y] = min(dp[x][k] + dp[k+1][y] + (A[x-1]*A[k]*A[y]) for all k that belongs to x->(y-1)) where A[x]*A[k]*A[y] is the cost of multiplying these
two matrices. A[x-1] = rows in the xth matrix, A[k] = cols in kth matrix , A[y] = cols in the yth matrix acc to a 0 based index array.
Hence the final answer for evaluating the entire problem is dp[1][n] which is the ans for the entire range of matrices.
Time Complexity : O(N^3) Space complexity : O(N^3)  */

#include<iostream>
#include<cstring>
using namespace std;

//0th row and 0th column of dp[][] are not used because we have n matrices numbered from 1-n
int dp[100][100];    //DP array

//Top Down DP
int MatrixChain(int m[], int i, int j){
    //dp[i,j] = Minimum number of scalar multiplications to compute the matrix M[i]M[i+1]...M[j] = M[i..j] where dimension of M[i] is p[i-1] x p[i]
    //Base Case
    if(i == j){
        return dp[i][j] = 0;
    }
    //Lookup : If overlapping subproblem is already computed
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    //pivot point can range from i-(j-1)
    for(int k = i; k < j; k++){
        int temp = MatrixChain(m, i, k) + MatrixChain(m, k + 1, j) + m[i-1] * m[k] * m[j];
        ans = min(ans, temp);
    }
    dp[i][j] = ans;
    return ans;
}

//Bottom Up DP
int matrixChainMulti(int *arr, int n){
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    /* For simplicity of the program,one extra row and one extra column are allocated in dp[][]. 0th row and 0th column of dp[][] are
    not used */
    for(int i = n-1; i >= 1; i--){
        for(int j = i; j < n; j++){
            //for diagonal elements: cost is zero when multiplying one matrix.
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]) );
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    return dp[1][n-1];
}

int main(){
    //n =5 ,i.e, (n-1)= 4 matrices of dimensions 4X2, 2X3, 3X1, 1X3
    //dimension of an ith matrix is matrices[i-1][i]
    //if there are n matrices, there will be (n+1) elements in the array.
    int matrices[] = {4, 2, 3, 1, 3};
    int n = sizeof(matrices)/sizeof(int);

    /* initialize DP array with -1
    memset(dp, -1, sizeof dp);
    cout<<"Minimum number of multiplications is : "<< MatrixChain(matrices, 1, n-1)<<endl;
    //Print the DP array
    //cells where no work happens(which are not reachable as i > j) will have value = -1
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */

    cout<<matrixChainMulti(matrices, n);
    return 0;
}
