#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int Day1P1() {
    int frequency = 0;

    string line;
    ifstream file("Inputs/Day1_input.txt");

    while (getline(file, line)) {
        frequency += stoi(line);
    }

    return frequency;
}

int Day1P2() {
    set<int> freqs;
    int frequency = 0;

    while (true) {
        string line;
        ifstream file("Inputs/Day1_input.txt");

        while (getline(file, line)) {
            frequency += stoi(line);

            if (freqs.find(frequency) != freqs.end()) {
                return frequency;
            }
            freqs.insert(frequency);
        }
    }

    return -1;
}

int main() {
    cout << Day1P2() << endl;
    return 0;
}



