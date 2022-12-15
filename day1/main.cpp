#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream inf { "input.txt" };

    if (!inf) {
        std::cerr << "error: could not be opened\n";
        return 1;
    }

    std::vector<int> array_store;
    std::vector<int> sum_vec;

    while (inf) {
        std::string str_input;
        std::getline(inf, str_input);

        if (str_input.empty()) {
            int sum { 0 };

            for (int food_item : array_store) {
                sum += food_item;
            }

            sum_vec.push_back(sum);
            array_store.clear();

        } else {

            int parsed_calorie { std::stoi(str_input) };
            array_store.push_back(parsed_calorie);
        }
    }

    std::sort(sum_vec.begin(), sum_vec.end());

    std::cout << "The top 3 calories are: \n";
    std::cout << sum_vec[sum_vec.size() - 1] << '\n';
    std::cout << sum_vec[sum_vec.size() - 2] << '\n';
    std::cout << sum_vec[sum_vec.size() - 3] << '\n';

    std::cout << "...and the sum of all 3 is: "
              << sum_vec[sum_vec.size() - 1] + sum_vec[sum_vec.size() - 2] +
                     sum_vec[sum_vec.size() - 3]
              << '\n';

    return 0;
}
