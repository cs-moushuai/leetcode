#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int n;
    void rotateOne(vector<vector<int>>& matrix, int start, int end)
    {
        int val = matrix[start][start];
        for (int i = start; i + 1 <= end; ++i)
        {
            int tmp = matrix[start][i + 1];
            matrix[start][i + 1] = val;
            val = tmp;
        }
        for (int i = start; i + 1 <= end; ++i)
        {
            int tmp = matrix[i + 1][end];
            matrix[i + 1][end] = val;
            val = tmp;
        }
        for (int i = end; i - 1 >= start; --i)
        {
            int tmp = matrix[end][i - 1];
            matrix[end][i - 1] = val;
            val = tmp;
        }
        for (int i = end; i - 1 >= start; --i)
        {
            int tmp = matrix[i - 1][start];
            matrix[i - 1][start] = val;
            val = tmp;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix)
    {
        n = matrix.size();
        int counts = n / 2;
        int start = 0, end = n - 1;
        for (int i = 0; i < counts; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                rotateOne(matrix, start, end);
            }
            ++start;
            --end;
            n -= 2;
        }

    }
};

int main(void)
{
    vector<vector<int>> vec = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    for (auto i : vec)
    {
        for (auto j : i)
        {
            cout << j << "\t";
        }
        cout << endl;
    }
    cout << endl;
    Solution sy;
    sy.rotate(vec);
    for (auto i : vec)
    {
        for (auto j : i)
        {
            cout << j << "\t";
        }
        cout << endl;
    }
    return 0;
}
