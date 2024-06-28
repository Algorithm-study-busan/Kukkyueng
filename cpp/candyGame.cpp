// BOG 3085 사탕게임, 브루트포스

#include <iostream>
using namespace std;

int n;
char board[51][51];

void swap(char& a, char& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int maxCnt()
{
    int result = -1;
    int count;

    // row
    for (int i=0; i<n; ++i)
    {
        count = 1;
        for (int j=0; j<n-1; ++j)
        {
            if (board[i][j] == board[i][j+1])
            {
                count += 1;
            }
            else
            {
                result = max(result, count);
                count = 1;
            }
        }
        result = max(result, count);
    }

    // column
    for (int i=0; i<n; ++i)
    {
        count = 1;
        for (int j=0; j<n-1; ++j)
        {
            if (board[j][i] == board[j+1][i])
            {
                count += 1;
            }
            else
            {
                result = max(result, count);
                count = 1;
            }
        }
        result = max(result, count);
    }

    return result;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> board[i][j];

    int result = -1;

    // change
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            // Column
            if (i < n - 1)
            {
                swap(board[i][j], board[i + 1][j]);
                result = max(result, maxCnt());
                swap(board[i][j], board[i+1][j]);
            }
            // Row
            if (j < n - 1)
            {
                swap(board[i][j], board[i][j+1]);
                result = max(result, maxCnt());
                swap(board[i][j], board[i][j+1]);
            }
        }
    }

    // 50 x 50 -> 2500 * 100 * 2 = 500,000, 브루트포스로 가능
    cout << result;
}