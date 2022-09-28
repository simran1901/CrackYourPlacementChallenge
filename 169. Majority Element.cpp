#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorEl;
        int count = 0;
        for(int i=0; i<n; i++) {
            if (count == 0) {
                count++;
                majorEl = nums[i];
            }
            else if (nums[i] == majorEl) {
                count++;
            }
            else {
                count--;
            }
        }
        return majorEl;
    }
};