#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> rem(k, 0);

        int ans = 0, r = 0;
        int pref = 0;
        for (int i = 0; i < n; i++)
        {
            pref += nums[i];
            r = pref % k;
            if (r < 0)
                r += k;
            if (r == 0)
                ans++;
            if (rem[r] > 0)
                ans += rem[r];
            rem[r] += 1;
        }
        return ans;
    }
};