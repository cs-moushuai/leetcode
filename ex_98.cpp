#include <bits/stdc++.h>
#include <climits>

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
    int comp = INT_MIN;
    bool flag = true;
    bool first = false;
    void Dfs(TreeNode *root)
    {
        if (!root)
            return;

        Dfs(root->left);
        if (!first)
        {
            first = true;
        }
        else
        {
            if (root->val <= comp)
            {
                flag = false;
            }
        }
        comp = root->val;
        Dfs(root->right);
    }
public:
    bool isValidBST(TreeNode* root)
    {
        Dfs(root);
        return flag;
    }
};

int main(void)
{

    return 0;
}
