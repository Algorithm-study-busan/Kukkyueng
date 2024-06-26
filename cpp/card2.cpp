// BOG 2164 카드2

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    queue<int> card;
    int n; cin>>n;
    for (int i=1; i<=n; ++i)
        card.push(i);

    while (card.size() > 1)
    {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    cout << card.front();
}