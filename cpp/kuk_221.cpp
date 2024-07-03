#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        

        row = matrix.size();
        col = matrix[0].size();

        bool isAllOne = true;
        for (int i=0; i<row; ++i)
        {
            for (int j=0; j<col; ++j)
                if (matrix[i][j] == '0')
                {
                    isAllOne = false;
                    break;
                } 
        }

        if (isAllOne)
            return pow(min(row, col), 2);

        int ret = 0;
        for (int i=0; i<row; ++i)
        {
            for (int j=0; j<col; ++j)
            {
                if (matrix[i][j] == '1')
                    ret = max(ret, func(matrix, i, j, 1));
            }
        }

        return ret;
    }

    int func(vector<vector<char>>& matrix, int i, int j, int r)
    {
        if (i + r > row || j + r > col) return -1;

        for (int x=i; x<i+r; ++x)
        {
            if (matrix[x][j + r - 1] == '0')
                return -1;
        }
        for (int y=j; y<j+r; ++y)
        {
            if (matrix[i + r - 1][y] == '0')
                return -1;
        }

        return max(r * r, func(matrix, i, j, r + 1));
    }

private:
    int row;
    int col;
};