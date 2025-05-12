/*
    Problem Link : https://leetcode.com/problems/decode-ways/description/
    Problem Name : 91. Decode Ways
    Difficulty   : Medium
    Time Complexity: O(n)
    Space Complexity : O(n) + call stack space O(n)
    Author : Ali Hossain
    Date : 12-05-2025

*/

#include<bits/stdc++.h>
using namespace std;



class Solution{ 
    public:    
    int ways(int ind, string &s, vector<int> &dp) {

        if(ind == s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];
        if(s[ind]=='0') return 0;

        int singleDig = ways(ind+1,s,dp);
        int doubleDig = 0;
        if(ind < s.size()-1 && (s[ind]=='1'||s[ind]=='2' && s[ind+1]<='6')){
            doubleDig =ways(ind+2,s,dp);
        }
        return dp[ind] = singleDig + doubleDig;
    }
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        vector<int> dp(n+1,-1);
        return ways(0,s,dp);   
    }
};
    