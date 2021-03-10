#include <bits/stdc++.h>
#include <iterator>
#include <numeric>
#include <unordered_map>

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
    int target;
    int res = 0;
    unordered_map<int, int> prefixSum;
    void Dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;
        sum += root->val;
        res += prefixSum[sum - target];
        ++prefixSum[sum];
        Dfs(root->left, sum);
        Dfs(root->right, sum);
        --prefixSum[sum];
    }
public:
    int pathSum(TreeNode *root, int sum)
    {
        target = sum;
        prefixSum.emplace(0, 1);
        Dfs(root, 0);
        return res;
    }
};

int main(void)
{
    auto i = accumulate(istream_iterator<int>(cin), istream_iterator<int>(), 0);
    cout << i << endl;

    return 0;
}
