#include <algorithm>
#include <bits/stdc++.h>
#include <sys/ucontext.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        int len = T.size();

        vector<int> res(len, 0);
        stack<int> my_stack;
        for (int i = 0; i < len; ++i)
        {
            while (!my_stack.empty() && T[i] > T[my_stack.top()])
            {
                int record = my_stack.top();
                my_stack.pop();

                res[record] = i - record;

            }
            my_stack.push(i);

        }
        return res;
    }
};

int main(void)
{

    return 0;
}
