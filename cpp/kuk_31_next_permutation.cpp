// 리트코드 31
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool isDescending = true;
        for (int i=nums.size() - 1; i>0; --i)
        {
            if (nums[i - 1] < nums[i])
            {
                findAndSort(nums, i - 1);
                isDescending = false;
                break;
            }
        }
        if (isDescending)
            sort(nums.begin(), nums.end());
    }

    void findAndSort(vector<int>& nums, int index)
    {
        reverse(nums.begin() + index + 1, nums.end());

        int nearestIndex = index + 1;
        for (int i=index + 1; i<nums.size(); ++i)
        {
            if (nums[index] < nums[i])
            {
                nearestIndex = i;
                break;
            }
        }

        swap(nums[index], nums[nearestIndex]);        
    }

    void swap(int& a, int& b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
};