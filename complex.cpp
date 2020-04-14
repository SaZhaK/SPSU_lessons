/*
 * Complex number
 Kolomiets Alexander
 PM-PU, 101
 13.04.2020
*/

#include <iostream>
#include <math.h>

using namespace std;

struct complexNumber{
    double real;
    double imaginary;
};

// Сложение
complexNumber add (complexNumber z1, complexNumber z2) {
    complexNumber sum = {z1.real + z2.real, z1.imaginary + z2.imaginary};
    return sum;
}

// Вычитание
complexNumber subtract (complexNumber z1, complexNumber z2) {
    complexNumber difference = {z1.real - z2.real, z1.imaginary - z2.imaginary};
    return difference;
}

// Умножение
complexNumber multiply (complexNumber z1, complexNumber z2) {
    complexNumber product = {z1.real * z2.real - z1.imaginary * z2.imaginary, z1.real * z2.imaginary + z1.imaginary * z2.real};
    return product;
}

// Деление
complexNumber divide (complexNumber z1, complexNumber z2) {
    complexNumber quotient =
    {(z1.real * z2.real + z1.imaginary * z2.imaginary) / (pow(z2.real, 2) + pow(z2.imaginary, 2)),
                (z1.imaginary * z2.real - z1.real * z2.imaginary) / (pow(z2.real, 2) + pow(z2.imaginary, 2))};
    return quotient;
}

// Ввод комплексного числа
complexNumber createComplexNumber() {
    double real, imaginary;
    cout << "Real: ";
    cin >> real;
    cout << "Imaginary: ";
    cin >> imaginary;
    cout << endl;
    return {real, imaginary};
}

// Вывод комплексного числа
void display(complexNumber z) {
    if (z.imaginary != 0) {
        cout << z.real << " + " << z.imaginary << "i";
    } else {
        cout << z.real;
    }
}

int main(int argc, char* argv[]) {
    cout << "Hello" << endl;
    cout << "Please enter first complex number" << endl;
    complexNumber z1 = createComplexNumber();
    cout << "Please enter second complex number" << endl;
    complexNumber z2 = createComplexNumber();

    cout << "Sum = ";
    display(add(z1, z2));
    cout << endl;

    cout << "Difference = ";
    display(subtract(z1, z2));
    cout << endl;

    cout << "Product = ";
    display(multiply(z1, z2));
    cout << endl;

    cout << "Quotient = ";
    display(divide(z1, z2));
    cout << endl;

    cout << endl;
    return 0;
}
