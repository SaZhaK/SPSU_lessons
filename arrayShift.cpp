#include <iostream>

using namespace std;

template <typename T>
void reverse(T* array, int n) {
    T temp;
    for (int i = 0, j = n-1; i < j; ++i, --j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

template <typename T>
void kshift (T* array, int n, int k) {
    while(k<0) k+= n;
    k %= n;

    reverse(array, n);
    reverse(array, n-k);
    reverse(array+(n-k), k);
}

template <typename T>
void print (const T* array, int arraySize, const char *str="") {
    cout << str;
    for (int i = 0; i < arraySize; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int ArrayShift(int argc, char *argv[]) {
    int arraySize;
    cout << "Введите размер массива: ";
    cin >> arraySize;

    cout << "Введите элементы массива: " << endl;
    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

    cout << "Введите длинну сдвига: ";
    int k;
    cin >> k;

    kshift(array, arraySize, k);

    print(array, arraySize);

    return 0;
}
