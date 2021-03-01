#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(void)
{
    vector<pair<int, int>> vec{{1, 2}, {3, 4}, {5, 6}};
    for (auto& [num, size] : vec)
    {
        cout << num << ", " << size << endl;
    }

    return 0;
}
