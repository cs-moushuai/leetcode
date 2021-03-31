#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

struct item
{
    int key;
    int value;
    int visited;
    item(): key(0), value(0), visited(0) {}
};


class LRUCache
{
private:
    vector<item> cache;
    int capacity_;
    int curr;
    int visited;
    deque<int> que;
    void update(int pos)
    {
        que.push_back(pos);
    }
    int pop_que()
    {
        int tmp = que.front();
        auto res = find(que.begin() + 1, que.end(), tmp);
        if (res == que.end())
        {
            que.pop_front();
            return tmp;
        }
        else
        {
            que.pop_front();
            return pop_que();
        }
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
                que.push_back(i);
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
                que.push_back(i);
                return;
            }
        }
        if (capacity_ == curr)
        {
            //delete least recently unit and insert in proper position
            int pos = pop_que();
            cache[pos].key = key;
            cache[pos].value = value;
            que.push_back(pos);

        }
        else
        {
            cache[curr].key = key;
            cache[curr].value = value;

            que.push_back(curr);
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
