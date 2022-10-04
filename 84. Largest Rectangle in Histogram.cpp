#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n, 0);
        vector<int> right(n, n-1);
        
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top()+1;
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            st.pop();
        }
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top()-1;
            }
            st.push(i);
        }
        
        int mx = 0;
        
        for(int i=0; i<n; i++) {
            mx = max(mx, heights[i]*(right[i]-left[i]+1));
        }
        
        return mx;
    }
};