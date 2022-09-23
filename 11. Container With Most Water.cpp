#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxAr = 0;
        while (left < right)
        {
            int h1 = height[left];
            int h2 = height[right];
            int h = min(h1, h2);
            maxAr = max(maxAr, h * (right - left));
            if (h1 < h2)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxAr;
    }
};