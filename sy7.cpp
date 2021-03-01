#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main(void)
{
    unordered_map<int, int> sy1, sy2;
    sy1[0] = 1;
    //sy1.erase(0);
    //sy2[0] = 1;
    cout << bool(sy1 == sy2) << endl;

    return 0;
}
