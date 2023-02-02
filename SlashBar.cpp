#include <iostream>
#include <string>
#include <thread>

int main()
{
    std::string bar(50, '\u25A0'); // инициализация прогресс бара состоящего из 50 слешей зеленого цвета
    int i = 0; // переменная для указания прогресса

    while (i <= 50) { // цикл, до 50, т.к. 50 - максимум слешей, которыми будет указываться прогресс

        std::cout << "\r" << bar; // \r - указывает, что этот cout-вывод будет "выводить" (помним: cout - console output) 
        // "над" (overwrite) - "прошлым" (previous) cout-выводом.

        bar.replace(i, 1, "\u25A2"); // replace() - replaces a sequence of characters in a string with new characters

        std::cout << i * 2 << "%"; // cout-вывод %

        i++; // i++ - increment operator

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // sleep_for() - pauses the execution of the current thread for a specified duration
    }

    std::cout << "\nDone!\n";

    return 0;
}