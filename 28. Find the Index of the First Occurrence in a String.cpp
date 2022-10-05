#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
    void constructLPSArray(string needle, vector<int> &lps) {
        int j = 0;
        int i = 1;
        int n = needle.length();
        
        while(i<n) {
            if (needle[i] == needle[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j>0){
                    j = lps[j-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        vector<int> lps(m);
        constructLPSArray(needle, lps);
        
        int i = 0, j = 0;
        
        // kmp search
        while((n - i) >= (m - j)) {
            if (needle[j]==haystack[i]) {
                i++;
                j++;
            }
            else {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
            if (j==m) {
                return i-m;
            }
        }
        return -1;
    }
};