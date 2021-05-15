#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int len = height.size();
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        int left = 0, right = len - 1;
        while (left < right)
        {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (leftMax < rightMax)
            {
                ans += leftMax - height[left++];
            }
            else
            {
                ans += rightMax - height[right--];
            }
        }
        return ans;

    }
};

class Solution2
{
public:
    int trap(vector<int>& height)
    {
        int len = height.size();
        int capacity = 0;
        for (int i = 0; i < len; )
        {
            int l_barr = height[i];
            int cost = 0, width = 1;
            int ground = height[i];
            for (int j = i - 1; j >= 0; --j)
            {
                if (height[j] >= l_barr)
                {
                    cost += l_barr - ground;
                    l_barr = height[j];
                    ++width;
                }
                else
                {
                    break;
                }
            }
            int r_barr = height[i];
            ++i;
            for (int j = i; j < len; ++j)
            {
                if (height[j] >= r_barr)
                {
                    i = j;
                    cost += r_barr - ground;
                    r_barr = height[j];
                    ++width;
                }
                else
                {
                    break;
                }

            }
            if (l_barr != r_barr && width > 2)
            {
                //cout << l_barr << ":" << r_barr << endl;
                int high = min(l_barr, r_barr) - ground;
                int area = high * (width - 2) - cost;
                //cout << area << endl;
                capacity += area;
            }
        }
        return capacity;

    }

};

int main(void)
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sy;
    std::cout << sy.trap(height)
              << std::endl;

    return 0;
}
