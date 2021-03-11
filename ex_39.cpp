#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    void combinationSumCore(vector<int> &candidates, int target, vector<int> &tmp, int sum, int begin)
    {
        if (sum == target)
        {
            res.push_back(tmp);
        }
        else
        {
            int len = candidates.size();
            for (int i = begin; i < len; ++i)
            {
                if (sum + candidates[i] <= target)
                {
                    tmp.push_back(candidates[i]);
                    combinationSumCore(candidates, target, tmp, sum + candidates[i], i);
                    tmp.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> tmp;
        combinationSumCore(candidates, target, tmp, 0, 0);
        return res;
    }

};

int main(void)
{
    Solution sy;
    vector<int> input = {2, 3, 6, 7};
    vector<vector<int>> result = sy.combinationSum(input, 7);

    ostream_iterator<int> os(cout, " ");

    for (auto &i : result)
    {
        copy(i.cbegin(), i.cend(), os);
        cout << endl;
    }
    return 0;
}
