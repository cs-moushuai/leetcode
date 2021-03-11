#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int binaryGap(int N)
    {
        string N_str;
        while(N != 0)
        {
            N_str.push_back(N % 2 + '0');
            N /= 2;
        }

        reverse(N_str.begin(), N_str.end());

        int max = 0;
        string::const_iterator temp;
        for(auto i = N_str.cbegin(); i != N_str.cend();)
        {
            temp = i;
            i = find(i + 1, N_str.cend(), '1');
            if(i != N_str.cend() && i - temp > max)
            {
                max = i - temp;
            }

        }

        return max;

    }
};

int main(void)
{
    Solution sy;
    cout << sy.binaryGap(22) << endl;

    return 0;
}
