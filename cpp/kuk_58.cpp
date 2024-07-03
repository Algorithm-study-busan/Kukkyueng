#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool isCounting = false;
        for (int i=s.size() - 1; i >= 0; --i)
        {
            if (!isCounting)
            {
                if (s[i] != ' ')
                {
                    isCounting = true;
                    count += 1;
                }                    
            }
            else
            {
                if (s[i] == ' ') break;
                count += 1;
            }
        }

        return count;
    }
};