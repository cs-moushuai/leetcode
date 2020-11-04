#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class MyHashSet
{
public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        vec = vector<list<int>>(kN);
    }

    void add(int key)
    {
        vec[key % kN].push_back(key);

    }

    void remove(int key)
    {
        vec[key % kN].remove(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        if(vec[key%kN].cend() != find(vec[key % kN].cbegin(), vec[key % kN].cend(), key))
        {
            return true;
        }

        return false;

    }
private:
    vector<list<int>> vec;
    const int kN = 100;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(void)
{

    return 0;
}
