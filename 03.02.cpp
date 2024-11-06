#include <iostream>
#include <string>
#include <Windows.h>

class Counter {
private:
    int value;

public:
    Counter() : value(1) {}

    Counter(int initialValue) : value(initialValue) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string choice;
    int initialValue;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> choice;

    Counter counter;

    if (choice == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
        counter = Counter(initialValue);  
    }
    else {
        counter = Counter();  
    }

    char command;

    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == '+') {
            counter.increment();
        }
        else if (command == '-') {
            counter.decrement();
        }
        else if (command == '=') {
            std::cout << "Текущее значение счётчика: " << counter.getValue() << std::endl;
        }
        else if (command == 'x') {
            std::cout << "До свидания!" << std::endl;
            break;
        }
        else {
            std::cout << "Неизвестная команда, попробуйте снова." << std::endl;
        }
    }

    return 0;
}
