#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int target;
    int res = 0;
    unordered_map<int, int> prefixSum;
    void Dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;
        sum += root->val;
        res += prefixSum[sum - target];
        ++prefixSum[sum];
        Dfs(root->left, sum);
        Dfs(root->right, sum);

        --prefixSum[sum];
    }
public:
    int pathSum(TreeNode* root, int sum)
    {
        target = sum;
        prefixSum[0] = 1;
        Dfs(root, 0);
        return res;
    }
};

class Solution2
{
private:
    int method = 0;
    int target;
    void dfs(TreeNode *root, int sum)
    {
        if (sum == target)
            ++method;
        if (!root)
            return;
        dfs(root->left, sum);
        dfs(root->left, sum + root->val);
        dfs(root->right, sum);
        dfs(root->right, sum + root->val);
    }
public:
    int pathSum(TreeNode* root, int sum)
    {
        target = sum;
        dfs(root, 0);
        return method;
    }
};

int main(void)
{

    return 0;
}
