#include<bits/stdc++.h>
using namespace std;

int main(){
    // string s = "pwwkew";
    // // string s = "abcabcbb";
    string s = "auuu";
    // string s = "tmmzuxt";
    // // cout << s[0] << endl;
    
    unordered_map<char, int > hash;
    int left = 0, right = 0;
    vector<int> res;
    
    while(right < s.length()){
        // cout << "righchar : " << s[right] << ' ';
        hash[s[right]]++;
        // cout << " count: " << hash[s[right]] << ' ';
        while(hash[s[right]] > 1){
            // cout << "achire bhai achi : " << endl;
            hash[s[left]]--;
            left++;            
        }
        res.push_back((right - left + 1));
        right++;
    }
    
    sort(res.rbegin(), res.rend());
    cout << res[0] << endl;
}