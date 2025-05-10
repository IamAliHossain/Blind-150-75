/*
    Problem Link : https://leetcode.com/problems/longest-common-subsequence/
    Problem Name : 1143. Longest Common Subsequence
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 10-05-2025


 */

#include<bits/stdc++.h>
using namespace std;

// This code is done with just recursive hence TC = O(2^n * 2^m) and brings TLE
    // To optimize the code we apply dp here, so see the next part
    //      Time Complexity : O(2^n * 2^m) Because eikhane 2 ta string er recursion cholche
    //      Space Complexity : O(1) 
/* 
class Solution {
    public:
    int LCS(string s, string t, int sn, int tn){
        if(sn < 0 || tn < 0) return 0;
        int len = 0;
        // Match on characters
        if(s[sn] == t[tn]){ 
            len += 1 + LCS(s, t, sn-1, tn-1);
        }
        // Not Match on characters
        else{
            len += 0 + max(LCS(s, t, sn-1, tn), LCS(s, t, sn, tn-1));
        }
        return len;

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        return LCS(text1, text2, n1-1, n2-1);
    }
};

*/
// This code is done using dp to reduce TC 
    // To optimize the code we apply dp here, so see the next part
    //      Time Complexity : O(n * m) Because eikhane 2 ta string er recursion cholche
    //      Space Complexity : O(n * m) + (n + m)(auxilary space at stack)

class Solution {
    public:
    int LCS(vector<vector<int>> &dp, string &s, string &t, int sn, int tn){
        if(sn == 0 || tn == 0) return 0;
        if(dp[sn][tn] != -1) return dp[sn][tn];
        if(s[sn - 1] == t[tn - 1]){
            return dp[sn][tn] = 1 + LCS(dp, s, t, sn - 1, tn - 1);
        } 
        else {
            return dp[sn][tn] = max(LCS(dp, s, t, sn - 1, tn), LCS(dp, s, t, sn, tn - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return LCS(dp, text1, text2, n1, n2);
    }
};

// This code is done with tabulation so TC = O(n * m) and SC : O(n * m) + (n + m)(auxilary space at stack)
    // To optimize the space we apply tabulation(Bottom-up) aproach  here, so see the next part
    //      Time Complexity : O(n * m) Because eikhane 2 ta string er recursion cholche
    //      Space Complexity : O(n * m)


    // Incomplete code do not take this part
class Solution{

    int LCS(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == t[m]){
            return dp[n][m] =  LCS(s, t, n-1, m-1, dp) + 1;
        }
        else{
            return dp[n][m] = max(LCS(s, t, n-1, m, dp), LCS(s, t, n, m-1, dp));
        }
        return dp[n][m];
    }

    int longestCommonSubsequence(string s, string t){
        int n = s.length() - 1;
        int m = t.length() - 1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // From the base case we know if i or j == 0 then return 0
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=n; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];

    }
};

