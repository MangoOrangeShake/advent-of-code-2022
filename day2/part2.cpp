#include <fstream>
#include <iostream>

auto CalcScore(char enemy_move, char outcome ) -> int
{
    int score { 0 };
    const int win { 6 };

    if (outcome == 'X')
        score += 0;
    if (outcome == 'Y')
        score += 3;
    if (outcome == 'Z')
        score += win;
    if (enemy_move == 'A' && outcome == 'X')
        score += 3;
    if (enemy_move == 'A' && outcome == 'Y')
        score += 1;
    if (enemy_move == 'A' && outcome == 'Z')
        score += 2;
    if (enemy_move == 'B' && outcome == 'X')
        score += 1;
    if (enemy_move == 'B' && outcome == 'Y')
        score += 2;
    if (enemy_move == 'B' && outcome == 'Z')
        score += 3;
    if (enemy_move == 'C' && outcome == 'X')
        score += 2;
    if (enemy_move == 'C' && outcome == 'Y')
        score += 3;
    if (enemy_move == 'C' && outcome == 'Z')
        score += 1;

    return score;
}

auto main() -> int
{
    std::ifstream inf { "encrypted.txt" };

    if (!inf) {
        std::cerr << "Can't read encrypted.txt\n";
        return 1;
    }

    int score { 0 };
    char enemy_turn { 0 };
    char outcome { 0 };

    while (inf >> enemy_turn) {
        inf >> outcome;
        score += CalcScore(enemy_turn, outcome);
    }

    std::cout << "The true final score is: " << score << '\n';

    return 0;
}
