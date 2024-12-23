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
        int n, size;

        std::cout << "Введите основание системы счисления: ";
        std::cin >> n;

        while (std::cin.peek() != '\n' || std::cin.fail() || n <= 1) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод. Введите число больше 1: ";
            std::cin >> n;
        }

        std::string* alphabet = alpha(n, size);
        std::string num1, num2;

        std::cout << "Введите первое число: ";
        std::cin >> num1;
        std::cout << "Введите второе число: ";
        std::cin >> num2;

        bool is_negative_num1 = num1[0] == '-';
        bool is_negative_num2 = num2[0] == '-';

        if (is_negative_num1) num1 = num1.substr(1);
        if (is_negative_num2) num2 = num2.substr(1);

        std::string sum, difference;

        if (is_negative_num1 == is_negative_num2) {
            sum = add(num1, num2, alphabet, size);
            if (is_negative_num1) sum = "-" + sum;
        } else {
            if (num1 == num2) {
                sum = "0";
            } else if (num1 > num2) {
                sum = subtract(num1, num2, alphabet, size);
                if (is_negative_num1) sum = "-" + sum;
            } else {
                sum = subtract(num2, num1, alphabet, size);
                if (is_negative_num2) sum = "-" + sum;
            }
        }

        if (is_negative_num1 == is_negative_num2) {
            if (num1 == num2) {
                difference = "0";
            } else if (num1 > num2) {
                difference = subtract(num1, num2, alphabet, size);
                if (is_negative_num1) difference = "-" + difference;
            } else {
                difference = subtract(num2, num1, alphabet, size);
                if (!is_negative_num1) difference = "-" + difference;
            }
        } else {
            difference = add(num1, num2, alphabet, size);
            if (is_negative_num1) difference = "-" + difference;
        }

        std::cout << "Сумма: " << sum << '\n' << "Разность: " << difference << '\n';

        delete[] alphabet;

        choice = chinazes();
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Спасибо за использование!";
    return 0;
}
