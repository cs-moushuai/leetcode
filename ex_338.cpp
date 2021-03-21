#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    int countOne(int x)
    {
        int counts = 0;

        while (x > 0)
        {
            x &= x - 1;
            ++counts;
        }
        return counts;
    }

public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i)
        {
            res[i] = countOne(i);
        }
        return res;
    }
};

int main(void)
{

    return 0;
}
