#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        if (n==1){
            return strs[0];
        }
        
        string ans = "";
        for (int i=0; i<strs[0].size(); i++) {
            for (int j=1; j<n; j++){
                if (strs[j][i]=='\0' || strs[j][i]!=strs[0][i]){
                    return ans;
                }
                if (strs[j][i] == strs[0][i] && j==strs.size()-1){
                    ans += strs[j][i];
                }
            }
        }
        return ans;
    }
};