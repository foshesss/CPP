#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <regex>

using namespace std;

/*
[PRACTICE]
-[proj2.cpp]---------------
    I found a bunch of Java exercises from the lower-level courses at my school,
    so I'm converting them to C++ and solving.

    factorial(int n) - [int] - returns the factorial of the argument
        n:      [int]
        @ret:   [int]

    HourGlass() - [void] - takes user inputs and creates and hourglass. O(n)
        @ret:    [null]

*/

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void HourGlass() {
    int size;
    char character;

    cout << "Enter size: ";
    cin >> size;

    cout << "Enter character: ";
    cin >> character;

   float mid = size - .5;

    for (int i = 0; i < size * 2; i++) {
        int num = (4 - ceil(abs(i - mid)));
        for (int j = 0; j < size * 2; j++) {
            if (j >= num && j <= size * 2 - 1 - num) {
                cout << character;
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

string MilitaryToRegular(int t) {
    int hour = (t / 60) % 24;
    int minutes = t % 60;
    string suffix = hour < 12 ? "am" : "pm";

    hour = hour % 12 ? hour % 12 : 12;

    char s[9];
    sprintf(s, "%02d:%02d%s\n", hour, minutes, suffix.c_str());
    return s;
}

// assume valid regular time
string RegularToMilitary(string t) {
    int hour = stoi(t.substr(0, 2));
    int minutes = stoi(t.substr(3, 2));

    hour = t.find("pm") != -1 ? 12 + hour % 12 : hour;

    char s[7];
    sprintf(s, "%02d:%02d\n", hour, minutes);
    return s;
}

int main() {
    string t = MilitaryToRegular(18 * 60 + 49);
    cout << t;
    cout << RegularToMilitary(t);

    return 0;
}