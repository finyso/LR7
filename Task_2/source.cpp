#include <iostream>
#include <cmath>
#include "header.h"

void menu() {
    std::cout << "--------------------------\n";
    std::cout << "Найдите сумму двоичных чисел, заданных в естественной форме.\n";
    std::cout << "Сложение выполните в обратном коде. Ответ выразите в прямом коде.\n";
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

int* tobinar(int num, int l) {
    int* binary = new int[l](); // O(l)
    int absNum = abs(num);

    for (int i = l - 1; i > 0; --i) { // O(l)
        binary[i] = absNum % 2;
        absNum /= 2;
    }

    if (num < 0) {
        binary[0] = 1;
    }

    return binary;
}

int* toobr(const int* binary, int l) {
    int* obr = new int[l]; // O(l)

    for (int i = 0; i < l; ++i) { // O(l)
        obr[i] = binary[i];
    }

    if (binary[0] == 1) {
        for (int i = 1; i < l; ++i) { // O(l)
            obr[i] = 1 - binary[i];
        }
    }

    return obr;
}

int* sumbin(const int* bin1, const int* bin2, int l) {
    int* result = new int[l](); // O(l)
    int remain = 0;

    for (int i = l - 1; i >= 0; --i) { // O(l)
        int sum = bin1[i] + bin2[i] + remain;
        result[i] = sum % 2;
        remain = sum / 2;
    }

    if (remain) {
        for (int i = l - 1; i > 0; --i) { // O(l)
            result[i] += 1;
            if (result[i] == 2) {
                result[i] = 0;
            } else {
                break;
            }
        }
    }

    return result;
}

int* convert(const int* obr, int l) {
    int* result = new int[l]; // O(l)

    for (int i = 0; i < l; ++i) { // O(l)
        result[i] = obr[i];
    }

    if (obr[0] == 1) {
        for (int i = 1; i < l; ++i) { // O(l)
            result[i] = 1 - obr[i];
        }
    }

    return result;
}

void printer(const int* binary, int l) {
    for (int i = 0; i < l; ++i) { // O(l)
        std::cout << binary[i];
    }
    std::cout << std::endl;
}