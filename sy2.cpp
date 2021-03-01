#include <bitset>
#include <iostream>

using namespace std;

int main(void)
{
    int v = 23;
    bitset<10> arr(v);
    cout << arr << endl;
    arr[0] = 0;
    cout << arr << endl;

    return 0;
}
