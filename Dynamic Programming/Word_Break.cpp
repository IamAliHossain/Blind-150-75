/*
    Problem Link : https://leetcode.com/problems/word-break/description/
    Problem Name : 139. Word Break
    Difficulty   : Medium
    Time Complexity : O(n * n * n) = O(n ^ 3)
    Space Complexity: O(n * n + k * m) = O(n ^ 2 + k * m)
    Author : Ali Hossain
    Date : 11-05-2025


*/


#include<bits/stdc++.h>
using namespace std;

/*  
    Time Complexity analysis : 
    O(n^2) pairs (start, end) and O(n) time to create substrings
    → O(n^2 * n) = O(n^3)

    🧠 Space Complexity
        dp array: O(n^2) space.
        Recursion call stack: maximum depth = O(n) (if each recursive call goes to end+1 only).
        Dictionary se: size = O(k * m), where k is number of words and m is average length of words.
*/

class Solution {
public:
    bool solve(int start, int end, string &s, unordered_set<string> &se, vector<vector<int>> &dp){
        
        if(dp[start][end] != -1) return dp[start][end];
        // Note : contains() only available on compiler c++23 version : se.contains(s.substr(start, end-start+1))
        if(end == s.length()-1){
            if(se.find(s.substr(start, end-start+1)) != se.end()){
                return true;
            }
            return false;
        }
        //  If the current substring (s[start...end]) is in the dictionary:
        // Recursively check if the rest of the string (s[end+1... ]) can also be segmented.
        // If that recursive call returns true, return true.
        if(se.find(s.substr(start, end-start+1)) != se.end()){
            if(solve(end+1, end+1, s, se, dp)){
                dp[start][end] = true;
                return true;
            }
        }
        dp[start][end] = solve(start, end+1, s, se, dp);
        return dp[start][end];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(int i=0; i<wordDict.size(); i++){
            se.insert(wordDict[i]);
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, s, se, dp);

    }
};