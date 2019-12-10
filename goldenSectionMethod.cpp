/**********************************************************
 * Первый курс                                            *
 * Первый поток, группа 101                               *
 * Коломиец Александр                                     *
 *                                                        *
 * Нахождение экстремума функции методом золотого сечения *
 *                                                        *
 **********************************************************/

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

double g(double x) {
    return log(1 + x * x - cos(x)) - pow(M_E, sin(M_PI * x));
}

int main(int argc, char *argv[])
{
    double leftBorder, rightBorder, accuracy, x1, x2;
    cout << "Введите левую границу отрезка: ";
    cin >> leftBorder;
    cout << "Введите правую границу отрезка: ";
    cin >> rightBorder;
    cout << "Введите требуемую точность вычислений: ";
    cin >> accuracy;

    do {
    x1 = rightBorder - (rightBorder - leftBorder) * (sqrt(5) - 1) / 2;
    x2 = leftBorder + (rightBorder - leftBorder) * (sqrt(5) - 1) / 2;

    if (g(x1) > g(x2)) rightBorder = x2;
    else leftBorder = x1;

    } while (fabs(rightBorder - leftBorder) > accuracy);

    cout << "Приближённые координаты точки экстремума: " << endl;
    cout << "x = " << (leftBorder + rightBorder) / 2 << endl;
    cout << "y = " << g((leftBorder + rightBorder) / 2) << endl;

    return 0;
}
