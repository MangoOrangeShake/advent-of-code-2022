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
    char payload_buffer { 0 };
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

        // Procedural pop back and push back from stack 1 to stack 2
        for (int i = 0; i < amount; i++) {
            payload_buffer = map_of_stacks[extract_stack].back();
            map_of_stacks[extract_stack].pop_back();
            map_of_stacks[insert_stack].push_back(payload_buffer);
        }
    }

    for (int i = 1; i < 10; i++) {
        std::cout << map_of_stacks[i].back() << '\n';
    }

    return 0;
}
