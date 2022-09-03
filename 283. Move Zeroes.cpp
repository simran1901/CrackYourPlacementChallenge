#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ptr1 = 0, ptr2 = 0;
        while(ptr2<n) {
            // 0 encountered
            while(ptr1<n && nums[ptr1]!=0) {
                ptr1++;
            }
            if (ptr1>=n-1) break;
            if (ptr2<ptr1) ptr2 = ptr1+1;
            while(ptr2<n && nums[ptr2]==0) {
                ptr2++;
            }
            if (ptr2==n) break;
            swap(nums[ptr1], nums[ptr2++]);
        }
    }
};