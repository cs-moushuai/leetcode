#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    vector<string> arr;
    int arr_len;


    TreeNode *Heapify(int pos)
    {
        if (pos >= arr_len)
            return nullptr;
        string str = arr[pos];
        TreeNode *root;
        if (str == ",")
            root = nullptr;
        else
        {
            root = new TreeNode(stoi(str));
            root->left = Heapify(2 * pos + 1);
            root->right = Heapify(2 * pos + 2);
        }
        return root;

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        queue<TreeNode *> que;
        string res;
        que.push(root);
        bool flag = false;
        while (!que.empty())
        {
            int len = que.size();
            for (int i = 0; i < len; ++i)
            {
                TreeNode *Node = que.front();
                que.pop();

                if (Node)
                {
                    res += " " + to_string(Node->val);
                    que.push(Node->left);
                    que.push(Node->right);
                }
                else
                {
                    res += " ,";
                    flag = true;
                }
            }
            if (flag)
                break;

        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        istringstream in(data);
        while (!in.eof())
        {
            string str;
            in >> str;
            arr.emplace_back(str);
        }
        arr_len = arr.size();
        return Heapify(0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(void)
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Codec sy;
    sy.deserialize(sy.serialize(root));

    return 0;
}
