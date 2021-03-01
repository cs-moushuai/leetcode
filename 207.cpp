#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:

    void Dfs(int i)
    {
        visited[i] = 1;
        for (auto j : edges[i])
        {
            if (visited[j] == 0)
            {
                Dfs(j);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[j] == 1)
            {
                valid = false;
                return;
            }
        }
        visited[i] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        visited.resize(numCourses);
        edges.resize(numCourses);
        for (const auto &i : prerequisites)
        {
            edges[i[1]].emplace_back(i[0]);
        }

        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
            {
                Dfs(i);
            }
        }

        return valid;
    }
};

int main(void)
{

    return 0;
}
