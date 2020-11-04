#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int Dfs(vector<vector<int>> &land, int x, int y)
    {

        //for(int i = 0; i != 8; i++)
        //{
        //int new_x = x + movex_[i];
        //int new_y = y + movey_[i];

        //if(new_x >= 0 && new_x < (int)land[0].size() &&
        //new_y >= 0 && new_y < (int)land.size())
        //{
        //land[new_y][new_x] = 1;
        //Dfs(land, new_x, new_y, size + 1);
        //flag = true;
        //}
        //else
        //{
        //if(flag == false)
        //{
        //size_.push_back(size);

        //}
        //}

        //}
        if(x < 0 || x >= static_cast<int>(land[0].size()) || y < 0 || y >= static_cast<int>(land.size()))
        {
            return 0;
        }
        if(land[y][x] != 0)
        {
            return 0;
        }

        int size = 1;
        land[y][x] = 1;
        for(auto &i : directions_)
        {
            size += Dfs(land, x + i[0], y + i[1]);
        }

        return size;

    }
    vector<int> pondSizes(vector<vector<int>>& land)
    {
        for(int i = 0; i < static_cast<int>(land.size()); i++)
        {
            for(int j = 0; j < static_cast<int>(land[0].size()); j++)
            {
                if(land[i][j] == 0)
                {
                    int size = Dfs(land, j, i);
                    size_.push_back(size);
                }
            }
        }
        sort(size_.begin(), size_.end());

        return size_;
    }

private:
    //const vector<int> movex_ = {0, 0, -1, 1, -1, 1, -1, 1};//up,down,left,right,up and left,up and right,down and left,down and right
    //const vector<int> movey_ = {-1, 1, 0, 0, -1, -1, 1, 1};
    const vector<vector<int>> directions_ = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
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
