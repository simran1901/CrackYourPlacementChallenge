#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        do {
            int num = (columnNumber - 1)%26;
            ans += 'A'+num;
            columnNumber-=num+1;
            columnNumber /= 26;
        } while (columnNumber > 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};