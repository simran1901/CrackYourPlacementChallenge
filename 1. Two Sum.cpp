#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapp.find(target - nums[i]) != mapp.end())
            {
                return vector<int>({mapp[target - nums[i]], i});
            }
            mapp[nums[i]] = i;
        }
        return vector<int>();
    }
};