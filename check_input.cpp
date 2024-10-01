#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::pair<int, int> countMatches(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    int sameIndexMatches = 0;   // Количество совпадений на одинаковых индексах
    int diffIndexMatches = 0;   // Количество совпадений на разных индексах

    const int n = std::min(vec1.size(), vec2.size());

    const std::unordered_set<int> set1(vec1.begin(), vec1.end());
    std::unordered_set<int> set2(vec2.begin(), vec2.end());

    for (int i = 0; i < n; ++i)
        if (vec1[i] == vec2[i])
            ++sameIndexMatches;

    for (int num : set1)
        if (set2.find(num) != set2.end())
            diffIndexMatches++;


    diffIndexMatches -= sameIndexMatches; // Количество совпадений на разных индексах. Общее количество совпадающих элементов минус те, что на одинаковых индексах

    return {sameIndexMatches, diffIndexMatches};
}

// Генерация всех возможных последовательностей
std::vector<std::vector<int>> generateAllCombinations() {
    std::vector<std::vector<int>> allCombos;

    // Генерирую все комбинации четырех цифр от 0000 до 9999
    for (int i = 0; i <= 9999; ++i) {
        std::vector<int> combo;
        int num = i;

        while (combo.size() < 4) {
            combo.push_back(num % 10);
            num /= 10;
        }
        std::reverse(combo.begin(), combo.end());
        allCombos.push_back(combo);
    }

    return allCombos;
}

std::vector<int> playBullsAndCows(const std::vector<int>& userInput) {
    std::vector<std::vector<int>> comboes = generateAllCombinations();

    std::vector<int> guess;
    std::pair<int, int> result;

    while (result.first != 4) {
        guess = comboes.front();

        result = countMatches(userInput, guess); // Проверка количества Быков и Коров

        std::vector<std::vector<int>> filteredCombos; // А тут я сохраняю только те результаты, которые могут потенциально подойти под решение

        for (const auto& combo : comboes)
            if (countMatches(guess, combo) == result)
                filteredCombos.push_back(combo);

        comboes = filteredCombos;
        std::cout << "Компьютер предполагает: ";
        for (int num : guess)
            std::cout << num;
        std::cout << ". В результате проверки " << result.first << " быков, " << result.second << " коров" << std::endl;
    }

    return guess;
}