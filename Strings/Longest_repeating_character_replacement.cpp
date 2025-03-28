#include<bits/stdc++.h>
using namespace std;

int main(){
    // string s = "AABABBA";
    // int k = 1;
    string s = "AABDDDDDDDDDBBA";
    int k = 1;
    unordered_map<char, int> hash;
    int left = 0, right = 0;
    int mxCnt = 0, ans = 0;
    while(right < s.size()){
        hash[s[right]]++;
        mxCnt = max(mxCnt, hash[s[right]]);
        cout << "Max freq : " << mxCnt << ' ';
        int windowLen = (right + 1 - left);
        int diff = windowLen - mxCnt;
        cout << "Difference : " << diff << ' ';
        if(diff <= k){
            cout << "valid window\n";
            ans =max(ans,windowLen);
        }
        right++;
        while(diff > k){
            hash[s[left]]--;
            diff--;
            left++;
            cout << "Invalid window\n";
        }
    }
    cout << ans << endl;

}