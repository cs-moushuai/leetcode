#include <iostream>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

class Solution
{
public:
    void Dfs(string &str, int i)
    {
        int num = 0;
        for(; i < (int)str.size(); i++)
        {
            int j = 0;
            if(str[i] <= '9' && str[i] >= '0')
            {

                num = str[i] - '0';
                for(; str[i + j + 1] <= '9' && str[i + j + 1] >= '0'; j++)
                {
                    num = num * 10 + str[i + j + 1] - '0';

                }
            }

            i += j;

            if(str[i] == ']')//检测到结束位置
            {
                int begin = my_stack.top();
                my_stack.pop();
                int count = my_stack.top();
                my_stack.pop();

                string in_str(str.begin() + begin + 1, str.begin() + i);

                int tmp = count;
                int count_of = 0;
                while(tmp)
                {
                    count_of++;
                    tmp /= 10;

                }
                str.erase(str.begin() + begin - count_of, str.begin() + i + 1);//3[string.....]全部删除
                for(int temp = count; temp > 0; temp--)
                {
                    str.insert(begin - count_of, in_str);
                }

                i = begin - count_of - 1 - 1;//begin为[的位置
                i += count * in_str.size();

            }

            if(str[i] == '[')
            {
                my_stack.push(num);//[]的次数
                my_stack.push(i);//[所在位置
                Dfs(str, i + 1);
            }

        }
    }

    string decodeString(string s)
    {

        string res(s);
        int num = 0;

        for(int i = 0; i < (int)res.size(); i++)
        {
            int j = 0;
            if(res[i] <= '9' && res[i] >= '0')
            {

                num = res[i] - '0';
                for(; res[i + j + 1] <= '9' && res[i + j + 1] >= '0'; j++)
                {
                    num = num * 10 + res[i + j + 1] - '0';

                }
            }

            i += j;


            if(res[i] == '[')
            {
                my_stack.push(num);//[]的次数
                my_stack.push(i);//[所在位置
                //cout << tmp << " " <<  i << endl;
                Dfs(res, i + 1);//[的下一个元素
                break;
            }
        }
        return res;

    }

private:
    stack<int> my_stack;

};

int main(void)
{
    Solution sy;
    cout << sy.decodeString("100[leetcode]") << endl;

    return 0;
}
