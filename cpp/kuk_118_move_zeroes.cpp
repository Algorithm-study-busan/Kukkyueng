// 리트코드 118
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret = vector<vector<int>>(numRows);
        for (int i=0; i<numRows; ++i)
        {
            ret[i] = vector<int>(i+1, -1);;
            ret[i][0] = 1;
            ret[i][i] = 1;
        }
            
        for (int i=0; i<numRows; ++i)
        {
            for (int j=0; j<=i; ++j)
            {
                if (ret[i][j] != -1) continue;

                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }

        return ret;
    }
};