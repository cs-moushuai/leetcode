#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int y, int x)
    {
        char cnt = '0';
        for(auto i : direction)
        {
            int new_y = y + i[0];
            int new_x = x + i[1];

            if(new_y < 0 || new_y >= (int)board.size() || new_x < 0 || new_x >= (int)board[0].size())
            {
                continue;
            }
            else if(board[new_y][new_x] == 'M')
            {
                cnt++;
            }
        }

        if(cnt == '0')
        {
            board[y][x] = 'B';
            for(auto i : direction)
            {
                int new_y = y + i[0];
                int new_x = x + i[1];
                if(new_y < 0 || new_y >= (int)board.size() || new_x < 0 || new_x >= (int)board[0].size() || board[new_y][new_x] != 'E')
                {
                    continue;
                }
                dfs(board, new_y, new_x);
            }
        }
        else
        {
            board[y][x] = cnt;
        }

    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        vector<vector<char>> res = board;
        int y = click.at(0);
        int x = click.at(1);
        if(board[y][x] == 'M')
        {
            res[y][x] = 'X';
        }
        else
        {
            dfs(res, y, x);
        }

        return res;
    }

private:
    vector<vector<int>> direction = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};//y and x

};

int main(void)
{
    vector<vector<char>> input = {{'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}
    };


    vector<int> click = {3, 0};
    Solution sy;
    auto res = sy.updateBoard(input, click);
    for(auto i: res)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}
