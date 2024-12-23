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

    while(std::cin.peek() != '\n' || choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') { //O(n)    n - кол-во ошибок пользователя
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Неверный ввод, введите y/n: ";
        std::cin >> choice;
    }

    return choice;
}

std::string* alpha(int n, int& size) { // O(n log n)
    size = n;
    std::string* alphabet = new std::string[n]; //  O(n)

    for (int i = 0; i < n; ++i) { //  O(n)
        if (i < 10) {
            alphabet[i] = std::string(1, '0' + i);
        } else {
            int temp = i - 10;
            std::string symbol;
            while (temp >= 0) { //  O(log n)
                symbol = char('A' + temp % 26) + symbol;
                temp = temp / 26 - 1;
            }
            alphabet[i] = symbol;
        }
    }
    return alphabet;
}

int index(const std::string& symbol, std::string* alphabet, int size) { // O(size)
    for (int i = 0; i < size; ++i) { // O(size)
        if (alphabet[i] == symbol) {
            return i;
        }
    }
    return -1;
}

std::string to_symbol(int value, std::string* alphabet, int size) {
    if (value < 0 || value >= size) {
        return "";
    }
    return alphabet[value];
}

std::string add(const std::string& num1, const std::string& num2, std::string* alphabet, int size) { // O(size * max_len)
    int n = size;
    std::string result;
    int carry = 0;
    size_t len1 = num1.size(), len2 = num2.size();
    size_t max_len = std::max(len1, len2);

    for (size_t i = 0; i < max_len || carry > 0; ++i) { // O(max_len)
        int value1 = (i < len1) ? index(std::string(1, num1[len1 - 1 - i]), alphabet, n) : 0; // O(size)
        int value2 = (i < len2) ? index(std::string(1, num2[len2 - 1 - i]), alphabet, n) : 0; // O(size)

        if (value1 == -1 || value2 == -1) {
            return "";
        }

        int sum = value1 + value2 + carry;
        std::string symbol = to_symbol(sum % n, alphabet, n);

        if (symbol.empty()) {
            return "";
        }

        result += symbol;
        carry = sum / n;
    }

    return result;
}

std::string subtract(const std::string& num1, const std::string& num2, std::string* alphabet, int size) { // O(len1 * size)
    int n = size;
    std::string result;
    int borrow = 0;

    size_t len1 = num1.size(), len2 = num2.size();

    if (len1 < len2 || (len1 == len2 && num1 < num2)) { // O(len1 + len2)
        return "";
    }

    for (size_t i = 0; i < len1; ++i) { // O(len1)
        int value1 = index(std::string(1, num1[len1 - 1 - i]), alphabet, n); // O(size)
        int value2 = (i < len2) ? index(std::string(1, num2[len2 - 1 - i]), alphabet, n) : 0; // O(size)

        if (value1 == -1 || value2 == -1) {
            return "";
        }

        int diff = value1 - value2 - borrow;

        if (diff < 0) {
            diff += n;
            borrow = 1;
        } else {
            borrow = 0;
        }

        std::string symbol = to_symbol(diff, alphabet, n);
        if (symbol.empty()) {
            return "";
        }

        result += symbol;
    }

    while (result.size() > 1 && result[0] == alphabet[0][0]) { // O(len1)
        result.erase(0, 1); // O(len1)
    }
    return result;
}