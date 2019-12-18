#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char Base64symbol(unsigned char b) {
    b &= 0x3F; // Получаем 6-битный символ
    if (b < 26) return 'A' + b;
    else if (b < 52) return 'a' + (b - 26);
    else if (b < 62) return '0' + (b - 52);
    else if (b == 62) return '+';
    else return '/';
}

int utf8symbol(unsigned char b) {
    if (b >= '0' && b <= '9') return b - '0';
    else if (b >= 'a' && b <= 'z') return b - 'a' + 10;
    else if (b >= 'A' && b <= 'Z') return b - 'A' + 36;
    else if (b == '+') return 62;
    else if (b == '/') return 63;
    else return '\0';
}

int EncodeToBase64(char* inStr, int len, char* outStr) {
   int j = 0;
   unsigned char a1, a2, a3;
   unsigned char b1, b2, b3, b4;

   for (int i = 0; i < len; i += 3) {
       a1 = inStr[i];
       a2 = (i + 1 < len) ? inStr[i+1] : 0;
       a3 = (i + 2 < len) ? inStr[i+2] : 0;

       b1 = a1 >> 2;
       b2 = ((a1 & 0x3) << 4)|(a2 >> 4);
       b3 = ((a2 & 0xF) << 2)|(a3 >> 6);
       b4 = a3 & 0x3F;

       outStr[j++] = Base64symbol(b1);
       outStr[j++] = Base64symbol(b2);
       outStr[j++] = (i + 1 < len) ? Base64symbol(b3) : '=';
       outStr[j++] = (i + 2 < len) ? Base64symbol(b4) : '=';
   }

   return j;
}

int decodeFromBase64(char* inStr, int len, char* outStr){
    int j = 0;
    unsigned int b1, b2, b3, b4;
    unsigned int a1, a2, a3;

    for (int i = 0; i < len; i += 4) {
        b1 = inStr[i];
        b2 = (i + 1 < len) ? inStr[i+1] : 0;
        b3 = (i + 2 < len) ? inStr[i+2] : 0;
        b4 = (i + 3 < len) ? inStr[i+3] : 0;

        b1 = utf8symbol(b1);
        b2 = utf8symbol(b2);
        b3 = utf8symbol(b3);
        b4 = utf8symbol(b4);

        a1 = (b1 << 2) | (b2 >> 4);
        a2 = (b2 << 4) | (b3 >> 2);
        a3 = (b3 << 6) | (b4);

        outStr[j++] = a1;
        outStr[j++] = a2;
        outStr[j++] = a3;
    }

    return j;
}

void EncodeFile(ifstream& inFile, ofstream& outFile){
    char inStr[3], outStr[4];
    while (inFile.peek() != EOF) {
        inFile.read(inStr, 3);

        int s = inFile.gcount();

        s = EncodeToBase64(inStr, s, outStr);
        outFile.write(outStr, s);
    }
}

void decodeFile(ifstream& inFile, ofstream& outFile){
    char inStr[4], outStr[3];
    while (inFile.peek() != EOF) {
        inFile.read(inStr, 4);

        int s = inFile.gcount();

        s = decodeFromBase64(inStr, s, outStr);
        outFile.write(outStr, s);
    }
}

int main(int argc, char* argv[]) {

    if (argc < 4){
        cout << "Unknown command " << argv[0] << endl;
        cout << "Use " << argv[0] << " -e inputFile outputFile" << endl;
        cout << "Use " << argv[0] << " -d inputFile outputFile" << endl;
        return -1;
    }

    if (!strcmp(argv[1], "-e")) {
        ifstream inFile(argv[2], ios_base::binary);
        if (!inFile) {
            cout << "Cannot open file "  << argv[2] << endl;
            return 1;
        }

        ofstream outFile(argv[3]);
        if (!outFile) {
            cout << "Cannot open file "  << argv[3] << endl;
            inFile.close();
            return 1;
        }

        EncodeFile(inFile, outFile);
        inFile.close();
        outFile.close();
    } else if (!strcmp(argv[1], "-d")) {
        ifstream inFile(argv[2], ios_base::binary);
        if (!inFile) {
            cout << "Cannot open file "  << argv[2] << endl;

            return 1;
        }

        ofstream outFile(argv[3]);
        if (!outFile) {
            cout << "Cannot open file "  << argv[3] << endl;
            outFile.close();
            return 1;
        }

        decodeFile(inFile, outFile);
        inFile.close();
        outFile.close();
    }
    return 0;
}
