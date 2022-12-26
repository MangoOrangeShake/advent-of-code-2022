#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    const int number_of_pairs { 1000 };

    std::ifstream inf { "day4.txt" };
    std::vector<int> ranges;
    int buffer { 0 };
    int contain_counter { 0 };
    int overlap_counter { number_of_pairs };

    // Each "ranges" will have format: [lower1, upper1, lower2, upper2]
    //
    // Conditions where one range "fully contains" the other:
    // 1. (lower1 <= lower2) && (upper1 >= upper2)
    // 2. (lower1 >= lower2) && (upper1 <= upper2)

    if (!inf) {
        std::cerr << "Error opening day4.txt" << '\n';
        return 1;
    }

    while (inf >> buffer) {
        ranges.clear();
        ranges.push_back(abs(buffer));

        for (int i = 0; i < 3; i++) {
            inf >> buffer;
            if (inf.peek() == ',') {
                inf.ignore();
            }
            ranges.push_back(abs(buffer));
        }

        if ((ranges[0] <= ranges[2]) && (ranges[1] >= ranges[3])) {
            contain_counter++;
            continue;
        }

        if ((ranges[0] >= ranges[2]) && (ranges[1] <= ranges[3])) {
            contain_counter++;
            continue;
        }

        if ((ranges[1] < ranges[2]) || (ranges[0] > ranges[3])) {
            overlap_counter--;
            continue;
        }
    }

    std::cout << "The number of \"fully contained\" assignment pairs is: " << contain_counter << '\n';
    std::cout << "The number of overlapping assignment pairs is: " << overlap_counter << '\n';

    return 0;
}
