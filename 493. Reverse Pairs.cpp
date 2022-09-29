#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    int search(vector<int> &bit, int i) {
        int sum = 0;
    
        while (i < bit.size()) {
            sum += bit[i];
            i += i & -i;
        }

        return sum;
    }

    void insert(vector<int> &bit, int i) {
        while (i > 0) {
            bit[i] += 1;
            i -= i & -i;
        }
    }
    
    int index(vector<int> &arr, long val) {
        int l = 0, r = arr.size() - 1, m = 0;
    	
        while (l <= r) {
    	    m = l + ((r - l) >> 1);
    		
    	    if (arr[m] >= val) {
    	        r = m - 1;
    	    } else {
    	        l = m + 1;
    	    }
        }
    
        return l + 1;
    }
    
public:
    int reversePairs(vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        vector<int> copy(nums.begin(), nums.end());
        vector<int> bit(n+1);
    
        sort(copy.begin(), copy.end());
    
        for (int ele : nums) {
            res += search(bit, index(copy, 2L * ele + 1));
            insert(bit, index(copy, ele));
        }
    
        return res;
    }
};