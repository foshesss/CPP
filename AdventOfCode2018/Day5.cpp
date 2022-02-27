#include <iostream>
#include <fstream>

using namespace std;

string input = "Inputs/Day5_input.txt";

int Day5P1() {
    string line;
    ifstream file(input);

    getline(file, line);

    int prev = int(line[0]);
    int i = 0;
    while (i != line.length()) {
        int val = int(line[i]);

        if (abs(val - prev) == 32) {
            string sub = line.substr(i - 1, 2);
            line = line.substr(0, i - 1) + line.substr(i + 1);

            i -= 2;
            prev = int(line[i]);
            continue;
        }

        prev = val;
        i++;
    }

    return line.length();
}

int main() {
    cout << Day5P1() << endl;
    return 0;
}