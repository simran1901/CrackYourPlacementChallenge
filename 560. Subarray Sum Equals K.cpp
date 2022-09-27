#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mapp;
        int ans = 0;
        int n = nums.size();
        mapp[nums[0]]++;
        mapp[0]++;
        if (nums[0]==k) ans++;
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
            ans+=mapp[nums[i]-k];
            mapp[nums[i]]++;
        }
        return ans;
    }
};