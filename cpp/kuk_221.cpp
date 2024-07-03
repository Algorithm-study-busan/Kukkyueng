#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = (int)matrix.size();
        if (n == 0) { return 0; }
        int m = (int)matrix[0].size();

        /*
        dp[i][j] : (i, j)가 오른쪽 아래 꼭짓점일 때 가능한 변의 길이의 최댓값
        (i - 1, j - 1) (i - 1, j)
        (i    , j - 1) (i    , j)   
        if (matrix[i][j] == 1) -> 자기와 이웃한 3 점들에 의해 결정됨.
            dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + !
        if (matrix[i][j] == 0) -> 자기를 포함한 1로 이루어진 정사각형은 있을 수 없음
            dp[i][j] = 0

        if (row == 0 || col == 0) -> 가능한 정사각형이 자기 자신만 포함한 것이기 때문
            dp[row][col] = matrix[row][col]
        */
        
        vector<vector<int>> dp(n, vector<int> (m));
        for (int row = 0; row < n; ++row) 
            dp[row][0] = matrix[row][0] - '0';
        for (int col = 0; col < m; ++col)
            dp[0][col] = matrix[0][col] - '0';

        for (int row = 1; row < n; ++row) 
        {
            for (int col = 1; col < m; ++col) 
            {
                if (matrix[row][col] == '0') 
                {
                    dp[row][col] = 0;
                } 
                else 
                {
                    dp[row][col] = min({dp[row - 1][col], dp[row - 1][col - 1], dp[row][col - 1]}) + 1;
                }
            }
        }
        int result = 0;
        for (const auto &vec : dp)
            for (int e : vec)
                result = max(result, e);

        return result * result;
    }
};

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         row = matrix.size();
//         col = matrix[0].size();

//         bool isAllOne = true;
//         for (int i=0; i<row; ++i)
//         {
//             for (int j=0; j<col; ++j)
//                 if (matrix[i][j] == '0')
//                 {
//                     isAllOne = false;
//                     break;
//                 } 
//         }

//         if (isAllOne)
//             return pow(min(row, col), 2);

//         int ret = 0;
//         for (int i=0; i<row; ++i)
//         {
//             for (int j=0; j<col; ++j)
//             {
//                 if (matrix[i][j] == '1')
//                     ret = max(ret, func(matrix, i, j, 1));
//             }
//         }

//         return ret;
//     }

//     int func(vector<vector<char>>& matrix, int i, int j, int r)
//     {
//         if (i + r > row || j + r > col) return -1;

//         for (int x=i; x<i+r; ++x)
//         {
//             if (matrix[x][j + r - 1] == '0')
//                 return -1;
//         }
//         for (int y=j; y<j+r; ++y)
//         {
//             if (matrix[i + r - 1][y] == '0')
//                 return -1;
//         }

//         return max(r * r, func(matrix, i, j, r + 1));
//     }

// private:
//     int row;
//     int col;
// };