#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cout << "Requires 3 arguments at least" << endl;
        return 0;
    } else {

        ofstream outFile(argv[argc-1], ios_base::binary);
        if (!outFile) {
            cout << "Can not open file" << argv[argc-1]<< endl;
            return 1;
        }

        ifstream inFile;

        for (int i = 1; i < argc - 1; ++i) {
            inFile.open(argv[i]);
            if (!inFile) {
                cout << "Can not open file " << argv[i] << endl;
                return 1;
            }

            int cnt = 0;
            int ch;
            while ((ch = inFile.get()) != EOF) {
                outFile.put(ch);
                ++cnt;
            }

            inFile.close();
        }

        outFile.close();
    }

    return 0;
}
