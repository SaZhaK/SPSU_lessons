/***************************************
 * Первый курс                         *
 * Первый поток, группа 101            *
 * Коломиец Александр                  *
 *                                     *
 * Задача Иосифа                       *
 *                                     *
 ***************************************/


#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int arraySize = 20;
    int array[arraySize];
    int myNum = 4;

    for (int i = 3; i < arraySize; i++) {
        int position = -1;
        int zeroCounter = 0;

        for (int i = 0; i < arraySize; i++) {
            array[i] = i + 1;
        }

        while (zeroCounter < arraySize - 1) {
           position = (position + i) % arraySize;
           if (array[position] != 0) {
               array[position] = 0;
               zeroCounter++;
           } else break;
        }

        if (array[myNum - 1] != 0 && zeroCounter == arraySize - 1) {
            cout << i << endl;
            return 0;
        }
    }

    cout << "Поставленная задача не имеет решения" << endl;

    return 0;
}
