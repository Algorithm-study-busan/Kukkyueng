#include <iostream>
using namespace std;

int MOD = 1000000000;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    // dp[현재 숫자][남은 카운트]
    // dp[0][k] = 1(k >= 1)
    // dp[n][1] = 1
    // dp[n][k] = dp[n][k - 1] + dp[n - 1][k - 1] + ... dp[0][k - 1]

    int dp[201][201] = {0, };
    for (int i=1; i<=K; ++i)
        dp[0][i] = 1;

    for (int i=0; i<=N; ++i)
        dp[i][1] = 1;

    for (int n=1; n<=N; ++n)
    {
        for (int k=2; k<=K; ++k)
        {
            for (int s=0; s<=n; ++s)
            {
                dp[n][k] = (dp[n][k] + dp[n - s][k - 1]) % MOD;
                // dp[n][k] = (dp[n][k] + dp[s][k - 1]) % MOD;
            }
        }
    }

    cout << dp[N][K];
}