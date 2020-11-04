#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> pondSizes(vector<vector<int>>& land)
    {
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[0].size(); j++)
            {
                if(land[i][j] == 0)
                {
                    size_.push_back(Dfs(land, i, j));

                }
            }
        }

        sort(size_.begin(), size_.end());
        return size_;
    }
    int Dfs(vector<vector<int>> &land, int i, int j)
    {
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size())
        {
            return 0;
        }
        if(land[i][j] != 0)
        {
            return 0;
        }
        land[i][j] = 1;
        int size = 1;
        for(auto &d : directions_)
        {
            size += Dfs(land, i + d[0], j + d[1]);
        }
        return size;

    }

private:
    const vector<vector<int>> directions_ = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    vector<int> size_;

};

int main(void)
{
    Solution sy;
    vector<vector<int>> land = {{0, 2, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {0, 1, 0, 1}};

    auto res = sy.pondSizes(land);

    for(auto i : res)
    {
        cout << i << endl;
    }


    return 0;
}
