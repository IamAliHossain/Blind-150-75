/*
    Problem Link : https://leetcode.com/problems/unique-paths/description/
    Problem Name : 62. Unique Paths
    Difficulty   : Medium
    Time Complexity: O(n)
    Space Complexity : O(n) + call stack space O(n)
    Author : Ali Hossain
    Date : 12-05-2025

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //This is recursive solution to optimize TC used DP(memoiation)
    int paths(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j] ;
        int ans = 0;
        ans += paths(i+1, j, n, m, dp) + paths(i, j+1, n, m, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return paths(0, 0, m, n, dp);
    }
};