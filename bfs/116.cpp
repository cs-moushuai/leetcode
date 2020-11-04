#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node (): val (0), left (NULL), right (NULL), next (NULL)
    {
    }

    Node (int _val): val (_val), left (NULL), right (NULL), next (NULL)
    {
    }

    Node (int _val, Node * _left, Node * _right, Node * _next): val (_val),
        left (_left), right (_right), next (_next)
    {
    }
};

class Solution
{
public:
    Node * connect (Node * root)
    {
        if (!root)
        {
            return root;
        }
        queue < Node * >que;
        que.push (root);

        while (!que.empty ())
        {
            int size = que.size ();

            Node *tmp = que.front ();
            que.pop ();
            if (tmp->left)
                que.push (tmp->left);
            if (tmp->right)
                que.push (tmp->right);

            for (int i = 1; i < size; i++)
            {
                Node *curr = que.front ();
                que.pop ();
                tmp->next = curr;
                tmp = curr;
                if (tmp->left)
                    que.push (tmp->left);
                if (tmp->right)
                    que.push (tmp->right);
            }

        }

        return root;
    }
};

int main(void)
{

    return 0;
}
