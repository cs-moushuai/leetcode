#include <bits/stdc++.h>

using namespace std;

/**
 *  * Definition for a binary tree node.
 *           */


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
    deque<TreeNode *> que;
public:
    void Dfs(TreeNode *root)
    {
        if (!root)
            return;
        que.push_back(root);
        Dfs(root->left);
        Dfs(root->right);
    }
    void flatten(TreeNode* root)
    {
        if (!root)
            return;
        Dfs(root);
        int len = que.size();
        for (int i = 1; i < len; ++i)
        {
            que[i - 1]->left = nullptr;
            que[i - 1]->right = que[i];
        }
    }
};

class Solution2
{
private:
    TreeNode *res, *end;
public:
    void Dfs(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *newnode = new TreeNode(root->val);
        end->right = newnode;
        end = end->right;
        Dfs(root->left);
        Dfs(root->right);
    }
    void flatten(TreeNode* root)
    {
        if (!root)
            return;
        res = end = new TreeNode(root->val);
        Dfs(root->left);
        Dfs(root->right);
        root->left = nullptr;
        root->right = res->right;
    }
};

int main(void)
{
    Solution sy;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = nullptr;
    root->right->right = new TreeNode(6);
    sy.flatten(root);

    return 0;
}
