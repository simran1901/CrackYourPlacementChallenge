#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {

    int getNum(int n) {
        int l;
        int s = 0;
        while(n>0) {
            l = n%10;
            s += l*l;
            n /= 10;
        }
        return s;
    }
public:
    bool isHappy(int n) {
        set<int> sumCovered;
        sumCovered.insert(n);
        while(n != 1) {
            n = getNum(n);
            if (sumCovered.find(n) != sumCovered.end()) return false;
            sumCovered.insert(n);
        }
        return true;
    }
};