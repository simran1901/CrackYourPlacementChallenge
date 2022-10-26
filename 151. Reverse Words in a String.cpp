#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        s = ' '+s;
        int len = s.length();
        int ind = s[len-1]!=' '?1:0;
        for(int i=len-1; i>=0; i--) {
            if (s[i]==' '){
                if (ind>0) {
                    if (ans.length()>0) 
                        ans += ' ';
                    ans += s.substr(i+1, ind);
                    ind = 0;
                }
            }
            else {
                ind++;
            }
        }
        return ans;
    }
};