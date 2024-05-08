// BOG 1018 체스판 다시 칠하기

#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string board[51];
    for (int i=0; i<n; ++i)
    {
        cin >> board[i];
        if (board[i].size() != m)
        {
            cout << "Input Error";
            return 0;
        }            
    }

    // 첫칸이 흰색인 경우, 검정인 경우 나눠서 
    // Brute Force 하면 될듯

    int result = INT32_MAX;

    for (int i=0; i<=n-8; ++i)
    {
        for (int j=0; j<=m-8; ++j)
        {
            int firstWhite = 0;
            int firstBlack = 0;
            for (int x = i; x < i + 8; ++x)
            {
                for (int y = j; y < j + 8; ++y)
                {
                    if ((x + y) % 2 == 0)
                    {
                        if (board[x][y] == 'W')
                            firstBlack += 1;
                        else 
                            firstWhite += 1;
                    }
                    else
                    {
                        if (board[x][y] == 'B')
                            firstBlack += 1;
                        else 
                            firstWhite += 1;
                    }
                }
            }
            result = min(result, min(firstWhite, firstBlack));
        }
    }

    cout << result;
}