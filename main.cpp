#include "Autofill.h"
#include <iostream>


int main() {
	
	setlocale(LC_ALL, "rus");

	Autofill chat;

	string input;
	char choose = '?';
	do {
		switch (choose) {
		case '?':
			std::cout << "Введите\n '1' для добавления слова в словарь\n '2' для проверки автозаполнения\n '3' для проверки, что такое слово есть в словаре\n '4' для удаления слова\n '5' для завершения программы" << std::endl;
			break;

		case '1':
			std::cout << "Введите слово: ";
			std::cin >> input;
			chat.insert(input);
			break;

		case '2': {
			char inChoose;

			std::cout << "Введите часть слова: ";
			cin >> input;
			chat.searchOption(input);
			string str;

			do {
				str = chat.get_optionByOne();
				if (str.empty())
					continue;
				std::cout << std::endl << str << " это то слово y/n: ";
				std::cin >> inChoose;

			} while (inChoose != 'y' && !str.empty());

			if (inChoose == 'y')
				std::cout << "Ваше слово: " << str << std::endl;
			else if (inChoose == 'n')
				std::cout << "Нету больше подходящих слов " << std::endl;
			break;
		}
		case '3':
			std::cout << "Введите слово: ";
			std::cin >> input;
			if (chat.search(input))
				std::cout << "Слово " << input << " есть в словаре" << std::endl;
			else
				std::cout << "Слово " << input << " нету в словаре" << std::endl;
			break;

		case '4':
			std::cout << "Ключ для удаления: ";
			cin >> input;
			chat.remove(input);
			break;

		default:
			std::cout << "Введите '?' для справки" << std::endl;
		}

		std::cout << "Вваш ввод: ";
		std::cin >> choose;
		std::cout << std::endl;

	} while (choose != '5');



	return 0;
}