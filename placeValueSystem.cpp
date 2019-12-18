#include <iostream>

using namespace std;

char* dec2bin(unsigned int x, char str[]) {
    int i = 0;
    do {
        str[i] = '0' + x % 2;
        ++i;
        x >>= 1;
    } while(x);
    str[i] = '\0';

    int temp;
    for (int j = 0, k = i-1; j < k; ++j, --k) {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }

    return str;
}

char* dec2hex(unsigned int x, char str[]) {
    int i = 0;
    do {
        if (x % 16 < 10) str[i] = '0' + x % 16;
        else str[i] = 'A' - 10 + x % 16;
        ++i;
        x >>= 4;
    } while(x);
    str[i] = '\0';

    int temp;
    for (int j = 0, k = i-1; j < k; ++j, --k) {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }

    return str;
}

unsigned int bin2dec (char str[]) {

    int lastIdx = 0;
    while (str[lastIdx] != '\0') {
        lastIdx++;
    }

    int result = 0;
    int curBinPower = 1;

    for (int i = lastIdx - 1; i >= 0; --i) {
        result += curBinPower * (str[i] - '0');
        curBinPower *= 2;
    }

    return result;
}

unsigned int hex2dec (char str[]) {

    int lastIdx = 0;
    while (str[lastIdx] != '\0') {
        lastIdx++;
    }

    int result = 0;
    int curHexPower = 1;

    for (int i = lastIdx - 1; i >= 0; --i) {

        if (str[i] - '0' >= 0 && str[i] - '0' < 10) result += curHexPower * (str[i] - '0');
        else result += str[i] - 'A';
        curHexPower *= 16;
    }

    return result;
}

void output (char str[]) {
    int idx = 0;
    while (str[idx] != '\0') {
        cout << str[idx++];
    }
}

int main(int argc, char *argv[]) {
    int maxSize = 128;

    char bin[maxSize];
    char hex[maxSize];

    unsigned int x;
    cout << "Decimal x = ";
    cin >> x;
    cout << endl;

    cout << "Binary " << x << " = " << dec2bin(x, bin) << endl;

    cout << "Hexadecimal " << x << " = 0x" << dec2hex(x, hex) << endl << endl;;

    cout << "Decimal ";
    output(bin);
    cout << " = " << bin2dec(bin) << endl;

    cout << "Decimal ";
    output(hex);
    cout << " = " << hex2dec(hex) << endl << endl;

    return 0;
}
