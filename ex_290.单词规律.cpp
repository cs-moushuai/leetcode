#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> menu;
        unordered_map<string, char> rmenu;

        stringstream ss(str);
        string s;
        for (auto c : pattern)
        {
            if (!(ss >> s) || (menu.count(c) == 1 && s != menu[c]) || (rmenu.count(s) == 1 && c != rmenu[s]))
            {
                return false;
            }
            menu[c] = s;
            rmenu[s] = c;
        }

        return ss >> s ? false : true;
    }
};
class Solution2
{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char, string> menu;

        auto str_next_func = [&str](string::iterator &i) -> string {
            string word;
            while (i != str.end())
            {
                if (*i == ' ')
                {
                    i++;
                    break;
                }
                word += *i;
                i++;
            }
            return word;
        };

        auto char_i = pattern.begin();
        auto str_i = str.begin();
        pair<unordered_map<char, string>::iterator, bool> judge;
        for (; char_i != pattern.end() && str_i != str.end(); char_i++)
        {
            auto word = str_next_func(str_i);
            judge = menu.insert(pair<char, string>(*char_i, word));

            if (judge.second == false && word != menu[*char_i])
            {
                return false;
            }
        }

        if (char_i != pattern.end() || str_i != str.end())
        {
            return false;
        }

        //*****************************

        unordered_map<string, char> menu2;
        char_i = pattern.begin();
        str_i = str.begin();
        pair<unordered_map<string, char>::iterator, bool> judge2;
        for (; char_i != pattern.end() && str_i != str.end(); char_i++)
        {
            auto word = str_next_func(str_i);
            judge2 = menu2.insert(pair<string, char>(word, *char_i));

            if (judge2.second == false && *char_i != menu2[word])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

int main(void)
{
    Solution sy;

    cout << sy.wordPattern("abba", "dog dog dog dog") << endl;
    return 0;
}