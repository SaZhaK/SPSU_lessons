/***************************************
 * Первый курс                         *
 * Первый поток, группа 101            *
 * Коломиец Александр                  *
 *                                     *
 * Решение уравнений методом итераций  *
 *                                     *
 ***************************************/


#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

float f(float x) {
    return (float)1 / (sin(M_PI*x / 180));
}

int main(int argc, char *argv[])
{
    float curX, nextX, E;
    cout << "Введите начальное значение: ";
    cin >> curX;
    cout << "ВВедите требуемую точность: ";
    cin >> E;

    do {
        nextX = curX;
        curX = f(curX);
    } while (fabs(nextX - curX) > E);

    cout << "Приближённый ответ: " << curX << endl << endl;

    return 0;
}
