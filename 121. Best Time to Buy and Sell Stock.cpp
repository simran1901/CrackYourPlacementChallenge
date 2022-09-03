#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int maxProfit = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int sell = prices[i];

            if (sell < buy)
            {
                buy = sell;
                continue;
            }
            maxProfit = max(maxProfit, (sell - buy));
        }

        return maxProfit;
    }
};