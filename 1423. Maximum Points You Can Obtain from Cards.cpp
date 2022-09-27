#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mx = 0;
        int n = cardPoints.size();
        int sum = 0;
        for(int i=n-k; i<n; i++) {
            sum += cardPoints[i];
        }
        mx = sum;
        for(int i=n-k+1; i<=n; i++) {
            sum += cardPoints[(i+k-1)%n];
            sum -= cardPoints[i-1];
            
            mx = max(sum, mx);
        }
        return mx;
    }
};