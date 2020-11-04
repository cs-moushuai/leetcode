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
    bool check(TreeNode *root1, TreeNode *root2)
    {
        if(!root1 && !root2)
        {
            return true;
        }
        if(!root1 || !root2)
        {
            return false;
        }

        return root1->val == root2->val && check(root1->left, root2->right) && check(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        return check(root, root);
    }

};

int main(void)
{

    return 0;
}
