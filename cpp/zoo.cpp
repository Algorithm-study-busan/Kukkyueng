#include <iostream>
using namespace std;

int MOD = 9901;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    int dp[100001][2];
    
/*
dp[i] = 전에놓은경우 + 전에안놓은경우

전에놓은경우 = 2 * dp[i - 1]
전에안놓은경우 = dp[i - 1]


dp[i][0] : 현재 층에 하나도 안 놓는 경우
dp[i][1] : 현재 층 왼쪽에 하나 놓는 경우

dp[i][0] = dp[i-1][0] + dp[i-1][1] * 2
dp[i][1] = dp[i-1][0] + dp[i-1][1]

result = dp[n][0] + dp[n][1] * 2
*/

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i=2; i<=n; ++i)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] * 2) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }

    cout << (dp[n][0] + 2 * dp[n][1]) % MOD;
}