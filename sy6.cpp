#include <iostream>
#include <string>
#include <cstddef>

int main ()
{
    std::string str ("It replaces the vowels in this sentence by asterisks.");
    std::size_t found = str.find_first_of("aeiou");
    while (found != std::string::npos)
    {
        str[found] = '*';
        found = str.find_first_of("aeiou", found + 1);
    }

    std::cout << str << '\n';

    return 0;
}
