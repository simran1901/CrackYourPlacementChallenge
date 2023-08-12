#include <simran.h>

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int mx = 0;
        for (auto a : points)
        {
            map<double, int> slopes;
            // find slope of current point with every other point
            for (auto b : points)
            {
                if (a == b)
                    continue;
                double slope = numeric_limits<double>::infinity();
                if (a[0] != b[0])
                {
                    slope = (double) (a[1] - b[1]) / (a[0] - b[0]);
                }
                slopes[slope]++;
                mx = max(slopes[slope], mx);
            }
        }
        return mx + 1;
    }
};