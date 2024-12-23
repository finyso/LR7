#include <iostream>
#include "header.h"

const int barrels = 240;
const int slaves = 5;

int main() {
    menu();

    char choice = chinazes();

    if (choice == 'n' || choice == 'N') {
        std::cout << "Спасибо за использование!";
        return 1;
    }

    do {
        int n;
        std::cout << "Введите номер отравленной бочки (от 1 до 240): ";
        std::cin >> n;

        while (std::cin.peek() != '\n' || std::cin.fail() || (n <= 0 && n > 240)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод. Введите число от 1 до 240: ";
            std::cin >> n;
        }

        n -= 1;

        int* result = new int[slaves]();

        int size = (barrels + (1 << slaves) - 1) / (1 << slaves);
        std::cout << "Определяем количество групп: " << size << '\n';
        int group = n / size;
        std::cout << "Вычисляем номер группы бочки: " << group << '\n';
        int l = n % size;
        std::cout << "Локальный номер бочки: " << l << '\n';

        assign(l, slaves, result);

        int x = find(result, slaves) + group * size + 1;
        std::cout << "Определённый номер отравленной бочки: " << x << std::endl;

        delete[] result;
        choice = chinazes();
    }while(choice == 'y' || choice == 'Y');
    std::cout << "Спасибо за использование!";
    return 0;
}