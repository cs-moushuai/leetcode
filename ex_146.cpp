#include <bits/stdc++.h>
#include <climits>
#include <utility>
#include <vector>

using namespace std;

struct Item
{
    int key;
    int value;
    int visited;
    Item(): key(0), value(0), visited(INT_MAX) {}
};


class LRUCache
{
private:
    vector<Item> cache;
    int capacity_;
    int curr;
    int visited;
    int findMin()
    {
        int min_val = 0;
        for (int i = 1; i < curr; ++i)
        {
            if (cache[i].visited < cache[min_val].visited)
            {
                min_val = i;
            }
        }
        return min_val;
    }
public:
    LRUCache(int capacity): cache(capacity), capacity_(capacity), curr(0), visited(1)
    {
    }

    int get(int key)
    {
        for (int i = 0; i < curr; ++i)
        {
            if (cache[i].key == key)
            {
                cache[i].visited = visited++;
                return cache[i].value;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        for (int i = 0; i < curr; ++i)
        {
            if (cache[i].key == key)
            {
                cache[i].value = value;
                cache[i].visited = visited++;
                return;
            }
        }
        if (capacity_ == curr)
        {
            //delete least recently unit and insert in proper position
            auto res = findMin();
            cache[res].key = key;
            cache[res].value = value;
            cache[res].visited = visited++;

        }
        else
        {
            cache[curr].key = key;
            cache[curr].value = value;

            cache[curr].visited = visited++;
            ++curr;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(void)
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // 返回 1
    cout << lRUCache.get(3) << endl;    // 返回 1
    cout << lRUCache.get(4) << endl;    // 返回 1


    return 0;
}
