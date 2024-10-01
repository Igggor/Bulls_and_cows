#include "main_header.h"


int main(){
	system("chcp 65001");
	int type = chooseGame();
	loadingSimulation(3);
	if (type == 1) {
		std::vector<int> computer_digits = generateUniqueRandomDigits();
		std::cout << "\n\nКомпьютер сгенерировал 4 цифры. Постарайтесь угадать их\n";
		std::pair<int, int> bulls_and_cows;
		while (true) {
			std::vector<int> input_1 = getUserInput();
			bulls_and_cows = countMatches(input_1, computer_digits);
			if (bulls_and_cows.first == 4)
				break;
			std::cout << "Последовательность не угадана.\n\n Среди введенной Вами последовательности \nБыков: " << bulls_and_cows.first << "; \nКоров: " << bulls_and_cows.second << std::endl;
		}
		std::cout << "Поздравляю, Вы угадали последовательность, загаданную компьютером. Вы победили в игре";

	}
	if (type == 2) {
		std::vector<int> input = getUserInput();
		std::vector<int> computerGuess = playBullsAndCows(input);
	}
	return 0;
}
