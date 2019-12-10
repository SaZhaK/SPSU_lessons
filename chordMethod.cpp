/***************************************
 * Первый курс                         *
 * Первый поток, группа 101            *
 * Коломиец Александр                  *
 *                                     *
 * Решение уравнений методом хорд      *
 *                                     *
 ***************************************/

#include <iostream>
#include <math.h>

using namespace std;

double fun(double x) {
    return log10(x) + 2*x - 5;
}

int main(int argc, char *argv[])
{
    double leftBorder, rightBorder, accuracy;
    cout << "Введите левую границу отрезка ";
    cin >> leftBorder;
    cout << "Введите правую границу отрезка: ";
    cin >> rightBorder;
    cout << "Введите требуемую точность: ";
    cin >> accuracy;

    do {
        leftBorder = leftBorder - fun(leftBorder) / (fun(leftBorder) - fun(rightBorder) * (leftBorder - rightBorder));
    } while (fabs(fun(leftBorder)) > accuracy);

    cout << "\nПриближённый ответ равен " << leftBorder << endl << endl;

    return 0;
}
