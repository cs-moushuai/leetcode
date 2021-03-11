#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int>& cuts)
    {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(m+2, vector<int>(m+2));
        for (int i = m; i >= 1; --i) {
            
        }



    }
};

int main(void)
{

    return 0;
}
