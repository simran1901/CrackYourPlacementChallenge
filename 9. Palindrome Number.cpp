#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long long revNum = 0;
        long long num = x;
        while (x > 0) {
            revNum = revNum*10 + x%10;
            x /= 10;
        }
        
        if (num == revNum) return true;
        return false;
    }
};