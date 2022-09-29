#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int mx = INT_MIN;
        int tempMx  = points[0][1]-points[0][0];
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            while(!pq.empty() && ((x - pq.top().second)>k)) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                mx = max(mx, x+y+pq.top().first);
            }
            
            pq.push({y-x, x});
        }
        return mx;
    }
};