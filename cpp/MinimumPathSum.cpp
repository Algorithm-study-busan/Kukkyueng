// LEET 64. Minimum Path Sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int dp[201][201];
        dp[0][0] = grid[0][0];
        for (int i=1; i<row; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int i=1; i<col; ++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];

        // dp[n][m] = min(dp[n - 1][m], dp[n][m - 1]) + grid[n][m];
        for (int i=1; i<row; ++i)
        {
            for (int j=1; j<col; ++j)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];

    }
};