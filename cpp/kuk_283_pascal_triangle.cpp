// 리트코드 283
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // for (int i=0; i<nums.size(); ++i)
        // {
        //     for (int j=i+1; j<nums.size(); ++j)
        //     {
        //         if (nums[i] == 0 && nums[j] != 0)
        //         {
        //             nums[i] = nums[j];
        //             nums[j] = 0;
        //         }
        //     }
        // }

        int zeroCount = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] == 0)
                zeroCount += 1;
            else if (zeroCount > 0)
            {
                nums[i-zeroCount] = nums[i];
                nums[i] = 0;
            }
        }
    }
};