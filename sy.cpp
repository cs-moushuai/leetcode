#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <ios>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> nums{1, 4, 7, 11, 15};
    auto i = lower_bound(nums.begin(), nums.end(), 7);
    cout << *i << ": " << i - nums.begin() << endl;
    nums.insert(i, 3);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    bitset<bool> v{true, false};
    auto val = v[0];
    val = false;
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}
