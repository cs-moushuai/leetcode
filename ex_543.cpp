#include <bits/stdc++.h>
#include <cstddef>
#include <endian.h>

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
private:
    int max_depth = 0;
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        max_depth = max(max_depth, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);
        return max_depth;
    }
};

//class Solution
//{
//private:
//int max_val = 0;
//public:
//int maxLength(TreeNode *root, int len)
//{
//if (root == nullptr)
//return len - 1;
//return max(maxLength(root->left, len + 1), maxLength(root->right, len + 1));
//}
//int maxOfNode(TreeNode *root)
//{
//if (!root)
//{
//return 0;
//}
//if (!root->left)
//{
//return maxLength(root, 0);
//}
//if (!root->right)
//{
//return maxLength(root, 0);
//}
//return maxLength(root->left, 0) + maxLength(root->right, 0) + 2;

//}
//void Dfs(TreeNode *root)
//{
//if (!root)
//{
//return;
//}
//max_val = max(max_val, maxOfNode(root));
//Dfs(root->left);
//Dfs(root->right);
//}
//int diameterOfBinaryTree(TreeNode* root)
//{
//Dfs(root);
//return max_val;
//}
//};

int main(void)
{

    return 0;
}
