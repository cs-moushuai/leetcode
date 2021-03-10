#include <bits/stdc++.h>
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
private:
    int middle = 0;
    int len;
public:
    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder)
    {
        if (middle == len)
            return nullptr;
        auto root_arr = find(inorder.begin(), inorder.end(), preorder[middle]);
        if (root_arr == inorder.end())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[middle++]);
        vector<int> left(inorder.begin(), root_arr);
        vector<int> right(root_arr + 1, inorder.end());
        root->left = dfs(preorder, left);
        root->right = dfs(preorder, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        len = preorder.size();
        return dfs(preorder, inorder);
    }
};

int main(void)
{

    return 0;
}
