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

int Day5P2() {
    string line;
    ifstream file(input);

    getline(file, line);

    int smallest = 0;

    for (int _ = 65; _ < 97; _++) {
        string n = "";

        for (int j = 0; j < line.length(); j++) {
            int val = int(line[j]);

            if (val != _ && val - 32 != _) {
                n += line[j];
            }
        }

        int prev = int(n[0]);
        int i = 0;

        while (i != n.length()) {
            int val = int(n[i]);

            if (abs(val - prev) == 32) {
                string sub = n.substr(i - 1, 2);
                n = n.substr(0, i - 1) + n.substr(i + 1);

                i -= 2;
                prev = int(n[i]);
                continue;
            }

            prev = val;
            i++;
        }

        int len = n.length();

        if (smallest == 0 || len < smallest) {
            smallest = len;
        }
    }

    return smallest;
}

int main() {
    cout << Day5P2() << endl;
    return 0;
}