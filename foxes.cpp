#include "main.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//конструктор, в котором полю рандомно присваиваются лисы со значением -1 и пустые ячейки со значением 0.

Hunter_foxes::Hunter_foxes() : foxesFound(0) {
        srand(time(nullptr));
        for (int i = 0; i < field_size; ++i) {
            for (int j = 0; j < field_size; ++j) {
                field[i][j] = 0;
            }
        }

        for (int i = 0; i < count_fox; ++i) {
            int x = rand() % field_size;
            int y = rand() % field_size;
            field[x][y] = -1;
        }
        
    }

//далее вводится функция, в котором мы создаем цикл.

void Hunter_foxes::play() {
    while (foxesFound < count_fox) {
        int x, y;
        cout << "Введите координаты (x, y): ";
        cin >> x >> y;

//мы проверяем правильно ли введены значения координат.

        if (x < 0 || x >= field_size || y < 0 || y >= field_size) {
            cout << "Неверно введены координаты." << endl;
            continue;
        }

//если значение координаты в поле равно -1, мы присваиваем 1 и оповещаем пользователя, что лис найден.

        if (field[x][y] == -1) {
            foxesFound++;
            field[x][y] = 1;
            cout << "Лис найден!" << endl;

//если не нашли лиса, то мы определяем сколько лисов вокруг
//Соответственно, если значение стало равно 1, то лисы вокруг не обнаруживаются.

        } else {
            int foxesCount = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int x0 = x + i;
                    int y0 = y + j;
                    if (x0 >= 0 && x0 < field_size && y0 >= 0 && y0 < field_size) {
                        if (field[x0][y0] == -1) {
                            foxesCount++;
                        }
                    }
                }
            }
            cout << foxesCount << " лисов вокруг." << endl;
        }
    }
    cout << "Все лисы найдены!" << endl;
}
