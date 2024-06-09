#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

//returns the length of the longest common subsequence
//i, j : pointers to iterate over the strings
int lcs1(string s1, string s2, int i, int j){
    //Base Case : if you reach the end of any either of the strings, you will not find any common subsequence
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    //Rec case
    //if the current character matches,include it in the subsequence and move both the pointers forward to recursively find the sol to the remaining string
    if(s1[i] == s2[j]){
        return 1 + lcs1(s1, s2, i + 1, j + 1);
    }
    //if the characters at the current indexes don't match, make 2 calls and take the maximum og those
    //first,keep the ith pointer where it is and increment the jth pointer(i.e, exclude the character at jth index)& rec find the sol for the rem part
    //second,increment the ith pointer(exclude the character at ith index) keeping the jth pointer where it is and rec find the sol for the rem part
    else{
        int opt1 = lcs1(s1, s2, i, j + 1);
        int opt2 = lcs1(s1, s2, i + 1, j);
        return max(opt1, opt2);
    }
}

//Top Down DP
//Since there are 2 variables that are getting updated after every recursive call, we will make a 2D DP array which denotes the length of the substring
//if you pick characters from index i till the end of string s1 and if you pick characters from index j till the end of s2 so that the max length of lcs
//of these 2 strings will be stored in dp[i][j]
//Time Complexity : O(n1*n2)
int lcs2(string s1, string s2, int i, int j, vector<vector<int> > &dp){
    //Base Case : if you reach the end of any either of the strings, you will not find any common subsequence
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    //Lookup : avoid recomputing the same value, if it has already been calculated return the value
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //Rec case
    //if the current character matches,include it in the subsequence and move both the pointers forward to recursively find the sol to the remaining string
    if(s1[i] == s2[j]){
        //before returning, store the calculated length in the vector so that the value computed can be reused
        return dp[i][j] = 1 + lcs2(s1, s2, i + 1, j + 1, dp);
    }
    //if the characters at the current indexes don't match, make 2 calls and take the maximum og those
    //first,keep the ith pointer where it is and increment the jth pointer(i.e, exclude the character at jth index)& rec find the sol for the rem part
    //second,increment the ith pointer(exclude the character at ith index) keeping the jth pointer where it is and rec find the sol for the rem part
    else{
        int opt1 = lcs2(s1, s2, i, j + 1, dp);
        int opt2 = lcs2(s1, s2, i + 1, j, dp);
        //before returning, store the calculated length in the vector so that the value computed can be reused
        return dp[i][j] = max(opt1, opt2);
    }
}

//Bottom Up DP
//dp[i][j] denotes the length of LCS if you pick i no. of characters from the first string(0 to i-1) & j no. of characters from the second string(0 to j-1)
//Hence if i=0 or j=0,dp[i][j] = 0(if you pick some characters from the 1st string & 0 characters from the second string,length of LCS = 0 and vice versa)
//So the first col and row will be 0 because either i == 0 or j == 0.
//If the last characters match,dp[i][j] = 1 + dp[i-1][j-1] (consider the sub problem in the backward direction )
//If the characters do not match, we have 2 case out of which we will consider the case where we get the max result.
//2 cases : Either include the ith character and solve the subproblem or include the jth character and solve the remaining subproblem.
//Time Complexity : O(n1*n2)
int lcs3(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    //grid size will be (n1+1) X (n2+1) because we are considering the case when we don't include any character as well(i,e. case of 0th row and col)
    int dp[n1+1][n2+1];
    //Following steps build dp[n1+1][n2+1] in  bottom up fashion. Note that dp[i][j] contains length of LCS of s1[0..i-1] and s2[0..j-1]
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            if(i == 0 || j == 0){
                //if we consider 0 characters from either of the strings,length of LCS will be 0
                dp[i][j] = 0;
            }
            //If last characters of both sequences match
            //since the indexing in the string is 0 based, but in the dp array it is 1 based, we have to subtract 1
            else if(s1[i-1] == s2[j-1]){
                //include that character in the LCS
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            //If last characters of both sequences do not match
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    /* print the dp array
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    Backtracking to print the LCS
    The value at dp[n1][n2] contains length of LCS. Hence you start backtracking from the last cell.
    Create a character array lcs[] of length equal to the length of lcs plus 1 (one extra to store \0).
    a)If characters (in s1 and s2) corresponding to dp[i][j] are same (Or s1[i-1] == s2[j-1]), then include this character as part of LCS and go upwards
      to the diagonally opp element(i.e,to the cell where you came from to dp[i][j])
    b)Else compare values of dp[i-1][j] and dp[i][j-1] and go in direction of greater value(because you came to dp[i][j] either via left cell or top cell)*/
    // Following code is used to print LCS
    int index = dp[n1][n2];
    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character
    // Start from the right-most-bottom-most corner and one by one store characters in lcs[]
    int i = n1, j = n2;
    while(i > 0 && j > 0){
        //If current character in s1[] and s2[] are same, then current character is part of LCS
        if(s1[i-1] == s2[j-1]){
            //Put current character in result
            lcs[index - 1] = s2[i - 1];
            //reduce values of i, j and index ,i.e, move diagonally upwards
            i--;
            j--;
            index--;
        }
        // If not same, then find the larger of two and go in the direction of larger value
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    //Print the lcs
    cout<<"LCS of "<<s1<<" and "<<s2<<" is "<<lcs<<endl;
    //length of LCS is stored at the last cell
    return dp[n1][n2];
}

int main(){
    string s1 = "ABCD";
    string s2 = "ABEDG";

    int n1 = s1.length();
    int n2 = s2.length();

    //create a 2D DP vector of size (n1 X n2) each initialized with -1
    vector<vector<int> > dp(n1, vector<int>(n2, -1));

    //lcs is "ABD"
    /*cout<<lcs1(s1, s2, 0, 0)<<endl;

    cout<<lcs2(s1, s2, 0, 0, dp)<<endl;

    //print the vector
    //-1 means those states are never visited, and the final ans is at dp[0][0]
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */

    int ans = lcs3(s1, s2);
    cout<<"Length of longest common subsequence : "<<ans;
    return 0;
}

