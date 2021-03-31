#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> land(n, 1);
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                //land[j] = land[j] + land[j - 1];
                land[j] += land[j - 1];
            }
        }
        return land[n - 1];
    }
};

int main(void)
{

    return 0;
}
