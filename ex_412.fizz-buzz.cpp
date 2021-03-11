#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> str;

        for (size_t i = 1; i <= n; i++)
        {
            if(i%3 == 0 && i % 5 == 0)
            {
                str.push_back("FizzBuzz");
            }
            else if( i % 3 == 0)
            {
                str.push_back("Fizz");
            }
            else if( i % 5 == 0)
            {
                str.push_back("Buzz");
            }
            else
            {
                str.push_back(to_string(i));
            }
            
            
        }
        return str;
        
    }
};
// @lc code=end

int main(void)
{
    return 0;
}