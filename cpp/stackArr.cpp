// BOG 1874 스택수열

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> nums(n);
    for (auto& e : nums)
        cin >> e;

    stack<int> s;

    int curIdx = 0;
    string result = "";

    for (int i=1; i<=n; ++i)
    {
        s.push(i); 
        result += "+\n";
        //cout << "Push " << i << '\n';

        // 다른게 나올 때 까지 POP을 해야하니 반복문 돌려
        while (nums[curIdx] == s.top())
        {
            //cout << "Pop " << i << '\n';
            s.pop();
            result += "-\n";
            curIdx += 1;

            // 예외 처리를 해줘야 해
            if (s.empty() || curIdx >= n) break;
        }
    }

    while (!s.empty())
    {
        if (s.top() != nums[curIdx])
        {
            result = "NO";
            break;
        }

        s.pop();
        result += "-\n";
    }

    cout << result;
}