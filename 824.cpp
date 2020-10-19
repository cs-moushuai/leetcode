#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string toGoatLatin(string S)
    {
        istringstream input(S);
        ostringstream output;
        auto PlusA = [&output](int i)
        {
            for(; i > 0; i--)
            {
                output << 'a';
            }
        };

        string i;
        input >> i;
        for(size_t count = 1; ; count++)
        {
            if(i[0] == 'a' || i[0] == 'e' || i[0] == 'i' || i[0] == 'o' || i[0] == 'u' ||
                    i[0] == 'A' || i[0] == 'E' || i[0] == 'I' || i[0] == 'O' || i[0] == 'U'    )
            {
                output << i + "ma";
            }
            else
            {
                i.push_back(i[0]);
                i.erase(i.begin());
                output << i + "ma";
            }
            PlusA(count);
            if(input >> i)
            {
                output << " ";
            }
            else
            {
                break;
            }
        }
        return output.str();

    }
};

class Solution2
{
public:
    string toGoatLatin(string S)
    {
        istringstream input(S);
        ostringstream output;
        auto PlusA = [&output](int i)
        {
            for(; i > 0; i--)
            {
                output << 'a';
            }
        };

        string i;
        for(size_t count = 1; input >> i ; count++)
        {
            if(i[0] == 'a' || i[0] == 'e' || i[0] == 'i' || i[0] == 'o' || i[0] == 'u' ||
                    i[0] == 'A' || i[0] == 'E' || i[0] == 'I' || i[0] == 'O' || i[0] == 'U'    )
            {
                output << i + "ma";
            }
            else
            {
                i.push_back(i[0]);
                i.erase(i.begin());
                output << i + "ma";
            }
            PlusA(count);
            output << " ";
        }
        string result = output.str();
        return string(result.begin(), result.end() - 1);

    }
};

int main(void)
{
    Solution sy;
    cout << sy.toGoatLatin("I speak Goat Latin") << endl;

    return 0;
}
