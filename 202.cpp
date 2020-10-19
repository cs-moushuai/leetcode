#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> set_num;

        while(n != 1)
        {
            int sum = 0;
            int r = 0;

            auto judge = set_num.insert(n);

            if(judge.second == false)
            {
                return false;
            }
            while(n)
            {
                r = n % 10;
                sum += r * r;
                n /= 10;
            }

            n = sum;


        }

        return true;

    }
};

int main(void)
{

    return 0;
}
