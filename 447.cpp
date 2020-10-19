#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>>& points)
    {
        int counts = 0;
        int comparison1 = 0, comparison2 = 0;

        for(int i = 0; i < points.size(); i++)
        {
            //num.push_back(num[i]);

            for(int j = 0, flag = 0; j < points.size(); j++)
            {
                if( j == i )
                {
                    continue;
                }
                if(flag == 0)
                {

                    comparison1 = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                    flag++;
                }
                else
                {
                    comparison2 = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                }
                //num.push_back(num[j]);

            }
            if(comparison1 == comparison2)
            {
                counts += 2;
            }

        }

        return counts;

    }
};

int main(void)
{
    Solution sy;
    vector<vector<int>> nums = {{0, 0}, {1, 0}, {2, 0}};
    cout << sy.numberOfBoomerangs(nums) << endl;

    return 0;
}
