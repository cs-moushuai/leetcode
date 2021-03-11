#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution2
{
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k)
    {
        if (board[i][j] != s[k])
        {
            return false;
        }
        else if (k == s.length() - 1)
        {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir : directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size())
            {
                if (!visited[newi][newj])
                {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag)
                    {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution
{
private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    int len;
    vector<vector<char>> board_;
    string word_;
    vector<vector<short>> visited;
    bool flag = false;
    void dfs(int k, int i, int j)
    {
        if (board_[i][j] != word_[k] || flag)
        {
            return;
        }
        else if (k == len - 1)
        {
            flag = true;
            return;
        }
        visited[i][j] = true;
        for (const auto &[c_i, c_j] : direction)
        {
            int tmp_i = i + c_i;
            int tmp_j = j + c_j;
            if (tmp_i >= 0 && tmp_i < m && tmp_j >= 0 && tmp_j < n && visited[tmp_i][tmp_j] == false)
            {
                dfs(k + 1, tmp_i, tmp_j);
            }
        }
        visited[i][j] = false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        board_ = board;
        word_ = word;
        m = board.size();
        n = board[0].size();
        len = word.size();
        visited.resize(m, vector<short>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(0, i, j);
                if (flag)
                    return true;
            }
        }
        return false;
    }
};

int main(void)
{
    vector<vector<char>> vec = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string s = "ABCCED";
    Solution sy;
    cout << sy.exist(vec, s) << endl;

    return 0;
}
