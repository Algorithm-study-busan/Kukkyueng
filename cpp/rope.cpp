// BOG 2217

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    
    vector<int> ropes(n);
    for (auto& e : ropes)
        cin >> e;

    sort(ropes.begin(), ropes.end(), greater<int>());

    int result = -1;

    for (int i=0; i<n; ++i)
    {
        int k = i + 1;
        int maxW = k * ropes[i];
        result = max(result, maxW);
    }

    cout << result;
}