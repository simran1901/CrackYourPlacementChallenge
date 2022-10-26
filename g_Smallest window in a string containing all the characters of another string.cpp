#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:
    string smallestWindow(string str, string pat)
    {
        const int no_of_chars = 256;
        int len1 = str.length();
        int len2 = pat.length();
        if (len1 < len2)
        {
            return "-1";
        }
        int hash_pat[no_of_chars] = {0};
        int hash_str[no_of_chars] = {0};
        for (int i = 0; i < len2; i++)
            hash_pat[pat[i]]++;
        int start = 0, start_index = -1, min_len = INT_MAX;
        int count = 0;
        for (int j = 0; j < len1; j++)
        {
            hash_str[str[j]]++;
            if (hash_str[str[j]] <= hash_pat[str[j]])
                count++;
            if (count == len2)
            {
                while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
                {
                    if (hash_str[str[start]] > hash_pat[str[start]])
                        hash_str[str[start]]--;
                    start++;
                }

                int len_window = j - start + 1;
                if (min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        if (start_index == -1)
        {
            return "-1";
        }

        return str.substr(start_index, min_len);
    }
};