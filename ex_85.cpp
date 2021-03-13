#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    int largestRectangleArea(vector<int>& heights)
    {
        int len = heights.size();

        stack<int> st;
        vector<int> left(len);
        vector<int> right(len, len);
        for (int i = 0; i < len; ++i)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();//0-1
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    heights[j] += 1;
                }
                else
                {
                    heights[j] = 0;
                }

            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

class Solution2
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
