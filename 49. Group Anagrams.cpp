#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapp;
        string temp;
        for(string s: strs) {
            temp = s;
            sort(temp.begin(), temp.end());
            mapp[temp].push_back(s);
        }
        vector<vector<string>> ans(mapp.size());
        int i = 0;
        for(auto it: mapp) {
            ans[i] = it.second;
            i++;
        }
        return ans;
    }
};