#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    /*
    반례
    3
    4 4
    3 4
    2 4
    */
   if (a.second == b.second) return a.first < b.first;
   return a.second < b.second;
}

int main()
{
   cin.tie(NULL); cout.tie(NULL);
   ios::sync_with_stdio(false);

    // 시작 시간 vs 종료 시간
    // 그냥 무조건 끝나는 시간 빠른거 하는게 이득 아님?

   int n; cin >> n;
   vector<pair<int, int>> meetings(n);
   for (auto& e : meetings)
   {
      cin >> e.first >> e.second;
   }

   sort(meetings.begin(), meetings.end(), mycmp);
   /*for (auto& e : meetings)
   {
      cout << e.first << ' ' << e.second << '\n';
   }*/

   int result = 1;
   int start = meetings[0].first;
   int end = meetings[0].second;
   for (int i = 1; i < meetings.size(); ++i)
   {
      if (meetings[i].first < end) continue;

      start = meetings[i].first;
      end = meetings[i].second;
      result += 1;
   }

   cout << result;
}