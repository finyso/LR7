#include <iostream>
#include <string>
#include "header.h"

int main() {
    menu();

    char choice = chinazes();

    if (choice == 'n' || choice == 'N') {
        std::cout << "Спасибо за использование!";
        return 1;
    }

    do {
        std::cout <<"Введите ваше число в дополнительном коде: ";

        std::string input;
        std::cin.ignore(10000, '\n');

        check(input);

        int l = input.length();
        int* binary = new int[l];

        for (int i = 0; i < l; ++i) {
            binary[i] = input[i] - '0';
        }

        convers(binary,l);

        std::cout << "Число в обратном коде: ";
        printer(binary, l);

        delete[] binary;

        choice = chinazes();
    }while(choice == 'y' || choice == 'Y');
    std::cout << "Спасибо за использование!";
    return 0;
}