// LEET 2099. Find Subsequence of Length K With the Largest Sum
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> num_indexs;
        for (int i=0; i<nums.size(); ++i)
            num_indexs.push_back({nums[i], i});

        sort(num_indexs.begin(), num_indexs.end(), greater<pair<int, int>>());

        vector<pair<int, int>> subIndex_nums;
        for (int i=0; i<k; ++i)
            subIndex_nums.push_back({num_indexs[i].second, num_indexs[i].first});

        sort(subIndex_nums.begin(), subIndex_nums.end());
        vector<int> ret;
        for (auto& e : subIndex_nums)
            ret.push_back(e.second);

        return ret;
    }
};