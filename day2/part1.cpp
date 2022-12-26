#include <fstream>
#include <iostream>

auto ConvertRps(char file_input) -> char
{
    if (file_input == 'A' || file_input == 'X')
        return 'R';
    if (file_input == 'B' || file_input == 'Y')
        return 'P';
    if (file_input == 'C' || file_input == 'Z')
        return 'S';

    return ' ';
};

auto ChoiceScore(char my_move) -> int
{

    const int unknown { -10000 };

    if (my_move == 'R')
        return 1;
    if (my_move == 'P')
        return 2;
    if (my_move == 'S')
        return 3;

    return unknown;
}

auto ResultScore(char my_move, char enemy_move) -> int
{
    const int win { 6 };
    const int draw { 3 };
    const int loss { 0 };
    const int unknown { -10000 };

    if (my_move == enemy_move)
        return draw;
    if (my_move == 'R' && enemy_move == 'P')
        return loss;
    if (my_move == 'R' && enemy_move == 'S')
        return win;
    if (my_move == 'P' && enemy_move == 'R')
        return win;
    if (my_move == 'P' && enemy_move == 'S')
        return loss;
    if (my_move == 'S' && enemy_move == 'R')
        return loss;
    if (my_move == 'S' && enemy_move == 'P')
        return win;

    return unknown;
}

auto main() -> int
{
    int score { 0 };
    char enemy_move { 0 };
    char my_move { 0 };

    // Read encrypted file then write separate file with correct RPS
    std::ifstream inf { "day2.txt" };

    if (!inf) {
        std::cerr << "error: day2.txt could not be opened\n";
        return 1;
    }

    std::ofstream outf { "decrypted.txt" };

    if (!outf) {
        std::cerr << "error: decrypted.txt could not be opened\n";
        return 1;
    }

    while (inf >> enemy_move >> my_move) {

        outf << ConvertRps(enemy_move) << ' ' << ConvertRps(my_move) << '\n';
    }

    outf.flush();

    // Scoring
    std::ifstream inf2 { "decrypted.txt" };

    if (!inf2) {
        std::cerr << "error: decrypted.txt could not be opened\n";
        return 1;
    }

    while (inf2 >> enemy_move >> my_move) {
        score += ChoiceScore(my_move);
        score += ResultScore(my_move, enemy_move);
    }

    std::cout << "The total score is: " << score << '\n';

    return 0;
}
