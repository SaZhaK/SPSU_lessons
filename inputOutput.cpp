/*******************************************************************
 * Первый курс                                                     *
 * Первый поток, группа 101                                        *
 * Коломиец Александр                                              *
 *                                                                 *
 * Работа с потоками ввода/вывода и взаимодействие с пользователем *
 *                                                                 *
 *******************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    int farenheightTemp;
    int highTemperature = 40;
    int lowTemperature = 10;

    cout << "Hello" << endl;

    char exitCondition;

    while (exitCondition != 'q') {
    cout << "Input the temperature by Farenheight please" << endl;
    cin >> farenheightTemp;

    double celsiusTemp = (farenheightTemp - 32) / 1.8;

    cout << "The temperature in Celsius is: " << celsiusTemp << endl;

    if (celsiusTemp > highTemperature) {
        cout << "It's ";
        for (int i = 0; i < celsiusTemp / 10 - 1; i++) cout << " very ";
        cout << " hot" << endl;
    }
    else if (celsiusTemp < lowTemperature) {
        cout << "It's ";
        for (int i = 0; i < fabs(celsiusTemp / 10) - 1; i++) cout << " very ";
        cout << " cold" << endl;
    }
    else if (celsiusTemp >= 10 && celsiusTemp <= 40) cout << "The weather is good" << endl;

    cout << "Input q to exit, input c to continue" << endl;
    cin >> exitCondition;
    while (!(exitCondition == 'q' || exitCondition == 'c')) {
        cout << "Invalid operation, please try again" << endl;
        cin >> exitCondition;
    }
}

    cout << endl;
    return 0;
}
