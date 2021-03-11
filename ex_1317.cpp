#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution2
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int tmp1 =  0, tmp2 = 0;
        vector<int> result;
        bool flag = true;

        for(int head = 1, tail = n - 1; ; head++, tail--)
        {
            tmp1 = head;
            tmp2 = tail;
            flag = true;
            do
            {
                if((tmp1 != 0 && tmp1 % 10 == 0) || (tmp2 != 0 && tmp2 % 10 == 0))
                {
                    flag = false;
                    break;
                }
                tmp1 /= 10;
                tmp2 /= 10;
            }
            while(tmp1 != 0 || tmp2 != 0);
            if(flag)
            {
                result.push_back(head);
                result.push_back(tail);
                break;
            }
        }
        return result;

    }
};

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for(int i = 1, j = n - 1; i < n; i++, j-- )
        {
            if((to_string(i) + to_string(j)).find('0') == string::npos)
            {
                return {i, j};
            }
        }
        return {};

    }
};


int main(void)
{
    Solution sy;
    vector<int> v = sy.getNoZeroIntegers(11);
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
