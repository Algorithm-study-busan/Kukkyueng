#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int arr[100001];

    for (int i=1; i<=n; ++i)
    {
        cin >> arr[i];
    }

    int dpLeft[100001];
    int dpRight[100001];
    dpLeft[1] = arr[1];
    dpRight[n] = arr[n];

    int result = dpLeft[1];
    for (int i=2; i<=n; ++i)
    {
        dpLeft[i] = max(dpLeft[i-1] + arr[i], arr[i]);
        dpRight[n-i+1] = max(dpRight[n-i+2] + arr[n-i+1], arr[n-i+1]);
        result = max(result, dpLeft[i]);
    }

    for (int i=n - 1; i >= 1; --i)
    {
        dpRight[i] = max(dpRight[i+1] + arr[i], arr[i]);
        result = max(result, dpRight[i]);
    }

    for (int i=2; i<=n-1; ++i)
    {
        result = max(result, dpLeft[i-1] + dpRight[i+1]);
    }

    cout << result;
}