#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        istringstream input(text);
        vector<string> result;
        vector<string> v_string;

        string i;
        while(input >> i)
        {
            v_string.push_back(i);
        }
        for(int j = 0; j < (int)v_string.size() - 2; j++)
        {
            if(v_string[j] == first && v_string[j + 1] == second)
            {
                result.push_back(v_string[j + 2]);

            }
        }
        return result;

    }
};

int main(void)
{
    Solution sy;
    auto v = sy.findOcurrences("alice is a good girl she is a good student", "a", "good");
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
