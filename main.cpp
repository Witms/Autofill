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
			std::cout << "Ââåäèòå\n '1' äëÿ äîáàâëåíèÿ ñëîâà â ñëîâàðü\n '2' äëÿ ïðîâåðêè àâòîçàïîëíåíèÿ\n '3' äëÿ ïðîâåðêè, ÷òî òàêîå ñëîâî åñòü â ñëîâàðå\n '4' äëÿ óäàëåíèÿ ñëîâà\n '5' äëÿ çàâåðøåíèÿ ïðîãðàììû" << std::endl;
			break;

		case '1':
			std::cout << "Ââåäèòå ñëîâî: ";
			std::cin >> input;
			chat.insert(input);
			break;

		case '2': {
			char inChoose;

			std::cout << "Ââåäèòå ÷àñòü ñëîâà: ";
			cin >> input;
			chat.searchOption(input);
			string str;

			do {
				str = chat.get_optionByOne();
				if (str.empty())
					continue;
				std::cout << std::endl << str << " ýòî òî ñëîâî y/n: ";
				std::cin >> inChoose;

			} while (inChoose != 'y' && !str.empty());

			if (inChoose == 'y')
				std::cout << "Âàøå ñëîâî: " << str << std::endl;
			else if (inChoose == 'n')
				std::cout << "Íåòó áîëüøå ïîäõîäÿùèõ ñëîâ " << std::endl;
			break;
		}
		case '3':
			std::cout << "Ââåäèòå ñëîâî: ";
			std::cin >> input;
			if (chat.search(input))
				std::cout << "Ñëîâî " << input << " åñòü â ñëîâàðå" << std::endl;
			else
				std::cout << "Ñëîâî " << input << " íåòó â ñëîâàðå" << std::endl;
			break;

		case '4':
			std::cout << "Êëþ÷ äëÿ óäàëåíèÿ: ";
			cin >> input;
			chat.remove(input);
			break;

		default:
			std::cout << "Ââåäèòå '?' äëÿ ñïðàâêè" << std::endl;
		}

		std::cout << "Ââàø ââîä: ";
		std::cin >> choose;
		std::cout << std::endl;

	} while (choose != '5');


	return 0;
}
