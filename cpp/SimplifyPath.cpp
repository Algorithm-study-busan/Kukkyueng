// LEET 71. Simplify Path
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> split(string str, char delemiter)
    {
        istringstream iss(str);
        string buffer;

        vector<string> result;

        while (getline(iss, buffer, delemiter))
        {
            result.push_back(buffer);
        }

        return result;
    }


    string simplifyPath(string path) {
        vector<string> splitPath = split(path, '/');

        deque<string> dq;
        string result = "";
        for (auto& e : splitPath)
        {
            if (e == "..")
            {
                if (!dq.empty())
                    dq.pop_back();
            }
            else if (e == ".")
                continue;
            else if (e != "")
            {
                dq.push_back(e);
            }
        }

        if (dq.size() == 0)
            return "/";

        while (!dq.empty())
        {
            result += "/" + dq.front();
            dq.pop_front();
        }

        return result;
    }
};