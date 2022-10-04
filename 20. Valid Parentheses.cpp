#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(char ch: s) {
            // if a opening bracket, push in
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            // if a closing bracket, pop out same opening bracket
            else {
                if (!(!st.empty() && ((st.top()=='(' && ch == ')') || (st.top()=='[' && ch == ']') || st.top()=='{' && ch == '}'))) 
                    return false;
                st.pop();
            }
            // if unable to return false
        }
        if (st.empty())
            return true;
        return false;
    }
};