#include <iostream>
#include "header.h"

int main() {
    menu();

    char choice = chinazes();

    if (choice == 'n' || choice == 'N') {
        std::cout << "Спасибо за использование!";
        return 1;
    }

    do {
        std::string input;
        std::cout << "Введите число: ";
        std::cin.ignore(10000, '\n');

        checkinp(input);

        const int p1 = 3;
        bool on3 = check(input, p1);
        std::cout << "Делится на 3: " << (on3 ? "Да" : "Нет") << std::endl;

        const int p2 = 79;
        bool on79 = check(input, p2);
        std::cout << "Делится на 79: " << (on79 ? "Да" : "Нет") << std::endl;

        const int p3 = 151;
        bool on151 = check(input, p3);
        std::cout << "Делится на 151: " << (on151 ? "Да" : "Нет") << std::endl;

        choice = chinazes();
    }while(choice == 'y' || choice == 'Y');
    std::cout << "Спасибо за использование!";
    return 0;
}