#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> ans;
        int n = path.length();
        int i = 0;
        while(i<n) {
            // get string between two slashes
            while(i<n && path[i]=='/') i++;
            string temp = "/";
            while(i<n && path[i]!='/') {
                temp+=path[i];
                i++;
            }
            if (temp == "/.") {
                // pass
            }
            else if (temp == "/..") {
                if(!ans.empty())
                ans.pop_back();
            }
            else if (temp != "/"){
                ans.push_back(temp);
            }
            i++;
        }
        string res = "";
        if (ans.empty()) res = "/";
        while(!ans.empty()) {
            res += ans.front();
            ans.pop_front();
        }
        
        return res;
    }
};