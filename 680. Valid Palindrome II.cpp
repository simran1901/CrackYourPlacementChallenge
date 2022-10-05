#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        
        int count = 0;
        bool flag = true;
        
        while(left<=right) {
            if (s[left]!=s[right]) {
                count++;
                left++;
            }
            else {
                left++;
                right--;
            }
            if (count>1) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            left = 0;
            right = n-1;
            count = 0;
            while(left<=right) {
                if (s[left]!=s[right]) {
                    count++;
                    right--;
                }
                else {
                    left++;
                    right--;
                }
                if (count>1) return false;
            }
        }
        return true;
    }
};