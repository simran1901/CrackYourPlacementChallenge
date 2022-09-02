#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = nums.size();
        if (l <= 1)
            return l;
        vector<int>::iterator ip = unique(nums.begin(), nums.end());
        return distance(nums.begin(), ip);
    }
};