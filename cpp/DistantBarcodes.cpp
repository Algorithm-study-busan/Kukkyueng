// [LC] 1054 Greedy Fail
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool static cmp(pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int numCount[10001] = {0, };
        for (auto& e : barcodes)
            numCount[e] += 1;

        vector<pair<int, int>> num_count;
        
        for (int i=1; i<=10000; ++i)
        {
            if (numCount[i] != 0)
                num_count.push_back({i, numCount[i]});
        }
        
        sort(num_count.begin(), num_count.end(), cmp);

        vector<int> res(barcodes.size());

        int resIndex = 0;
        for (auto& e : num_count)
        {
            int num = e.first;
            int count = e.second;

            for (int i=0; i<count; ++i)
            {
                res[resIndex] = num;
                resIndex += 2;

                if (resIndex >= barcodes.size())
                    resIndex = 1;
            }
        }

        return res;
    }
};

int main() {}