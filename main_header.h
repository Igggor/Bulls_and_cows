//
// Created by Админ on 30.09.2024.
//

#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#endif //MAIN_HEADER_H

#include <iostream>
#include <vector>

using Numbers = std::vector<int>;


Numbers generateUniqueRandomDigits();
Numbers getUserInput();
void loadingSimulation(int seconds);
std::pair<int, int> countMatches(const Numbers& vec1, const Numbers& vec2);
Numbers playBullsAndCows(const Numbers& userInput);
int chooseGame();
