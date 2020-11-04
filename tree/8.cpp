#include <iostream>

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
public:
    bool dfs(TreeNode *root, int my_sum, int sum)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            my_sum += root->val;
            return my_sum == sum;
        }

        int a = 0, b = 0;
        if(root->left)
        {
            a = dfs(root->left, my_sum + root->val, sum);
        }
        if(root->right)
        {
            b = dfs(root->right, my_sum + root->val, sum);
        }
        return  a || b;
    }

    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == nullptr)
        {
            return false;
        }

        return dfs(root, 0, sum);
    }
};

int main(void)
{

    return 0;
}
