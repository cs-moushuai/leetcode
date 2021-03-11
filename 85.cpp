#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> width(m, vector<int>(n, 0));
        int maxArea = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    width[i][j] = (j == 0) ? 1 : width[i][j - 1] + 1;
                }
                else
                {
                    width[i][j] = 0;
                }
                int minWidth = width[i][j];
                for (int row = i; row >= 0; --row)
                {
                    int height = i - row + 1;
                    minWidth = min(minWidth, width[row][j]);
                    maxArea = max(maxArea, minWidth * height);
                }
            }

        }
        return maxArea;
    }
};

int main(void)
{

    return 0;
}
