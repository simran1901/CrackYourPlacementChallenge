#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int numbersArr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romansArr[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; num > 0; num = num % numbersArr[i], i++)
        {
            int times = num / numbersArr[i];
            for (int j = 0; j < times; j++)
            {
                ans+=romansArr[i];
            }
        }
        return ans;
    }
};