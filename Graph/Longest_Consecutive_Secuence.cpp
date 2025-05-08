/*
    Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
    Problem Name : 128. Longest Consecutive Sequence
    Difficulty   : Medium
    Time Complexity : O(N)
    Space Complexity : O(N)
    ================================================================================================

    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
    Example 3:

    Input: nums = [1,0,1,2]
    Output: 3
    

    Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

// To solve this problem in O(N) we need to use set data structure

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestConsecutive(vector<int> &nums) {
        
        set<int> se;
        for(int i=0; i<nums.size(); i++){
            se.insert(nums[i]);
        }
        int cnt = 1, mxCnt = 1;
        for(auto u : se){
            if(se.find(u-1) == se.end()){
                cnt = 1;
                while(se.find(u+1) != se.end()){
                    cnt++;
                    u++;
                }
                mxCnt = max(mxCnt, cnt);
            } 
        }
        return mxCnt;
    }
};