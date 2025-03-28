/*  
    Problem Link: https://leetcode.com/problems/longest-palindromic-substring/description/
    Problem Title: 5.Longest Palindromic Substring
    Problem Difficulty: Medium
    Given a string s, return the longest palindromic substring in s.

    Example 1:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    Example 2:

    Input: s = "cbbd"
    Output: "bb"
    

    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

*/

#include<bits/stdc++.h>
using namespace std;

// string s="babad";
// string s = "cbbcddddc";
// string s = "a";
string s = "aacabdkacaa";
bool dp[1010][1010];

string longestSubstr(string s, int i, int j, int start, int maxLength){
    if(i<0 and j>=s.size()) return "";
    if(dp[i][j] != false) return s.substr(start, maxLength);
    string l = longestSubstr(s, i-1, j, start, maxLength);
    string r = longestSubstr(s, i, j+1, start, maxLength);

}

int main(){
    
    int start = 0, maxLength = 1;
    string longestSubstr = s.substr(start, maxLength);
    for(int i=0; i<s.size(); i++){
        dp[i][i] = true;
    }
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]){
            maxLength = 2;
            start = i;
            longestSubstr = s.substr(start, maxLength);
            dp[i][i+1] = true;
        }
    }
    for(int len = 3; len<= s.size(); len++){
        for(int i=0; i<s.size()-len+1; i++){
            int j=i+len-1;
            if(s[i] == s[j] and dp[i+1][j-1] == true){ 
                dp[i][j] = true;
                start = i;
                maxLength = len;
                longestSubstr = s.substr(start, maxLength);
            }
        }
    }
    cout  << "longestSubstr " << longestSubstr << endl;
}