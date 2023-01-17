#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{

    std::map<int, std::vector<char>> map_of_stacks;
    map_of_stacks[1] = { 'P', 'F', 'M', 'Q', 'W', 'G', 'R', 'T' };
    map_of_stacks[2] = { 'H', 'F', 'R' };
    map_of_stacks[3] = { 'P', 'Z', 'R', 'V', 'G', 'H', 'S', 'D' };
    map_of_stacks[4] = { 'Q', 'H', 'P', 'B', 'F', 'W', 'G' };
    map_of_stacks[5] = { 'P', 'S', 'M', 'J', 'H' };
    map_of_stacks[6] = { 'M', 'Z', 'T', 'H', 'S', 'R', 'P', 'L' };
    map_of_stacks[7] = { 'P', 'T', 'H', 'N', 'M', 'L' };
    map_of_stacks[8] = { 'F', 'D', 'Q', 'R' };
    map_of_stacks[9] = { 'D', 'S', 'C', 'N', 'L', 'P', 'H' };

    std::ifstream inf { "day5.txt" };
    std::vector<char> payload_buffer;
    std::string file_buffer;
    const int skiplines { 10 };
    int amount { 0 };
    int extract_stack { 0 };
    int insert_stack { 0 };

    // Skip first 10 lines
    for (int i = 0; i < skiplines; i++) {
        std::getline(inf, file_buffer);
    }

    while (std::getline(inf, file_buffer, 'e')) {
        inf >> amount;
        std::getline(inf, file_buffer, 'm');
        inf >> extract_stack;
        std::getline(inf, file_buffer, 'o');
        inf >> insert_stack;
        std::getline(inf, file_buffer, '\n');

        // Slice and copy from stack 1
        payload_buffer = std::vector<char>(
            map_of_stacks[extract_stack].end() - amount,
            map_of_stacks[extract_stack].end()
        );

        // Erase copied elements from stack 1
        map_of_stacks[extract_stack].erase(
            map_of_stacks[extract_stack].end() - amount,
            map_of_stacks[extract_stack].end()
        );

        // Place copied elements on top of stack 2
        map_of_stacks[insert_stack].insert(
            map_of_stacks[insert_stack].end(), payload_buffer.begin(),
            payload_buffer.end()
        );
    }

    for (auto const& [key, val] : map_of_stacks) {
        std::cout << "Stack " << key << ": ";
        for (char crate : val) {
            std::cout << crate << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
