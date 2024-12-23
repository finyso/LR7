#include <iostream>
#include "header.h"

void menu() {
    std::cout << "--------------------------\n";
    std::cout << "Делится ли введенное пользователем число на заданное простое\n";
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

void checkinp(std::string& inp) {
    bool valid = false;

    while (!valid) { // O(n)    n - кол-во ошибок пользователя
        getline(std::cin, inp);

        if (inp.empty()) {
            std::cout << "Неверный ввод. Введите непустую строку: ";
            continue;
        }

        bool all_valid = true;
        for (char ch : inp) { // O(m)    m - длина строки
            if (!isdigit(ch)) {
                all_valid = false;
                break;
            }
        }

        if (all_valid) {
            valid = true;
        } else {
            std::cout << "Неверный ввод. Введите только цифры: ";
        }
    }
}

bool check(const std::string& num, int p) {
    int remain = 0;

    for (char digit : num) { // O(m)    m - длина строки
        int currentDigit = digit - '0';
        remain = (remain * 10 + currentDigit) % p;
    }

    return remain == 0;
}