#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

string input = "Inputs/Day4_input.txt";

class Guard {
    
    private:
        int minutes[60];
        int guard_num;

    public:
        Guard(int guard_num) {
            this->guard_num = guard_num;
            for (int i = 0; i < 60; i++) {
                minutes[i] = 0;
            }
        };

        void addToRange(int low, int high) {
            for (int i = low; i < high; i++) {
                minutes[i]++;
            }
        };

        int totalMinutesAsleep() {
            int total = 0;

            for (int i = 0; i < 60; i++) {
                total += minutes[i];
            }

            return total;
        };

        pair<int, int> getMostAsleep() {
            int min = 0;
            int largest = 0;

            for (int i = 0; i < 60; i++) {
                if (minutes[i] > largest) {
                    min = i;
                    largest = minutes[i];
                }
            }

            // return (minute, times_asleep)
            return pair<int, int>(min, largest);
        };
};

int Day4P1() {
    string line;
    ifstream f(input);
    vector<string> lines;

    while (getline(f, line)) {
        lines.push_back(line);
    }

    // sort input
    sort(lines.begin(), lines.end());

    // all guard info
    unordered_map<int, Guard> guards;

    int guard_num = 0;
    int last_asleep = 0;

    for (string s : lines) {
        s = s.substr(15);

        stringstream ss(s);

        string word1;
        int min;
        char temp;

        ss >> min >> temp >> word1;

        if (word1 == "Guard") {
            ss >> temp >> guard_num;
            if (guards.find(guard_num) == guards.end()) {
                Guard g(guard_num);
                guards.insert(pair<int, Guard>(guard_num, g));
            }
        } else if (word1 == "wakes") {
            guards.find(guard_num)->second.addToRange(last_asleep, min);
            last_asleep = 0;
        } else if (word1 == "falls") {
            last_asleep = min;
        }
    }
    
    int guard = 0;
    int total_minutes = 0;
    int largest = 0;
    int min = 0;

    for (auto elem : guards) {
        Guard g = elem.second;
        int t_min = g.totalMinutesAsleep();

        if (t_min < total_minutes) {
            continue;
        }

        pair<int, int> p = g.getMostAsleep();

        if (t_min > total_minutes || p.second >= largest) {
            total_minutes = t_min;
            min = p.first; // minute most asleep
            largest = p.second; // largest most asleep
            guard = elem.first; // guard number
        }
    }

    return guard * min;
}

int Day4P2() {
    string line;
    ifstream f(input);
    vector<string> lines;

    while (getline(f, line)) {
        lines.push_back(line);
    }

    // sort input
    sort(lines.begin(), lines.end());

    // all guard info
    unordered_map<int, Guard> guards;

    int guard_num = 0;
    int last_asleep = 0;

    for (string s : lines) {
        s = s.substr(15);

        stringstream ss(s);

        string word1;
        int min;
        char temp;

        ss >> min >> temp >> word1;

        if (word1 == "Guard") {
            ss >> temp >> guard_num;
            if (guards.find(guard_num) == guards.end()) {
                Guard g(guard_num);
                guards.insert(pair<int, Guard>(guard_num, g));
            }
        } else if (word1 == "wakes") {
            guards.find(guard_num)->second.addToRange(last_asleep, min);
            last_asleep = 0;
        } else if (word1 == "falls") {
            last_asleep = min;
        }
    }
    
    int guard = 0;
    int largest = 0;
    int min = 0;

    for (auto elem : guards) {
        Guard g = elem.second;

        pair<int, int> p = g.getMostAsleep();

        if (p.second >= largest) {
            min = p.first; // minute most asleep
            largest = p.second; // largest most asleep
            guard = elem.first; // guard number
        }
    }

    return guard * min;
}

int main() {
    cout << Day4P2() << endl;
    return 0;
}