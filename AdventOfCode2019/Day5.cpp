#include <iostream>
#include <fstream>

using namespace std;

string input = "Inputs/Day5_input.txt";

string Day5P1() {
    string line;
    ifstream file(input);

    getline(file, line);

    int prev = int(line[0]);
    // previous:
    for (int i = 1; i < line.length(); i++) {
        int val = int(line[i]);

        if (abs(val - prev) == 32) {
            // remove these 2
            string sub = line.substr(i - 1, 2);
            cout << "SUBSTRING: " << sub << endl;

            line = line.substr(0, i - 1) + line.substr(i + 2, line.length());

            cout << line << endl;
            prev = -5000;
            continue;
        }

        prev = val;
    }

    return line;
}

int main() {
    cout << Day5P1() << endl;
    return 0;
}