#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> visited;
    const int dir_i[4] = {-1, 1, 0, 0};
    const int dir_j[4] = {0, 0, -1, 1};
    int row;
    int col;
public:
    void Bfs(vector<vector<char>>& grid, int i, int j)
    {
        queue<vector<int>> que;
        que.push({i, j});
        visited[i][j] = 1;
        while (!que.empty())
        {
            vector<int> obj = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i)
            {
                int tmp_i = obj[0] + dir_i[i];
                int tmp_j = obj[1] + dir_j[i];
                if (tmp_i >= 0 && tmp_i < row && tmp_j >= 0 && tmp_j < col)
                {
                    if (grid[tmp_i][tmp_j] == '1' && visited[tmp_i][tmp_j] == 0)
                    {
                        que.push({tmp_i, tmp_j});
                        visited[tmp_i][tmp_j] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        row = grid.size();
        col = grid[0].size();
        visited.resize(row, vector<int>(col, 0));
        int cnt = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    Bfs(grid, i, j);
                    ++cnt;
                }
            }

        }

        return cnt;
    }
};

class Solution2
{
private:
    vector<vector<int>> visited;
    const int dir_i[4] = {-1, 1, 0, 0};
    const int dir_j[4] = {0, 0, -1, 1};
    int row;
    int col;
public:
    void Dfs(vector<vector<char>>& grid, int i, int j)
    {
        visited[i][j] = 1;
        for (int k = 0; k < 4; ++k)
        {
            int tmp_i = i + dir_i[k];
            int tmp_j = j + dir_j[k];
            if (tmp_i >= 0 && tmp_i < row && tmp_j >= 0 && tmp_j < col)
            {
                if (grid[tmp_i][tmp_j] == '1' && visited[tmp_i][tmp_j] == 0)
                {
                    Dfs(grid, tmp_i, tmp_j);
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid)
    {
        row = grid.size();
        col = grid[0].size();
        visited.resize(row, vector<int>(col, 0));
        int cnt = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    Dfs(grid, i, j);
                    ++cnt;
                }
            }

        }

        return cnt;
    }
};

int main(void)
{

    return 0;
}
