#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <fstream>

using namespace std;

const int defaultBufSize = 20;

int myless(int argc, char* argv[]) {

    struct termios oldt, newt;

    if (argc == 1) {
        cout << argv[0] << ": command not found" << endl;
        cout << "Try:" << endl;
        cout << "   myless 'filename' to start reading from file" << endl;
        cout << "   --help to see command options" << endl;
        return 0;
    }

    if (strcmp(argv[1], "--help") == 0) {
        cout << "Available options:" << endl;
        cout << "   -s : sets the number of output lines \n\tDefault number of output lines is 5\n\tMax number is 24" << endl;
        cout << "   -c : clears screen after each output" << endl;
        cout << "   -d : prints a dividing line after each output" << endl;
        return 0;
    }

    ifstream inFile(argv[1]);

    int readBuf = defaultBufSize;
    bool clearScreenFlag = false;
    bool divideFlag = false;

    if (argc > 2) {
        for (int i = 2; i < argc; ++i) {

        // -s option
        if (strcmp(argv[i], "-s") == 0) {

            string optionArg(argv[i + 1]);
            ++i;

            if ((optionArg.length() == 1) && (optionArg[0] - '0' > 0) && (optionArg[0] - '0' < 10)) {
                readBuf = optionArg[0] - '0';
            } else if ((optionArg.length() == 2) && (optionArg[0] - '0' > 0) && (optionArg[0] - '0' < 3)
                       && (optionArg[1] - '0' >= 0) && (optionArg[1] - '0' < 5)) {
                readBuf = (optionArg[0] - '0') * 10 + (optionArg[1] - '0');
            }
            else {
                cout << argv[0] << " : buffer overflow error: max size is 24" << endl;
                return 0;
            }
        }

        // -c option
        else if (strcmp(argv[i], "-c") == 0) {
            clearScreenFlag = true;
        }

        // -d option
        else if (strcmp(argv[i], "-d") == 0) {
            divideFlag = true;
        }

        // unknown option
        else {
            cout << argv[0] << ": Unknown option " << argv[i] << endl;
            return 0;
        }
        }
    }

    if (!inFile) {
        cout << argv[0] << ": an error occured while opening file " << argv[1] << endl;
        return 0;
    }

    char ch;
    int end;
    while (true) {
        for (int i = 0; i < readBuf; i++) {
            while ((ch = inFile.get()) != '\n') {
                if (ch == EOF) {
                    inFile.close();
                    return 0;
                }
                cout.put(ch);
            }
            cout.put('\n');
        }

        tcgetattr( STDIN_FILENO, &oldt );
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt );

        if (divideFlag) cout << "----------" << endl;

        end = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

        if (clearScreenFlag) cout << "\033c" << endl;
    }
}
