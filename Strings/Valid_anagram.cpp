#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ="ANAGRAM", t = "MARGANA";

    unordered_map<char, int> hash;
    for(char c : s){
        hash[c]++;
    }
    int left = 0, right = 0;
    int required = t.size();
    bool isAnagram = false;
    while(right < t.size()){
        hash[t[right]]--;
        if(hash[t[right]] >= 0){
            required--;
        }
        right++;
        while(required == 0){
            if(right - left == t.size()){
                isAnagram = true;
            }
            hash[t[left]]++;
            if(hash[t[left]] > 0){
                required++;
            }
            left++;
        }
    }
    cout << isAnagram << endl;
}