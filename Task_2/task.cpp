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
        int l, num1, num2;

        std::cout << "Введите кол-во битов в числе: ";
        std::cin >> l;

        while (std::cin.peek() != '\n' || std::cin.fail() || l <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод. Введите неотрицательное целое число: ";
            std::cin >> l;
        }

        std::cout <<"Введите первое число в двоичной форме (естественная форма): ";
        std::cin >> num1;

        std::cout <<"Введите второе число в двоичной форме (естественная форма): ";
        std::cin >> num2;

        int* bin1 = tobinar(num1, l);
        int* bin2 = tobinar(num2, l);
        int* obr1 = toobr(bin1, l);
        int* obr2 = toobr(bin2, l);
        int* sum = sumbin(obr1, obr2, l);
        int* result = convert(sum, l);

        std::cout << "Прямой и обратный код первого числа:\n";
        printer(bin1, l);
        printer(obr1, l);

        std::cout << "Прямой и обратный код второго числа:\n";
        printer(bin2, l);
        printer(obr2, l);

        std::cout << "Результат сложения в обратном и прямом коде:\n";
        printer(sum, l);
        printer(result, l);

        delete[] bin1;
        delete[] bin2;
        delete[] obr1;
        delete[] obr2;
        delete[] sum;
        delete[] result;

        choice = chinazes();
    }while(choice == 'y' || choice == 'Y');
    std::cout << "Спасибо за использование!";
    return 0;
}