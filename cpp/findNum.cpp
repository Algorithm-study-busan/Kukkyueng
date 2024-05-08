// BOG 1920 수찾기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> numN(n);
    for (auto& e : numN)
        cin >> e;
    int m; cin >> m;
    vector<int> numM(m);
    for (auto& e : numM)
        cin >> e;

    sort(numN.begin(), numN.end());

    // binary search
    for (auto& e : numM)
    {
        int start = 0;
        int end = n - 1;
        
        bool isFind = false;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (e < numN[mid])
                end = mid - 1;
            else if (e > numN[mid])
                start = mid + 1;
            else
            {
                isFind = true;
                break;
            }
        }
        cout << isFind ? 1 : 0;
        cout << '\n';
    }
}