// LEET 123. Best Time to Buy and Sell Stock III
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left[100000] = {0, };
        int right[100000] = {0, };

        int temp = prices.front();
        for (int i=1; i<prices.size(); ++i)
        {
            temp = min(temp, prices[i]);
            left[i] = max(prices[i] - temp, left[i - 1]);
        }

        temp = prices.back();
        for (int i=prices.size() - 2; i>=0; --i)
        {
            temp = max(temp, prices[i]);
            right[i] = max(right[i + 1], temp - prices[i]);
        }

        int ret = right[0];
        for (int i=0; i<prices.size() - 1; ++i)
        {
            ret = max(ret, left[i] + right[i+1]);
        }

        return ret;
    }
};