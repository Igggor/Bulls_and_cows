#include <vector>
#include <ctime>
#include <algorithm>

std::vector<int> generateUniqueRandomDigits() {
    std::vector<int> digits;
    srand(static_cast<unsigned int>(time(0)));

    while (digits.size() < 4) {
        int newDigit = rand() % 10;

        // Проверяю, есть ли уже такое число в векторе
        if (std::find(digits.begin(), digits.end(), newDigit) == digits.end())
            digits.push_back(newDigit);

    }
    return digits;
}

// Да, возможно, что такое решение будет работать бесконечно. Тогда пользоку просто не повезло 🤭
