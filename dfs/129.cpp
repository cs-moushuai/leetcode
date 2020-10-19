#include <iostream>

using namespace std;

//Definition for a binary tree node.
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
    void dfs(TreeNode *root, int num, int &sum)
    {
        if(root == nullptr)
        {
            return;
        }

        num = num * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            sum += num;
            return;
        }

        dfs(root->left, num, sum);
        dfs(root->right, num, sum);

    }
    int sumNumbers(TreeNode* root)
    {
        //vector<int> result;
        int sum = 0;
        dfs(root, 0, sum);

        return sum;
    }
};

int main(void)
{

    return 0;
}
