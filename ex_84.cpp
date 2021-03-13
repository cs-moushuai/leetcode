#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
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
};


class Solution3
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int len = heights.size();

        stack<int> st;
        int left[len];
        for (int i = 0; i < len; ++i)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();//0-1
            st.push(i);
        }
        st = stack<int>();
        int right[len];
        for (int i = len - 1; i >= 0; --i)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            right[i] = st.empty() ? len : st.top();//n-1+1
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};


class Solution2
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int len = heights.size();
        int maxArea = 0;
        for (int i = 0; i < len; ++i)
        {
            int width = 1;
            for (int j = i - 1; j >= 0; )
            {
                if (heights[j] >= heights[i])
                {
                    --j;
                    ++width;
                }
                else
                {
                    break;
                }
            }
            for (int j = i + 1; j < len; )
            {
                if (heights[j] >= heights[i])
                {
                    ++j;
                    ++width;
                }
                else
                {
                    break;
                }
            }
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};

int main(void)
{

    return 0;
}
