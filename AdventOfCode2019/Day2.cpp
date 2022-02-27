#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string input = "Inputs/Day2_input.txt";

int Day2P1() {
    int num_twos = 0;
    int num_threes = 0;

    string line;
    ifstream file(input);

    while (getline(file, line)) {
        unordered_map<char, int> um;

        for (int i = 0; i < line.length(); i++) {
            char c = line[i];

            auto elm = um.find(c);

            if (elm == um.end()) {
                um.insert(pair<char, int>(c, 1));
            } else {
                elm->second = elm->second + 1;
            }
        }

        bool found_two = false;
        bool found_three = false;

        for (auto& elm : um) {
            if (elm.second == 2) {
                found_two = true;
            } else if (elm.second == 3) {
                found_three = true;
            }
        }

        num_twos = found_two == true ? num_twos + 1 : num_twos;
        num_threes = found_three == true ? num_threes + 1 : num_threes;
    }

    return num_twos * num_threes;
}

string close_enough(string s1, string s2) {
    bool one_mistake = false;
    string ret = "";

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) {
            ret += s1[i];
        } else {
            if (one_mistake == true) {
                return ret;
            }
            one_mistake = true;
        }
    }

    return ret;
}

string Day2P2() {
    string line;
    ifstream file(input);

    vector<string> lines;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {
        for (int j = i + 1; j < lines.size(); j++) {
            string s = close_enough(lines.at(i), lines.at(j));

            if (s.length() == lines.at(i).length() - 1) {
                return s;
            }
        }
    }

    return line;
}

int main() {
    cout << Day2P2() << endl;
    return 0;
}