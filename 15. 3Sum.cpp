#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int x = i+1, y = n-1;
            while(x<n && x<y) {
                if (nums[x]+nums[y] == -nums[i]) {
                    ans.push_back({nums[i], nums[x], nums[y]});
                    while(y>0 && nums[y] == nums[y-1]) y--;
                    while(x<n-1 && nums[x] == nums[x+1]) x++;
                    x++; y--;
                }
                else if (nums[x]+nums[y] > -nums[i]) {
                    while(y>0 && nums[y] == nums[y-1]) y--;
                    y--;
                }
                else {
                    while(x<n-1 && nums[x] == nums[x+1]) x++;
                    x++;
                }
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};