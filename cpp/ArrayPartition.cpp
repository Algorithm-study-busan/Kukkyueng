// [LC] 561 Greedy
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i=0; i<nums.size(); i += 2)
        {
            res += min(nums[i], nums[i + 1]);
        }

        return res;
    }
};

int main() {}