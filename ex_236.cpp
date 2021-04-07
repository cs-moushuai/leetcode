#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    TreeNode *ans = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return false;
        bool l_flag = dfs(root->left, p, q);
        bool r_flag = dfs(root->right, p, q);
        if ((l_flag && r_flag) || ((root->val == p->val || root->val == q->val) && (l_flag || r_flag)))
            ans = root;
        return l_flag || r_flag || root->val == p->val || root->val == q->val;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        dfs(root, p, q);
        return ans;

    }
};

class Solution2
{
private:
    TreeNode *res = nullptr;
    bool flag_res = false;
    bool flag_p = false;
    bool flag_q = false;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return;
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        if (root == p)
            flag_p = true;
        if (root == q)
            flag_q = true;
        if (!flag_res && flag_p && flag_q && findNode(root, p) && findNode(root, q))
        {
            flag_res = true;
            res = root;
        }
    }
    bool findNode(TreeNode *root, TreeNode *tar)
    {
        if (!root)
            return false;
        if (root != tar)
            return findNode(root->left, tar) || findNode(root->right, tar);
        else
            return true;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        dfs(root, p, q);
        return res;
    }
};

int main(void)
{

    return 0;
}
