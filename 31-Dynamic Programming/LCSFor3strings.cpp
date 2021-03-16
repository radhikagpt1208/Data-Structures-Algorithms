#include<iostream>
#include<cstring>
using namespace std;

int lcs1(string s1, string s2, string s3, int x, int y, int z){
    if(x == s1.length() || y == s2.length() || z == s3.length()){
        return 0;
    }
    if(s1[x] == s2[y] && s2[y] == s3[z]){
        return 1 + lcs1(s1, s2, s3, x + 1, y + 1, z + 1);
    }
    else{
        int opt1 = lcs1(s1, s2, s3, x + 1, y, z);
        int opt2 = lcs1(s1, s2, s3, x, y + 1, z);
        int opt3 = lcs1(s1, s2, s3, x, y, z + 1);
        return max(opt1, max(opt2, opt3));
    }
}

int lcs2(string s1, string s2, string s3){
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    int dp[n1+1][n2+1][n3+1];
    for(int m = 0; m <= n1; m++){
        for(int n = 0; n <= n2; n++) {
            for(int o = 0; o <= n3; o++){
                if(m == 0 || n == 0|| o == 0){
                    dp[m][n][o] = 0;
                }
                else if(s1[m-1] == s2[n-1] && s2[n-1] == s3[o-1]){
                    dp[m][n][o] = 1 + dp[m-1][n-1][o-1];
                }
                else{
                    dp[m][n][o] = max(dp[m-1][n][o], max(dp[m][n-1][o], dp[m][n][o-1]));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    cout<<lcs1(s1, s2, s3, 0, 0, 0)<<endl;
    cout<<lcs2(s1, s2, s3)<<endl;

    return 0;
}
