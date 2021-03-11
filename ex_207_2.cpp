#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> indeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &i : prerequisites)
        {
            edges[i[1]].emplace_back(i[0]);
            ++indeg[i[0]];
        }
        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indeg[i] == 0)
            {
                que.push(i);
            }
        }
        int visited = 0;
        while (!que.empty())
        {
            ++visited;
            auto i = que.front();
            que.pop();
            for (auto j : edges[i])
            {
                --indeg[j];
                if (indeg[j] == 0)
                    que.push(j);
            }
        }

        return visited == numCourses;
    }
};

int main(void)
{

    return 0;
}
