#include <iostream>
#include <vector>

std::vector<int> getUserInput() {
    /*
     * Функция для ввода данных с клавиатуры пользователя
     */
    std::vector<int> numbers;
    int el;

    std::cout << "Введите четыре цифры через пробел: \n ";
    for (int i = 0; i < 4; ++i) {
        std::cin >> el;
        numbers.push_back(el);
    }

    return numbers;
}
