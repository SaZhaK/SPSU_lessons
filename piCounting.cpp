/*****************************
 * Первый курс               *
 * Первый поток, группа 101  *
 * Коломиец Александр        *
 *                           *
 * Вычисление числа Пи   *
 *                           *
 *****************************/


#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    double radius = 1;
    double hipotenuse, leg1, leg2;
    int accuracy = 13;

    hipotenuse = sqrt(pow(radius, 2)+ pow(radius, 2));

    for (int i = 0; i < accuracy; i++) {
        leg1 = hipotenuse / 2;
        leg2 = radius - sqrt(pow(radius, 2) - pow(leg1, 2));
        hipotenuse = sqrt(pow(leg1, 2) + pow(leg2, 2));
    }

    double pi = 4 * pow(2, accuracy) *hipotenuse / (2. * radius);

    printf("Pi = %.7f\n\n", pi);

    return 0;
}
