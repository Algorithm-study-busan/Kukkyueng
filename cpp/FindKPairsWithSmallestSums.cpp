// LEET 373. Find K Pairs with Smallest Sums
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int sum, i, j;

    Node(int _sum, int _i, int _j) : sum(_sum), i(_i), j(_j) {}

    bool operator<(const Node& other) const
    {
        return sum > other.sum;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        map<int, bool> visited[100001];
        priority_queue<Node> pq;
        pq.push(Node(nums1[0] + nums2[0], 0, 0));
        visited[0][0] = true;

        while (k > 0)
        {
            Node here = pq.top();
            pq.pop();

            vector<int> v = {nums1[here.i], nums2[here.j]};
            result.push_back(v);

            if (here.i + 1 < nums1.size() && !visited[here.i + 1][here.j])
            {
                int nextSum = nums1[here.i + 1] + nums2[here.j];
                int nextI = here.i + 1;
                int nextJ = here.j;
                pq.push(Node(nextSum, nextI, nextJ));
                visited[nextI][nextJ] = true;
            }
            
            if (here.j + 1 < nums2.size() && !visited[here.i][here.j + 1])
            {
                int nextSum = nums1[here.i] + nums2[here.j + 1];
                int nextI = here.i;
                int nextJ = here.j + 1;
                pq.push(Node(nextSum, nextI, nextJ));
                visited[nextI][nextJ] = true;
            }

            k -= 1;
        }


        return result;
    }
};