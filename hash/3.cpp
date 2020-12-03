#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        return set<int>(nums.cbegin(), nums.cend()).size() != nums.size();

    }
};
//class Solution
//{
//public:
//bool containsDuplicate(vector<int>& nums)
//{
//unordered_set<int> menu;

//for(auto i: nums)
//{
//if(menu.count(i) == 1)
//{
//return true;
//}
//menu.insert(i);
//}

//return false;

//}
//};

int main(void)
{

    return 0;
}
