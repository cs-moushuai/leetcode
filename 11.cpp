#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int len = height.size();
        int l = 0, r = len - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(area, ans);
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return ans;
    }
};

//class Solution
//{
//private:
//int getArea(int left, int right, const vector<int> &height)
//{
//int y = min(height[left], height[right]);
//int x = right - left;
//return x * y;
//}
//public:
//int maxArea(vector<int>& height)
//{
//int len = height.size();
//int max_V = 0;
//for (int left = 0; left < len; ++left)
//{
//for (int right = left + 1; right < len; ++right)
//{
//if (height[right] < )
//max_V = max(max_V, getArea(left, right, height));
//}
//}
//return max_V;
//}
//};

int main(void)
{

    return 0;
}
