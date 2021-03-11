#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int len = nums.size();
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < k; ++i)
        {
            que.push(pair<int, int> {nums[i], i});
        }

        vector<int> res{que.top().first};
        for (int i = k; i < len; ++i)
        {
            que.push({nums[i], i});
            while (que.top().second <= i - k)
            {
                que.pop();
            }
            res.emplace_back(que.top().first);
        }
        return res;
    }
};

int main(void)
{

    return 0;
}
