#include <fstream>
#include <iostream>
#include <typeinfo>
#include <vector>

int Convert2Priority(char letter)
{
    const int lowercase_ascii { 96 };
    const int uppercase_ascii { 64 };
    const int uppercase_score { 26 };

    if (letter > lowercase_ascii)
        return letter - lowercase_ascii;

    return letter - uppercase_ascii + uppercase_score;
}

int main()
{
    int sum_of_duplicates { 0 };
    std::string line;

    std::ifstream inf { "day3.txt" };

    if (!inf) {
        std::cerr << "Could not open day3.txt" << '\n';
        return 1;
    }

    while (std::getline(inf, line)) {

        std::string first_half { line.substr(0, line.size() / 2) };
        std::string second_half { line.substr(line.size() / 2, line.size()) };

        for (char in_first : first_half) {
            for (char in_second : second_half) {
                if (in_first == in_second) {
                    sum_of_duplicates += Convert2Priority(in_first);
                    goto end;
                }
            }
        }
    end:;
    }

    std::cout << "The priorities add up to: " << sum_of_duplicates << '\n';
    return 0;
}
