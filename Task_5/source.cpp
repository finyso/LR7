#include <iostream>
#include "header.h"

void menu() {
    std::cout << "--------------------------\n";
    std::cout << "Определение отравленной бочки методом тестов рабов\n";
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

void assign(int l, int s, int* slaveresult) {
    std::cout << "Определяем, какие рабы пьют из бочки" << std::endl;
    for (int i = 0; i < s; ++i) { // O(s)
        slaveresult[i] = (l & 1 << i) != 0 ? 1 : 0;
        std::cout << "Для раба " << i + 1 << " :" << slaveresult[i] << "\n";
    }
}

int find(const int* slaveresult, int s) {
    int n = 0;
    for (int i = 0; i < s; ++i) { // O(s)м
        if (slaveresult[i] == 1) {
            std::cout << "Умер: " << i + 1 << " раб" << std::endl;
            n |= 1 << i;
        }
    }
    return n;
}