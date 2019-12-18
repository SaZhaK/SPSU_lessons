#include <iostream>
#include <fstream>

using namespace std;
int  main(int argc, char* argv[]) {

    if(argc < 3) {
        cout << "Error: You have to enter at least 3 arguments:" << endl;
        cout << "N, K, output file" << endl;
        return 1;
    }

    int N = stoi(argv[1]);
    int K = stoi(argv[2]);

    ofstream outFile(argv[3]);
    if (!outFile) {
        cout << "Cannot open file "  << argv[3] << endl;
        return 1;
    }

    int* number = new int[N + 1];
    for (int i = 0; i < N; ++i) {
        number[i] = 0;
    }
    number[N] = 1;

    for (int i = 0; i < K; ++i) {
        int buf = 0;
        for (int j = N; j >= 0; --j) {
            if (number[j] * 2 >= 10) {
                number[j] = (number[j] * 2) % 10 + buf;
                buf = 1;
            } else {
                number[j] = number[j] * 2 + buf;
                buf = 0;
            }
        }
    }

    char* result = new char[N + 1];
    int iter = 0;

    bool firstNumber = false;
    for (int i = 1; i < N+1; ++i) {
        if (number[i] != 0) {
            firstNumber = true;
        }
        if (firstNumber) result[iter++] = number[i] + '0';
    }

    result[N] = '\n';
    outFile.write(result, N+1);
    outFile.close();
    delete[] number;
    delete[] result;

    return 0;
}
