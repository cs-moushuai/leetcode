#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &lhs, const vector<int> &rhs)
        {
            return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        list<vector<int>> res;
        for (const auto &i : people)
        {
            if (res.size() <= i[1])
                res.emplace_back(i);
            else
            {
                int pos = i[1];
                auto it = res.begin();
                while(pos--)
                    ++it;
                res.insert(it, i);
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};


class Solution2
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &lhs, const vector<int> &rhs)
        {
            return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        vector<vector<int>> res;
        for (const auto &i : people)
        {
            if (res.size() <= i[1])
                res.emplace_back(i);
            else
                res.insert(res.begin() + i[1], i);
        }
        return res;
    }
};

int main(void)
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution sy;
    auto res = sy.reconstructQueue(people);
    for (auto &i : res)
    {
        cout << i[0] << "," << i[1] << " ";
    }
    cout << endl;

    return 0;
}
