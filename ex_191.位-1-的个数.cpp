#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    string hammingWeight(uint32_t n)
    {
        string s;
        back_insert_iterator<string> i(s);

        do
        {
            if (n % 2 == 1)
            {
                i = '1';
            }
            else
            {
                i = '0';
            }

            n /= 2;

        } while (n != 0);

        reverse(s.begin(), s.end());

        return s;
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    int num;
    cin >> num;
    cout << sy.hammingWeight(num) << endl;
    return 0;
}
/* class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        do
        {
            if (n % 2 == 1)
            {
                count++;
            }
            n /= 2;

        } while (n != 0);

        return count;
    }
};
 */