#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, int> m = {{'(', 1}, {'[', 2}, {'{', 3}, {')', 4}, {']', 5}, {'}', 6}};
        stack<int> mystack;

        bool istrue = true;
        int flag = 0;
        for(char i: s)
        {
            flag = m[i];
            if (1<=flag && flag<=3)
            {
                mystack.push(flag);
            }
            else if(!mystack.empty() && mystack.top() == flag - 3 )
            {
                mystack.pop();
            }
            else
            {
                istrue = false;
                break;
            }
            
        }

        if (!mystack.empty())
        {
            istrue = false;
        }
        return istrue;
        
    }
};

int main(void)
{
    Solution sy;
    cout<<sy.isValid("({{]})")<<endl;
    return 0;
}