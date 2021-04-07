#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        int nvars = 0;
        unordered_map<string, int> variables;

        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
            {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end())
            {
                variables[equations[i][1]] = nvars++;
            }
        }

        // 对于每个点，存储其直接连接到的所有点及对应的权值
        vector<vector<pair<int, double>>> edges(nvars);
        for (int i = 0; i < n; i++)
        {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back(make_pair(vb, values[i]));
            edges[vb].push_back(make_pair(va, 1.0 / values[i]));
        }

        vector<double> ret;
        for (const auto& q : queries)
        {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end())
            {
                int ia = variables[q[0]], ib = variables[q[1]];
                if (ia == ib)
                {
                    result = 1.0;
                }
                else
                {
                    queue<int> points;
                    points.push(ia);
                    vector<double> ratios(nvars, -1.0);
                    ratios[ia] = 1.0;

                    while (!points.empty() && ratios[ib] < 0)
                    {
                        int x = points.front();
                        points.pop();

                        for (const auto [y, val] : edges[x])
                        {
                            if (ratios[y] < 0)
                            {
                                ratios[y] = ratios[x] * val;
                                points.push(y);
                            }
                        }
                    }
                    result = ratios[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};


//struct Edge
//{
//string v;
//double weight;
//Edge(string &v_, double weight_): v(v_), weight(weight_) {}
//};

//class Graph
//{
//private:
//unordered_map<string, set<Edge>> graph;
//public:
//void AddEdge(string &u, string &v, double weight)
//{
//for (auto &i : graph[u])
//{
//graph[i.v].emplace(Edge(v, i.weight / weight));
//graph[v].emplace(Edge(i.v, i.weight * weight));
//}
//graph[u].emplace(Edge{v, weight});
//for (auto &i : graph[v])
//{
//graph[i.v].emplace(Edge{u, i.weight / weight});
//graph[u].emplace(Edge(i.v, i.weight * weight));
//}
//graph[v].emplace(Edge{u, 1 / weight});
//}

//double Find(string &u, string &v)
//{
//for (auto &i : graph[u])
//{
//if (i.v == v)
//return i.weight;
//}
//return -1;
//}
//void Print()
//{
//for (auto &i : graph)
//{
//cout << i.first << ": " << endl;
//for (auto &j : i.second)
//{
//cout << j.v << "," << j.weight << endl;
//}
//}
//}

//};

//class Solution
//{
//private:
//Graph graph;
//public:
//vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
//{
//int len = equations.size();
//for (int i = 0; i < len; ++i)
//{
//graph.AddEdge(equations[i][0], equations[i][1], values[i]);
//}
//graph.Print();

//return {0.0};
//}
//};

int main(void)
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    Solution sy;
    auto res = sy.calcEquation(equations, values, queries);
    return 0;
}
