#include <iostream>
#include <cmath>
#include <iomanip>
#include<windows.h> //for sleep(ms)
//#include <dos.h> //for deley(ms) 


using namespace std;

int main()
{
    float size;
    float speed;
    cout << "Ввод:\n";
    do {
        cout << "Укажите размер файла для скачивания: ";
        cin >> size;
        cin.ignore(100, '\n');
        cout << "Какова скорость вашего соединения? ";
        cin >> speed;
        cin.ignore(100, '\n');
        if (size < 0 || speed < 0) cout << "Укажите не отрицательные значения!\n";
    } while (size < 0 || speed < 0);
    cout << "Вывод:\n";
    cout << fixed << setprecision(1);
    float downolad = 0;
    int percent = 0;
    for (int time = 1; percent < 100; time++) {
        cout << "Прошло " << time << " сек. ";
        if (speed > size) speed = size;
        downolad += speed;
        if (downolad > size) downolad = size;
        percent = downolad * 100 / size;
        cout << "Скачано " << downolad << " из " << size << " МБ (" << percent << "%).\n";
        Sleep(1000); //я знаю что это типо костыль, он просто прерывает выполнение программы. 
        // Если бы у нас реально что-то скачивалось бы с заданной скоростью, то вывод информации каждую секунду надо было реализовать по другому
        // На arduino есть функция milis()
        // по любому как-то можно сделать привязку к времени системы и сделать условие, что бы информация выводилась каждую секунду системного времени
        // просто в нашем случае за секунду уже весь код сделается
    }
    return 0;
}