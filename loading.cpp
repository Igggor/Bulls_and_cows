#include <iostream>
#include <chrono>
#include <thread>

void loadingSimulation(const int seconds) {
    /*
     * Тут я решил сделать что-то типо фейковой загрузки.
     * Смысла никакого, просто имитация загрузки игры
     */
    const int barWidth = 10;  // Ширина шкалы загрузки, количество квадратиков
    int totalSteps = barWidth; // Количество шагов в шкале, то есть за сколько шагов она заполнится
    const int delay = (seconds * 1000) / totalSteps; // Задержка на каждый шаг
    std::cout << "_________________________\n";
    std::cout << "Происходит загрузка игры: \n";
    std::cout << "Загрузка: [";

    for (int i = 0; i < barWidth; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        std::cout << "\rЗагрузка: [";

        for (int j = 0; j <= i; ++j)
            std::cout << "█";
        for (int j = i + 1; j < barWidth; ++j)
            std::cout << " ";

        std::cout << "] " << ((i + 1) * 100 / barWidth) << "%";
        std::cout.flush();
    }

    std::cout << "\rЗагрузка: [██████████] 100%" << std::endl;
    std::cout << "Загрузка игры завершена завершена!" << std::endl;
}