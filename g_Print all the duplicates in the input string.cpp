#include <bits/stdc++.h>
using namespace std;

void fillCharCounts(string str, vector<int> count)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
        count[(int)str[i]]++;
}

void printDups(string str)
{
    vector<int> count(256);
    fillCharCounts(str, count);

    int i;
    for (i = 0; i < 256; i++)
    {
        if (count[i] > 1)
        {
            cout << (char)i << ", count = " << count[i] << '\n';
        }
    }
}

int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}
