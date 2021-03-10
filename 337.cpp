#include <bits/stdc++.h>
#include <unordered_map>

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

struct SubTreeStatus
{
    int noSelected;
    int selected;
};

class Solution
{
private:
    SubTreeStatus dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int selected = root->val + l.noSelected + r.noSelected;
        int noSelected = max(l.selected, l.noSelected) + max(r.selected, r.noSelected);
        return {noSelected, selected};
    }
public:
    int rob(TreeNode *root)
    {
        auto res = dfs(root);
        return max(res.noSelected, res.selected);
    }
};

class Solution4
{
private:
    int f = 0, g = 0;
    void dfs(TreeNode *root)
    {
        if (!root)
        {
            f = g = 0;
            return;
        }
        dfs(root->left);
        int g1 = g;
        int f1 = f;
        dfs(root->right);
        int g2 = g;
        int f2 = f;
        f = root->val + g1 + g2;
        g = max(f1, g1) + max(f2, g2);
    }
public:

    int rob(TreeNode* root)
    {
        dfs(root);
        return max(f, g);
    }
};


class Solution3
{
private:
    unordered_map<TreeNode *, int> f, g;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }
public:

    int rob(TreeNode* root)
    {
        dfs(root);
        return max(f[root], g[root]);
    }
};

class Solution2
{
public:
    int rob(TreeNode* root)
    {
    }
};

int main(void)
{

    return 0;
}
