#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        
        if(n==0) return ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll target2 = 1ll*target-nums[i]-nums[j];
                int front=j+1;
                int back=n-1;
                while(front<back){
                    if(target2>nums[front]+nums[back]) front++;
                    else if(target2<nums[front]+nums[back]) back--;
                    else{
                        int tfront = front, tback = back;
                        ans.push_back(vector<int>({nums[i], nums[j], nums[front], nums[back]}));
                        while(front<back && nums[front]==nums[tfront]) front++;
                        while(front<back && nums[back]==nums[tback]) back--;
                    }
                }
                while(j<n-1 && nums[j]==nums[j+1]) j++;
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};