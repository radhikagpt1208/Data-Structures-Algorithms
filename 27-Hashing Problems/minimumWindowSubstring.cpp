/* PROBLEM STATEMENT:
Given two strings string1 and string2, the task is to find smallest substring in string1 containing all characters of string2

APPROACH:
1. First check if the length of string is less than the length of the given pattern, if yes then "no such window can exist"
2. Store the occurrence of characters of the given pattern in a hash map,i.e, make a frequency map of the given pattern
3. Start traversing the input string and store the frequency of each character of the current window in another frequency map.
4. Check if the pattern lies in the window,i.e, check if the frequency of the required characters matches the frequency
   of the characters in the current window
5. Keep repeating the process until you find a suitable window by expanding your window from the right of the string
6. Check if (count == length of pattern) this means a window is found,i.e,frequency of all the characters in the current window
   matches that of the pattern
7. If such window found, try to minimize it by removing extra characters from the beginning of the current window.
   (extra characters are either those characters which are not present in the pattern or those whose frequency is greater than
    what is required)
9. Also every time you get the required window,update the min length by making a comparison b/w the current window and the
   min window till now
10.Now, to get the smallest window,start contracting your window from the left of the string and keep on checking if the pattern
   lies in the current contracted window
11.If it does not lie, then expand your window from the right and repeat the process else contract the window from the left and
   keep on checking until you get the smallest window */

#include<iostream>
#include<string>
#include<climits>
using namespace std;

string smallest_window(string s, string pattern){
    //corner case
    if(s.length() < pattern.length()){
        return "No such window exists";
    }
    //make 2 frequency maps
    int FS[256] = {0};
    int FP[256] = {0};

    //build the pattern frequency map
    for(int i = 0; i < pattern.length(); i++){
        char ch = pattern[i];
        FP[ch]++;
    }

    //Sliding Window
    int cnt = 0;     //stores the total count of characters that are matched with the pattern string
    int start = 0;   //left pointer for shrinking the window
    int min_len = INT_MAX;
    int start_idx = -1;

    for(int i = 0; i < s.length(); i++){
        //Expansion process
        char ch = s[i];
        FS[ch]++;

        //maintain count of matching characters
        //if the current char is present in the pattern,increment the count
        if(FP[ch] != 0 && FS[ch] <= FP[ch]){
            cnt++;
        }

        //if all the characters have matched
        //Contraction Process
        if(cnt == pattern.length()){
            //start shrinking the window from the left
            //remove unwanted characters
            char temp = s[start];
            while(FP[temp] == 0 || FS[temp] > FP[temp]){
                FS[temp]--;
                start++;
                temp = s[start];
            }

            //you have got the smallest window
            int window_len = i - start + 1;
            if(window_len < min_len){
                min_len = window_len;
                start_idx = start;
            }
        }
    }
    if(start_idx == -1){
        cout<<"No such window found"<<endl;
    }
    string ans = s.substr(start_idx, min_len);
    return ans;

}

int main(){
    string s = "heelleeoaeo world";
    string pattern = "eelo";

    cout<<smallest_window(s, pattern)<<endl;
    return 0;
}
