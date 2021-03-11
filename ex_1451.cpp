#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
public:
    string arrangeWords(string text)
    {
        istringstream in(text);
        vector<string> arr;
        string i;
        while (in >> i)
        {
            arr.emplace_back(i);
        }
        stable_sort(arr.begin(), arr.end(), [](const string & lhs, const string & rhs)
        {
            return lhs.size() < rhs.size();

        });
        text.clear();
        int counts = 0;
        for_each(arr.begin(), arr.end(), [&](string i)
        {
            if (counts++ == 0)
            {
                if (i[0] <= 'z' && i[0] >= 'a')
                    i[0] -= 32;
            }
            else
            {
                if (i[0] <= 'Z' && i[0] >= 'A')
                    i[0] += 32;
            }

            text += i + " ";
        });
        text.pop_back();
        //cout << text << endl;
        return text;

    }
};

int main(void)
{
    Solution obj;
    obj.arrangeWords("Keep calm and code on");

    return 0;
}
