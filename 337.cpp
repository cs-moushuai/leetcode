#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int rob(TreeNode* root)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        else if (len == 1)
            return nums[0];
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; ++i)
        {
            dp[i] = max( + nums[i], dp[i - 1]);

        }
        return dp[len - 1];

    }
};

int main(void)
{

    return 0;
}
