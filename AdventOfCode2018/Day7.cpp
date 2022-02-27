#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string input = "Inputs/Day7_input.txt";

class Checkpoint {
    public:
        bool seen;
        char letter;
        vector<Checkpoint> next;
        vector<Checkpoint> prev;

        Checkpoint(char letter) {
            this->letter = letter;
        };

        void add_next(Checkpoint point) {
            next.push_back(point);
        };

        void add_prev(Checkpoint point) {
            prev.push_back(prev);
        };

        bool can_enter() {
            for (Checkpoint &c : prev) {
                if (c.seen == false) {
                    return false;
                }
            }
            return true;
        };

        
};

// C
    // next: A, F
    // prev: null

// A
    // B, D

// B
    // E

// 

string Day7P1() {
    string output = "";
    string line;
    ifstream file(input);

    while (getline(file, line)) {
        string temp;
        char enter, exit;

        stringstream ss(line);

        ss >> temp >> enter >> temp >> temp >> temp >> temp >> temp  >> exit;
    }

    return output;
}

int main() {
    cout << Day7P1() << endl;
    return 0;
}