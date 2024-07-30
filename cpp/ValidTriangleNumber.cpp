// LEET 611. Valid Triangle Number

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // @return - k보다 작은 수 중 가장 큰 수 - lower_bound - 1
    // @param - k : 나머지 두 수의 합
    // nums는 정렬되어 크거나 같은 수를 반환하기 때문에 nums[mid] >= sum 만 확인하면 된다
    int upperBound(vector<int>& nums, int start, int sum)
    {
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] < sum)
            {
                start = mid + 1;
            }
            else if (nums[mid] >= sum)
            {
                end = mid - 1;
            }
        }
        return start;
    }

    int triangleNumber(vector<int>& nums) {
        // 가장 긴 변이 나머지 두 변의 합보다 같거나 크면 탈락

        sort(nums.begin(), nums.end());

        int result = 0;

        // logn * n^2
        for (int i = 0; i<nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                int k = upperBound(nums, j + 1, nums[i] + nums[j]);

                result += k - j - 1;

                //cout << "(" << nums[i] << ", " << nums[j] << "), " << k << '\n';
            }
        }

        return result;
    }
};