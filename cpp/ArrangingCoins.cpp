// LEET 441. Arranging Coins

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

class Solution {
public:
    long long func(ll n)
    {
        return n * (n + 1) / 2;
    }

    int arrangeCoins(int n) {
        ll start = 1;
        ll end = n;
        while (start <= end)
        {
            ll mid = (start + end) / 2;

            if (func(mid) < n)
            {
                start = mid + 1;
            }
            else if (func(mid) > n)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start - 1; // upper bound - 1이 다 채워진 row 개수
    }
};