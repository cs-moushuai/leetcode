#include <iostream>
#include <vector>
#include <queue>

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

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(!root)
        {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize = q.size();

            res.push_back(vector<int>());
            for(int i = 0; i < levelsize; i++)
            {
                auto curr = q.front();
                q.pop();

                res.back().push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }

            }
        }


        return res;
    }

private:
    vector<vector<int>> res;
};

int main(void)
{

    return 0;
}
