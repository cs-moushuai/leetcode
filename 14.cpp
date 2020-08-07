#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		string result, temp = *(strs.cbegin());
		
		if (temp == "")
		{
			return temp;	
		}
			
		

		for (auto i = strs.cbegin() + 1; i != strs.cend(); i++)
		{
			result = "";
			//string CommonPrefix(string s1,string s2),CommonPrefix(temp, *i)
			for (string::size_type j = 0; j  != temp.size() && j  != i->size(); ++j)
			{
				if (temp[j] == (*i)[j])
				{
					result += temp[j];
				}
				else
				{
					break;
				}
			}

			temp = result;
		}

		return result;
	}
};

int main(void)
{

	Solution sy;
	vector<string> s = {"filx", "fila", "filb"};

	cout << sy.longestCommonPrefix(s) << endl;

	return 0;
}
