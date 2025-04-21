/*
    Problem Link : https://leetcode.com/problems/two-sum/description/
    Problem Name : Two Sum
    Difficulty   : Easy
    Time Complexity : O(N * log * N) -> for sorting operation
    Space Complexity : O(N)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vp;
        for(int i=0; i<nums.size(); i++){
            vp.push_back({nums[i], i});
        }
        sort(vp.begin(), vp.end());

        vector<int> pos;
        int n = nums.size();
        int l = 0, r = n -1 ;
        while(l < r){
            int sum = vp[l].first + vp[r].first ;
            if(sum == target) {
                pos.push_back(vp[l].second);
                pos.push_back(vp[r].second);
                break;
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }
        return pos;
    }
    // int isAvailable(vector<pair<int, int>>& vp, int need, int id1){
        
    //     int l = 0, r = vp.size() -1 ;
    //     while(l <= r){
    //         int mid = (l + r) / 2;
    //         if(vp[mid].first == need && mid != id1) return mid;
    //         else if(vp[mid].first < need){
    //             l = mid + 1;
    //         }
    //         else if(vp[mid].first > need){
    //             r = mid - 1;
    //         }
    //     }
    //     return -1;
    // }
};