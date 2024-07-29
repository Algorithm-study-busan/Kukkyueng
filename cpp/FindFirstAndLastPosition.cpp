// LEET 34. Find First and Last Position of Element in Sorted Array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1; // lower bound 바로 전 index를 가리킴

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] >= target)
            {
                end = mid - 1;
            }
        }

        return start;
    }

    int upperBound(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1; // 얘는 upperBound 바로 전 index를 가리킴

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] <= target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
        }

        return start;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);

        if (lower == nums.size() || nums[lower] != target)
        {
            return vector<int>{-1, -1};
        }

        return vector<int> {lower, upper - 1};
    }
};