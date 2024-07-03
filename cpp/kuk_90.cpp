#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(0, nums, vector<int>(), ret);
        return ret;
    }

    void dfs(int here, vector<int>& nums, vector<int> v, vector<vector<int>>& ret)
    {
        if (here >= nums.size())
        {
            sort(v.begin(), v.end());
            if (myunique(ret, v))
                ret.push_back(v);
                
            return;
        }

        dfs(here + 1, nums, v, ret);
        v.push_back(nums[here]);
        dfs(here + 1, nums, v, ret);
    }

    bool myunique(vector<vector<int>>& ret, vector<int> v)
    {
        for (auto& e : ret)
        {
            // 다르니까 다음꺼 찾아
            if (e.size() != v.size()) continue;

            // 다르니까 다음꺼 찾아
            bool isSame = true;
            for (int i=0; i<v.size(); ++i)
            {
                if (v[i] != e[i])
                {
                    isSame = false;
                    break;
                }
            }

            if (isSame)
                return false;
        }
        // 이까지 왔다는건 둘이 다르다는 뜻
        return true;
    }
};