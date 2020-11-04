#include <iostream>
#include <vector>

using namespace std;

constexpr int kSize = 1000;

class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        vec_.assign(kSize, new Node());
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int hash_value = key % kSize;
        Node *tmp = vec_[hash_value];
        Node *end = tmp;

        while(tmp != nullptr)
        {
            if(tmp->key == key)
            {
                tmp->val = value;
                return;
            }

            end = tmp;
            tmp = tmp->next;
        }

        end->next = new Node(key, value);

    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int hash_value = key % kSize;
        Node *tmp = vec_[hash_value];

        while(tmp != nullptr)
        {
            if(tmp->key == key)
            {
                return tmp->val;
            }

            tmp = tmp->next;
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int hash_value = key % kSize;
        Node *tmp = vec_[hash_value];
        Node *end = tmp;

        while(tmp != nullptr)
        {
            if(tmp->key == key)
            {
                Node *temp = tmp;
                end->next = tmp->next;
                delete temp;
                
                return;
            }
            end = tmp;
            tmp = tmp->next;
        }

    }
private:
    struct Node
    {
        int key;
        int val;

        Node *next;

        Node(int key_ = -1, int val_ = -1): key(key_), val(val_), next(nullptr) {}
    };
    vector<Node *> vec_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(void)
{

    return 0;
}
