// LEET 1700. Number of Studnerts Unable to Eat Lunch
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
/*
0 : circular, 1 : square
각 학생은 둘 중 하나를 선호
샌드위치의 수 == 학생 수

*/
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> line, food;
        for (auto e : students)
            line.push(e);
        for (auto e : sandwiches)
            food.push(e);

        int loopCount = 0;
        while (!line.empty())
        {
            if (line.front() == food.front())
            {
                loopCount = 0;

                cout << line.front() << " out!\n";
                line.pop();
                food.pop();
            }
            else
            {
                loopCount += 1;


                cout << line.front() << " in!\n";
                line.push(line.front());
                line.pop();
            }

            if (loopCount > line.size())
                break;
        }

        return line.size();
    }
};

int main() {}