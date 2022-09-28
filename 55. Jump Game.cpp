#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if (n==1) return true;
        for (int i=0; i<nums.size();) {
            if (i+nums[i]>=n-1) return true;
            int mx = nums[i+nums[i]];
            int mxi = i+nums[i];
            for(int j=i+1; j<n && j<=i+nums[i]; j++){
                if(nums[j]-(i+nums[i]-j) > mx && nums[j] != 0) {
                    mx = nums[j]-(i+nums[i]-j);
                    mxi = j;
                }
            }
            ans++;
            if (i==mxi) return false;
            i = mxi;
            
        }
        return true;
    }
};