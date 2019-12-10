#include <iostream>
#include <fstream>

using namespace std;

int justify(int argc, char* argv[]) {

    int n;

    if (argc < 2) {
        cout << "Unknown command " << argv[0] << endl;
        return 1;
    }
    else if (argc == 2) n = 80;
    else if (argc == 3) {
        string optionArg(argv[2]);

        if ((optionArg.length() == 1) && (optionArg[0] - '0' > 0) && (optionArg[0] - '0' < 10)) {
            n = optionArg[0] - '0';
        } else if ((optionArg.length() == 2) && (optionArg[0] - '0' > 0) && (optionArg[0] - '0' < 10)
                   && (optionArg[1] - '0' >= 0) && (optionArg[1] - '0' < 10)) {
            n = (optionArg[0] - '0') * 10 + (optionArg[1] - '0');
        }
        else {
            cout << argv[0] << " : buffer overflow error: max size is 99" << endl;
            return 1;
        }
    }
    else {
        cout << "Too many arguments" << endl << "Limit is 3" << endl;
        return 1;
    }


    fstream file(argv[1]);
    if (!file) {
        cout << "Can not open file" << argv[1]<< endl;
        return 1;
    }



    char* buff = new char[n + 1];
    while (file.peek() != EOF) {
        int iter = 0;
        int spaceCount = 0;
        int symbolCount = 0;
        int words = 0;

        file.getline(buff, n + 1);

        while (buff[iter]) {
            if(buff[iter] == ' ') ++spaceCount;
            else ++symbolCount;

            if(buff[iter - 1] == ' ' && buff[iter] != ' ' && iter != 0) ++words;

            ++iter;
        }

        int spacesRequired = n - (symbolCount + spaceCount);
        int spacesPerWord = spacesRequired / words;
        int extraSpaces = spacesRequired % words;

        iter = 0;
        while (buff[iter]) {
            cout << buff[iter];
            if (buff[iter+1] != ' ' && buff[iter] == ' '){
                for (int i = 0; i < spacesPerWord; ++i) {
                    cout << " ";
                }
                if (extraSpaces > 0) {
                    cout << " ";
                    --extraSpaces;
                }
            }
            ++iter;
        }

        cout << endl;
        }

    return 0;
}
