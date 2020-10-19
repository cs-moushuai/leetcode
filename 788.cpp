#include <iostream>

using namespace std;

class Solution
{
public:
    int rotatedDigits(int N)
    {
        auto Judge = [](int i)->bool
        {
            bool flag = false;
            while(i != 0)
            {
                int num = i % 10;
                if(num == 3 || num == 7 || num == 4)
                {
                    return false;
                }
                if(num == 2 || num == 6 || num == 9 || num == 5)
                {
                    flag = true;
                }
                i /= 10;
            }

            return flag;
        };
        int count = 0;

        for(int i = 1; i <= N; i++)
        {
            if(Judge(i))
            {
                count++;
            }
        }

        return count;

    }
};

int main(void)
{

    return 0;
}
