//
// Created by Админ on 30.09.2024.
//

#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#endif //MAIN_HEADER_H

#include <iostream>
#include <vector>


std::vector<int> generateUniqueRandomDigits();
std::vector<int> getUserInput();
void loadingSimulation(int seconds);
std::pair<int, int> countMatches(const std::vector<int>& vec1, const std::vector<int>& vec2);
std::vector<int> playBullsAndCows(const std::vector<int>& userInput);
int chooseGame();
