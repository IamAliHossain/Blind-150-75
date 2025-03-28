#include<bits/stdc++.h>
using namespace std;
/*  
    Leetcode String(Sliding Window) : 
    Dificulty : Hard
    Problem Link : https://leetcode.com/problems/minimum-window-substring/
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(128, 0);
        for(char ch : t){
            hash[ch]++;
        }
        int counter = t.size();
        int left = 0, right = 0;
        int minLength = INT_MAX;
        int bestLeft = -1;
        while(right < s.size()){
            char endChar = s[right];
            hash[endChar]--;
            if(hash[endChar] >= 0){
                counter--;
            }
            right++;

            while(counter == 0){

                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    bestLeft = left;
                }
                char startChar = s[left];
                hash[startChar]++;
                if(hash[startChar] > 0){
                    counter++;
                }
                left++;
            }
        }
        return (bestLeft == -1 ? "" : s.substr(bestLeft, minLength));
    }
};

int main(){
    string s = "AB", t ="C";

    vector<int> hash(128);
    int counter = t.length();
    int bestLeft = -1;
    int minLength = s.length() + 1;

    for (char c : t)
        hash[c]++;
        
    int left = 0, right = 0;
    while( right < s.length()) {
    
        hash[s[right]]--;
        if(hash[s[right]] >= 0){
            counter--;
        }
        right++;
        while (counter == 0) {
            if (right - left< minLength) {
            bestLeft = left;
            minLength = right - left ;
            }
            
            hash[s[left]]++;
            if(hash[s[left]] > 0){
                counter++;
            }
            left++;
        }
    }
    cout << ((bestLeft == -1) ? "" : s.substr(bestLeft, minLength)) << endl;
}