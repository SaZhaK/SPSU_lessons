#include <iostream>>

using namespace std;

template <typename T>
void print (const T* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void powers() {
    cout << "Hello" << endl;
    cout << "Please, enter the number N: ";
    int N;
    cin >> N;
    int* twoPowers = new int[N];

    int curPower = 1;
    for (int i = 0; i < N; ++i){
        twoPowers[i] = 2 * curPower;
        curPower *= 2;
    }

    cout << "The powers of 2 are: " << endl;
    print(twoPowers, N);
}

void arithmeticalProgresion() {
    int N, A, D;
    cout << "Hello" << endl;
    cout << "Please, enter the number N: ";
    cin >> N;
    cout << "Please, enter the number A: ";
    cin >> A;
    cout << "Please, enter the number D: ";
    cin >> D;

    int* progressionElements = new int[N];

    int counter = 0;
    for (int i = 0; i < N; ++i) {
        progressionElements[i] = A + D * counter++;
    }

    cout << "The elements of progression are: " << endl;
    print(progressionElements, N);
}

void geometriaclProgresion() {
    int N, A, D;
    cout << "Hello" << endl;
    cout << "Please, enter the number N: ";
    cin >> N;
    cout << "Please, enter the number A: ";
    cin >> A;
    cout << "Please, enter the number D: ";
    cin >> D;

    int* progressionElements = new int[N];

    int curD = 1;

    progressionElements[0] = A;
    for (int i = 1; i < N; ++i) {
        curD *= D;
        progressionElements[i] = A * curD;
    }

    cout << "The elements of progression are: " << endl;
    print(progressionElements, N);
}

void fibonachi () {
    cout << "Hello" << endl;
    cout << "Please, enter the number N: ";
    int N;
    cin >> N;

    int* fibonachiElements = new int[N];
    fibonachiElements[0] = 1;
    fibonachiElements[1] = 1;

    for (int i = 2; i < N; ++i) {
        fibonachiElements[i] = fibonachiElements[i-1] + fibonachiElements[i-2];
    }

    cout << "The elements of Fibonachi sequence are: " << endl;
    print(fibonachiElements, N);
}

void sum () {
    int N, A, B;
    cout << "Hello" << endl;
    cout << "Please, enter the number N: ";
    cin >> N;
    cout << "Please, enter the number A: ";
    cin >> A;
    cout << "Please, enter the number B: ";
    cin >> B;

    int* elements = new int[N];
    elements[0] = A;
    elements[1] = B;

    int curSum = A + B;
    for (int i = 2; i < N; ++i) {
        elements[i] = curSum;
        curSum += elements[i];
    }

    cout << "The elements of sequence are: " << endl;
    print(elements, N);
}

int sequences() {

    //powers();

    //arithmeticalProgresion();

    //geometriaclProgresion();

    //fibonachi()

    //sum();

    return 0;
}
