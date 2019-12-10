/***************************************
 * Первый курс                         *
 * Первый поток, группа 101            *
 * Коломиец Александр                  *
 *                                     *
 * Решение уравнений методом дихотомии *
 *                                     *
 ***************************************/


#include <iostream>
#include <math.h>

using namespace std;

float function(float x) {
    return tan(x) - 1/2.;
}

int main(int argc, char *argv[])
{
    float leftBorder, rightBorder;

    cout << "Введите границы отрезка, на котором преположительно расположен корень: " << endl;
    cout << "Левая граница: ";
    cin >> leftBorder;
    cout << "Правая граница: ";
    cin >> rightBorder;

    if (function(leftBorder) * function(rightBorder) > 0) {
        cout << "На данном отрезке нет решений" << endl;
        return 0;
    }

    float middle = (leftBorder + rightBorder) / 2.;
    while (fabs(rightBorder - leftBorder) > 1e-8) {
        if (function(middle) * function(leftBorder) > 0) leftBorder = middle;
        else if (function(middle) * function(rightBorder) > 0) rightBorder = middle;
        else break;
        middle = (leftBorder + rightBorder) / 2.;
    }

    cout << "x = " << middle << endl;

    return 0;
}
