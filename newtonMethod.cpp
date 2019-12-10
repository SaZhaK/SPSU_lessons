/*******************************************************************
 * Первый курс                                                     *
 * Первый поток, группа 101                                        *
 * Коломиец Александр                                              *
 *                                                                 *
 * Решение уравнений методом Ньютона (методом касательных)         *
 *                                                                 *
 *******************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

float func(float x) {
    return (float) sin(M_PI*x / 180) - 1 / x;
}

float func1(float x) {
    return (float) M_PI / 180 * cos(M_PI*x / 180) + 1 / (x*x);
}

int main(int argc, char *argv[])
{
    float initialValue, accuracy, lastValue;
    cout << "Введите начальное значение: ";
    cin >> initialValue;
    cout << "Введите требуемую точность: ";
    cin >> accuracy;

    do {
        lastValue = initialValue;
        initialValue = initialValue - func(initialValue) / func1 (initialValue);
    } while (initialValue - lastValue >= accuracy);

    cout << "Ответ: " << initialValue << endl;

    return 0;
}
