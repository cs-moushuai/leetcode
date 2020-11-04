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
    void Dfs(TreeNode *root, int depth)
    {
        if(root == nullptr)
        {
            if(depth - 1 > max_depth)
            {
                max_depth = depth - 1;
            }
            return;
        }
        Dfs(root->left, depth + 1);
        Dfs(root->right, depth + 1);
    }

    int maxDepth(TreeNode* root)
    {
        Dfs(root, 1);

        return max_depth;
    }
private:
    int max_depth;
};

int main(void)
{

    return 0;
}
