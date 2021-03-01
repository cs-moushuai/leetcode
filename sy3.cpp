#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string str = "abcdef";
    string pattern = "de";
    map<char, int> menu;
    for (auto i : str)
    {
        auto j = pattern.find(i);
        if (j != std::string::npos)
        {
            ++menu[i];
        }
    }
    for (auto i: menu)
    {
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}
