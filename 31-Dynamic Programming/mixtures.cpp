/* Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the
resulting mixture in their place.
When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.
Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.
Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
Input Format : The first line of each input file will contain n, the number of mixtures. The second line will contain n integers between 0 and 99 - the
initial colors of the mixtures.
Solution : Suppose we are given 4 mixtures A B C D,we can make partitions at every place recursively and out of all these cases, the minimum one will be my
required answer. In the worst case, when  there is a single element left, then the resultant smoke generate is 0 because it is not getting mixed with any
element. If we create a partition like this : (AB)|(CD) then the resultant smoke will be (A+B)*(C+D).
Hence if we have mixtures A1,A2..A(k),A(k+1),A(k+2)...A(n), then the resultant smoke will be :
( A1*A2*A3..A(k) ) + ( A(k+1)*A(k+2)*..*A((n) )+ ( (A1+A2+..+A(k)) * (A(k+1)+A(k+2)+..+A(n)) )
So final answer, f(i,j) = f(i,k) + f(k+1, j) + cumulative sum of numbers from(i, k) * cumulative sum of numbers from(k+1, n)
where cumulative sum = Σ (a[i] % 100) */

#include<iostream>
using namespace std;

int arr[1000];
long long dp[1000][1000];

long long sum(int s, int e){
    long long ans = 0;
    for(int i = s; i <= e; i++){
        ans += arr[i];
        ans %= 100;
    }
    return ans;
}

//i and j are the starting and ending index of the array
long long mixtures(int i, int j){
    //Base case: smoke generated for a single element will be 0
    if(i >= j){
        return 0;
    }
    //Lookup
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //We try to break the expression at every possible k
    dp[i][j] = INT_MAX;
    for(int k = i; k <= j; k++){
        dp[i][j] = min( dp[i][j], mixtures(i, k) + mixtures(k+1, j) + sum(i, k) * sum(k+1, j) );
    }
    return dp[i][j];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        //initialize dp array with -1
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        cout<<mixtures(0, n-1)<<endl;
    }
}

/* Input :
    2
    2
    18 19
    3
    40 60 20
   Output :
    342
    2400
*/


