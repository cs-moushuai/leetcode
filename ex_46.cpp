#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<short> visited;
    vector<vector<int>> res;
    vector<int> nums_;
    int len;
public:
    void dfs(vector<int> &one, int size)
    {
        if (size == len)
        {
            res.emplace_back(one);
            return;
        }
        for (int i = 0; i < len; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                one.emplace_back(nums_[i]);
                dfs(one, size + 1);
                one.pop_back();
                visited[i] = false;

            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        nums_ = nums;
        len = nums.size();
        visited.resize(len, 0);
        vector<int> one;
        dfs(one, 0);

        return res;
    }
};

int main(void)
{

    return 0;
}
