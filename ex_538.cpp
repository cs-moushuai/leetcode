#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <vector>

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
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root)
    {
        if (root)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};


class Solution2
{
private:
    vector<int> arr;
    vector<int> acc;
    int len;
    unordered_map<int, int> menu;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        arr.emplace_back(root->val);
        dfs(root->right);
    }
    void dfs2(TreeNode *root)
    {
        if (!root)
            return;
        dfs2(root->left);
        root->val = menu[root->val];
        dfs2(root->right);
    }
    void accCount()
    {
        acc = arr;
        len = acc.size();
        for (int i = len - 2; i >= 0; --i)
        {
            acc[i] += acc[i + 1];
        }
    }
public:
    TreeNode* convertBST(TreeNode* root)
    {
        dfs(root);
        accCount();
        for (int i = 0; i < len; ++i)
        {
            menu.emplace(make_pair(arr[i], acc[i]));
        }
        dfs2(root);
        return root;
    }
};

int main(void)
{

    return 0;
}
