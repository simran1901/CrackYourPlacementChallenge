#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int live = 0;
                if (j+1<m && board[i][j+1]&1) live++;
                if (j-1>=0 && board[i][j-1]&1) live++;
                if (i+1<n && board[i+1][j]&1) live++;
                if (i-1 >= 0 && board[i-1][j]&1) live++;
                if (i+1<n && j+1<m && board[i+1][j+1]&1) live++;
                if (i-1>=0 && j-1>=0 && board[i-1][j-1]&1) live++;
                if (i+1<n && j-1>=0 && board[i+1][j-1]&1) live++;
                if (i-1>=0 && j+1<m && board[i-1][j+1]&1) live++;
                
                // main
                if ((board[i][j]==1 && (live<2 || live>3)) || (board[i][j]==0 && live==3)) {
                    board[i][j] += 2;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j]>1) {
                    board[i][j] = (board[i][j]%2 + 1)%2;
                }
            }
        }
        
    }
};