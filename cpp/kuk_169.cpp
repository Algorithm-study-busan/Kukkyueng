#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int maxCount = -1;
        int ret = nums[0];
        for (int i=0; i<nums.size(); ++i)
        {
            m[nums[i]] += 1;
            if (maxCount < m[nums[i]])
            {
                maxCount = m[nums[i]];
                ret = nums[i];
            }
        }
        return ret;
    }
};