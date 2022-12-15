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

    std::string line1;
    std::string line2;
    std::string line3;
    std::vector<char> dup_buffer;

    std::ifstream inf { "day3.txt" };

    if (!inf) {
        std::cerr << "Could not open day3.txt" << '\n';
        return 1;
    }

    while (std::getline(inf, line1)) {
        std::getline(inf, line2);
        std::getline(inf, line3);

        for (char in_first : line1) {
            for (char in_second : line2) {
                if (in_first == in_second) {
                    dup_buffer.push_back(in_first);
                }
            }
        }

        for (char in_third : line3) {
            for (char in_buffer : dup_buffer) {
                if (in_third == in_buffer) {
                    sum_of_duplicates += Convert2Priority(in_third);
                    dup_buffer.clear();
                    goto end;
                }
            }
        }
    end:;
    }

    std::cout << "The priorities add up to: " << sum_of_duplicates << '\n';
    return 0;
}
