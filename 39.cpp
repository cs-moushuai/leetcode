#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    vector<int> tmp;
    combinationSumCore(res, candidates, target, tmp, 0, 0);
    return res;
  }

  void combinationSumCore(vector<vector<int>> &res, vector<int> &candidates, int target, vector<int> &tmp, int sum, int begin)
  {
    if (sum == target)
    {
      res.push_back(tmp);
    }
    else
    {
      for (int i = begin; i < candidates.size(); ++i)
      {
        if (sum + candidates[i] <= target)
        {
          tmp.push_back(candidates[i]);
          combinationSumCore(res, candidates, target, tmp, sum + candidates[i], i);
          tmp.pop_back();
        }
      }
    }
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
