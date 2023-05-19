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
			std::cout << "�������\n '1' ��� ���������� ����� � �������\n '2' ��� �������� ��������������\n '3' ��� ��������, ��� ����� ����� ���� � �������\n '4' ��� �������� �����\n '5' ��� ���������� ���������" << std::endl;
			break;

		case '1':
			std::cout << "������� �����: ";
			std::cin >> input;
			chat.insert(input);
			break;

		case '2': {
			char inChoose;

			std::cout << "������� ����� �����: ";
			cin >> input;
			chat.searchOption(input);
			string str;

			do {
				str = chat.get_optionByOne();
				if (str.empty())
					continue;
				std::cout << std::endl << str << " ��� �� ����� y/n: ";
				std::cin >> inChoose;

			} while (inChoose != 'y' && !str.empty());

			if (inChoose == 'y')
				std::cout << "���� �����: " << str << std::endl;
			else if (inChoose == 'n')
				std::cout << "���� ������ ���������� ���� " << std::endl;
			break;
		}
		case '3':
			std::cout << "������� �����: ";
			std::cin >> input;
			if (chat.search(input))
				std::cout << "����� " << input << " ���� � �������" << std::endl;
			else
				std::cout << "����� " << input << " ���� � �������" << std::endl;
			break;

		case '4':
			std::cout << "���� ��� ��������: ";
			cin >> input;
			chat.remove(input);
			break;

		default:
			std::cout << "������� '?' ��� �������" << std::endl;
		}

		std::cout << "���� ����: ";
		std::cin >> choose;
		std::cout << std::endl;

	} while (choose != '5');



	return 0;
}