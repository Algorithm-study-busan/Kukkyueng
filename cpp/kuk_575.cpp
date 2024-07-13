#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int eatable = candyType.size() / 2;
        int kind = 0;
        bool visitedPos[100001] = {0, };
        bool visitedNeg[100001] = {0, };
        for (auto& e : candyType)
        {
            if (e >= 0)
            {
                if (!visitedPos[e])
                {
                    kind += 1;
                    visitedPos[e] = true;
                }
            }
            else
            {
                if (!visitedNeg[-e])
                {
                    kind += 1;
                    visitedNeg[-e] = true;
                }
            }
        }
        if (eatable > kind)
            return kind;
        return eatable;
    }
};