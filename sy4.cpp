#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    map<int, int> menu;
    menu[9] += 3;
    menu[3] += 5;
    menu[21] += 33;
    for (auto i: menu)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
