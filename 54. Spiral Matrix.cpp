#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans(m*n);
        int ptr = 0;
        bool flag = n%2 && m%2;
        int j;
        for(int i=0; i<ceil(min(n,m)/2.0); i++) {
            
            // row = i
            for (j = i; j<m-i-1; j++) {
                if (ptr==n*m) return ans;
                ans[ptr++] = matrix[i][j];
            }
            
            // col = m-i-1
            for(j=i; j<n-i-1; j++){
                if (ptr==n*m) return ans;
                ans[ptr++] = matrix[j][m-i-1];
            }
            
            // row = n-i-1
            for(j=m-i-1; j>i; j--) {
                if (ptr==n*m) return ans;
                ans[ptr++] = matrix[n-i-1][j];
            }
            
            // col = i
            for(j=n-i-1; j>i; j--) {
                if (ptr==n*m) return ans;
                ans[ptr++] = matrix[j][i];
            }
            
            if (flag && i==n/2) ans[ptr++] = matrix[i][j];
            
        }
        return ans;
    }
};