// [LC] 1005 Greedy
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    1. 절댓값 기준 내림차순 정렬
    2. nums[i] >= 0 이면 continue
    3. nums[i] < 0 이면 - 붙이고 k -= 1
    4. 끝이 났는데
    4-1. k 가 남았다면 올라가면서 남은 개수만큼 - 붙임
    4-2. 끝이 안 났다면 그대로 답 계산 후 종료
    */
    bool mysort(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //sort(nums.begin(), nums.end(), mysort);

        for (int i=0; i<nums.size(); ++i)
        {
            for (int j = i; j<nums.size(); ++j)
            {
                if (abs(nums[i]) < abs(nums[j]))
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

        int res = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            // k를 다 썼다면 남은 수들을 다 더한다.
            if (k <= 0)
            {
                res += nums[i];
                continue;
            }
            
            // 양수라면 결괏값에 더한다.
            if (nums[i] >= 0)
            {
                res += nums[i];
            }
            // 음수라면 k를 하나 써서 양수로 만든 뒤 더한다.
            else
            {
                nums[i] = -nums[i];
                res += -nums[i];
                k -= 1;
            }
        }

        // 만약 k가 남았다면 현재 nums의 원소는 모두 양수이고 결괏값에 더해졌다.
        // 남은 k가 홀수라면 절댓값이 가장 작은 원소만 음수로 바꾼다.
        if (k % 2 == 1)
            res -= 2 * nums[nums.size() - 1]; // 이미 더해진 것도 빼야하기 때문에 2를 곱함.

        return res;
    }
};

int main() {}