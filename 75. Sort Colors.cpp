#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int arr[3] = {0, 0, 0};
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            arr[nums[i]]++;
        }

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (arr[j] == 0)
                j++;
            nums[i] = j;
            arr[j]--;
        }
    }
};