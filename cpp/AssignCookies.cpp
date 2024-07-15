// [LC] 455 Greedy
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // 쿠키 하나씩 나눠줄거
    // g[i] : i 아이에게 줘야하는 쿠키 크기의 최솟값, s[j] : j 쿠키의 사이즈
    // s[j] >= g[i] 여야 아이가 만족함
    // 오름차순으로 해서 가성비 좋게 쿠키를 쥐어주면 되지 않을까. 그리디로
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0;
        int j=0;
        int res = 0;

        while (i <g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                res += 1;
                i += 1;
            }

            j += 1;
        }
        
        return res;
    }
};

int main() {}