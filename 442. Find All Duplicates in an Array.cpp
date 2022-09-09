#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            arr[i]--;
        int ptr = 0;
        int picked, temp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                picked = arr[i];
                arr[i] = -2;

                while (arr[picked] != -1 && arr[picked] != -2)
                {
                    temp = picked;
                    picked = arr[picked];
                    arr[temp] = -1;
                }

                if (arr[picked] == -1)
                {
                    // cout<<i<<picked<<endl;
                    ans[ptr++] = picked + 1;
                }
                else if (arr[picked] == -2)
                {
                    arr[picked] = -1;
                }
            }
        }
        ans.resize(ptr);
        return ans;
    }
};