// LEET 300. Longest Increasing Subsequence
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        for (auto& num : nums)
        {
            int idx = lowerBound(arr, num);
            if (idx == arr.size()) arr.push_back(num);
            else arr[idx] = num;
        }
        return arr.size();
    }

    // O(N^2) 풀이법
    // int lengthOfLIS(vector<int>& nums) {
    //     int dp[2502];
    //     // dp[n] = dp[0~n-1]의 최댓값 + 1, 이때 nums[n]은 nums[0~n-1] 중 최댓값 보다 커야한다
    //     for (int i=0; i<nums.size(); ++i)
    //     {
    //         int temp = 1;
    //         for (int j=0; j<i; ++j)
    //         {
    //             if (nums[j] < nums[i])
    //                 temp = max(temp, dp[j] + 1); // i가 j보다 크면 dp[j] + 1 하는거지
    //         }
    //         dp[i] = temp;
    //     }

    //     int ret = 0;
    //     for (int i=0; i<nums.size(); ++i)
    //     {
    //         ret = max(ret, dp[i]);
    //     }

    //     return ret;
    // }
};