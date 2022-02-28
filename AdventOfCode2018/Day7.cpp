#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string input = "Inputs/Day7_input.txt";

/*

    Thought process:
    - Process one, go back to root and find next to process.
    - Find all available.

    Steps:
        1) Find all available at beginning.
        2) Process smallest value (inorder)
        3) Add all next to visible if it can be seen
            - Use .can_enter() method.
        4) Repeat 2-3 until complete.

    

    AHHH the issue I'm running into is just a lack of understanding
    with memory. I'm overwriting specific parts of memory, which
    is causing bugs. I'll probably read a bit and look back at it tomorrow.
*/

class Checkpoint {
    public:
        bool seen;
        char letter;
        vector<Checkpoint*> next;
        vector<Checkpoint*> prev;

        Checkpoint(char letter) {
            this->letter = letter;
        };

        void add_next(Checkpoint *point) {
            next.push_back(point);
        };

        void add_prev(Checkpoint *point) {
            prev.push_back(point);
        };

        bool can_enter() {
            // cout << prev.size() << endl;

            // for (Checkpoint *c : prev) {
            //     if (c.seen == false) {
            //         return false;
            //     }
            // }
            return true;
        };  

        bool isRoot() {
            return prev.size() == 0;
        };

        void print() {
            cout << "PRINTING STATS FOR LETTER: " << letter << endl;
            cout << "CONNECTIONS: " << endl;
            for (Checkpoint *c : next) {
                cout << c->letter << ' ';
            }
            cout << endl;
        }
};

string Day7P1() {
    string output = "";
    string line;
    ifstream file(input);
    unordered_map<char, Checkpoint> points;

    while (getline(file, line)) {
        string temp;
        char enter, exit;

        stringstream ss(line);

        ss >> temp >> enter >> temp >> temp >> temp >> temp >> temp  >> exit;

        // create origin point if not already created
        if (points.find(enter) == points.end()) {
            Checkpoint c(enter);
            points.insert(pair<char, Checkpoint>(enter, c));
        }

        // create transition point if not already created
        if (points.find(exit) == points.end()) {
            Checkpoint c(exit);
            points.insert(pair<char, Checkpoint>(exit, c));
        }

        Checkpoint c1 = points.find(enter)->second;
        Checkpoint c2 = points.find(exit)->second;

        c1.add_next(&c2);
        c2.add_prev(&c1);


        for (Checkpoint *cp : c1.next) {
            cout << cp->letter << endl;
            cout << cp->prev.size() << endl;
        }
    }

    return output;

    // vector<char> available;

    // for (auto elem = points.begin(); elem != points.end(); elem++) {
    //     if (elem->second->isRoot() == true) {
    //         available.push_back(elem->first);
    //     }
    // }

    // sort(available.begin(), available.end());

    // cout << "ROOTS: " << endl;
    // for (char c : available) {
    //     cout << c << ' ';
    // }
    // cout << endl;

    // while (available.size() > 0) {
    //     // remove smallest
    //     char c = available.at(0);
    //     available.erase(available.begin());

    //     cout << "PROCESSING " << c << endl;

    //     Checkpoint *p = points.find(c)->second;
    //     p->seen = true;

    //     for (Checkpoint *cp : p->next) {
    //         cout << cp->letter << endl;
    //         cout << cp->prev.size() << endl;
    //         if (cp->can_enter() == true) {
    //             available.push_back(cp->letter);
    //         }
    //     }

    //     sort(available.begin(), available.end());

    //     for (char c : available) {
    //         cout << c << ' ';
    //     }
    //     cout << endl;

    // }

    // while (available.size() > 0) {

    //     // remove lowest
    //     char c = available.at(0);
    //     available.erase(available.begin());

    //     cout << "PROCESSING: " << c << endl;

    //     Checkpoint p = points.find(c)->second;
    //     p.seen = true;

    //     cout << p.next.size() << endl;
    //     cout << p.next.at(0).prev.size() << endl;

    //     for (Checkpoint *cp : p.next) {

    //         if (cp->can_enter() == true) {
    //             available.push_back(cp->letter);
    //         }
    //     }

    //     return output;

    //     // sort(available.begin(), available.end());

    //     // for (char c : available) {
    //     //     cout << c << ' ';
    //     // }
    //     // cout << endl;
    // }

    return output;
}

int main() {
    cout << Day7P1() << endl;
    return 0;
}