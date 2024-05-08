// BOG 2751 수 정렬하기2

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> nums(n);
    for (auto& e : nums)
        cin >> e;

    sort(nums.begin(), nums.end());
    for (auto& e : nums)
        cout << e << '\n';
}