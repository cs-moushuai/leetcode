#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret(1, 0);
        for(int m = 0; m < n; m++)
        {
            for(int i = ret.size() - 1 ; i >= 0; i--)
            {
                ret.push_back(ret[i] + (1 << m));
            }
        }

        return ret;

    }
};

int main(void)
{
    Solution sy;
    auto v = sy.grayCode(2);
    for_each(v.begin(), v.end(), [](int i)
    {
        cout << i << " ";
    });
    cout<<endl;

    return 0;
}
