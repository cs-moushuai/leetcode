#include <algorithm>
#include <bits/stdc++.h>
#include <pthread.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = m - 1;
        int col = 0;
        while (col < n && row >= 0)
        {
            if (target > matrix[row][col])
                col++;
            else if (target < matrix[row][col])
                row--;
            else
                return true;
        }
        return false;

    }

    //bool searchMatrix(vector<vector<int>>& matrix, int target)
    //{
    //auto right_bound_iter = upper_bound(matrix[0].begin(), matrix[0].end(), target);
    //int right_bound = right_bound_iter - matrix[0].begin();
    //if (right_bound == 0)
    //return false;
    //int m = matrix.size();
    //for (int i = right_bound - 1; i >= 0; i--)
    //{
    //vector<int> tmp(m);
    //for (int j = 0; j < m; j++)
    //{
    //tmp[j] = matrix[j][i];
    //}
    //auto down_bound = upper_bound(tmp.begin(), tmp.end(), target);
    //if (down_bound == tmp.begin())
    //continue;
    //if (*(down_bound - 1) == target)
    //return true;
    //}
    //return false;

    //}
};

int main(void)
{
    Solution sy;
    vector<vector<int>> obj{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    cout << sy.searchMatrix(obj, 8) << endl;

    return 0;
}
