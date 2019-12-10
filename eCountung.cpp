/*****************************
 * Первый курс               *
 * Первый поток, группа 101  *
 * Коломиец Александр        *
 *                           *
 * Вычисление числа Эйлера   *
 *                           *
 *****************************/


#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    double sum = 1.0, a = 1.0;
    int n = 1;

    while (a > 1e-7) {
        sum += a;
        a /= ++n;
    }

    printf("E = %.7f\n\n", sum);

    return 0;
}
