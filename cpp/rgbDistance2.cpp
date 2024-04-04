#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int prices[1001][3];
    for (int i=1; i<=n; ++i)
        for (int j=0; j<3; ++j)
            cin >> prices[i][j];

    // dp[a][b] : a번째 집의 b번째를 칠하는 비용 중 최솟값
    int dp[1001][3];
    int result = 987654321;
    for (int start = 0; start < 3; ++start)
    {
        for (int i=0; i<3; ++i)
        {
            if (i == start) dp[1][i] = prices[1][i];
            else dp[1][i] = 987654321;
        }

        for (int i=2; i<=n; ++i)
        {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + prices[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + prices[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + prices[i][2];
        }

        for (int end=0; end<3; ++end)
        {
            if (start != end)
                result = min(result, dp[n][end]);
        }
    }

    cout << result;
}