#include <iostream>
#include "header.h"

void menu() {
    std::cout << "--------------------------\n";
    std::cout << "Из дополнительного кода в обратный\n";
    std::cout << "Выполнил: Финский Павел Владимирович, гр.453502\n";
    std::cout << "--------------------------\n";
}

char chinazes() {
    char choice;
    std::cout << "Хотите запустить программу?(y/n): ";
    std::cin >> choice;

    while(std::cin.peek() != '\n' || choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') { // O(n)    n - кол-во ошибок пользователя
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Неверный ввод, введите y/n: ";
        std::cin >> choice;
    }

    return choice;
}

void check(std::string& inp) { // O(n * m)
    bool valid = false;

    while (!valid) { // O(n)    n - кол-во ошибок пользователя
        getline(std::cin, inp); // O(m)    m - длина строки

        if (inp.empty()) {
            std::cout << "Неверный ввод. Введите непустую строку (только 0 и 1): ";
            continue;
        }

        bool all_valid = true;
        for (char ch : inp) { // O(m)
            if (ch != '0' && ch != '1') {
                all_valid = false;
                break;
            }
        }

        if (all_valid) {
            valid = true;
        } else {
            std::cout << "Неверный ввод. Введите только 0 и 1: ";
        }
    }
}

void convers(int* binary, int l) {
    if (binary[0] == 0) {
        return;
    }

    bool carry = true;
    for (int i = l - 1; i >= 0 && carry; --i) { // O(l)
        if (binary[i] == 1) {
            binary[i] = 0;
            carry = false;
        } else {
            binary[i] = 1;
        }
    }
}

void printer(const int* binary, int l) {
    for (int i = 0; i < l; ++i) { // O(l)
        std::cout << binary[i];
    }
    std::cout << std::endl;
}