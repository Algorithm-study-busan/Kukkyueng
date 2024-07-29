// LEET 668. Kth Smallest Number in Multiplication Table

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // x보다 작거나 같은 원소의 개수
    int f(int x, int m, int n)
    {
        int ret = 0;
        for (int i=1; i<=m; ++i)
        {
            // row를 돌면서 그 행에서 작거나 같은 원소의 개수를 세서 결괏값에 더한다
            // column수가 위 결괏값보다 작으면 column 수를 더해줘야 한다
            ret += min(n, x / i);
        }
        return ret;
    }

    int findKthNumber(int m, int n, int k) {
        // [1, m x n]를 binarySearch

        int start = 1;
        int end = m * n;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (f(mid, m, n) < k)
            {
                start = mid + 1;
            }
            else if (f(mid, m, n) > k)
            {
                end = mid - 1;;
            }
            else
            {
                end = mid - 1;
            }
        }

        return start;
    }
};