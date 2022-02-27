#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string input = "Inputs/Day3_input.txt";

int Day3P1() {
    string line;
    ifstream file(input);

    int size = 1000;
    char grid[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = '.';
        }
    }

    int x_spots = 0;

    while (getline(file, line)) {
        int id, x, y, width, height;
        char sep;
        string temp;

        cout << line << endl;
        stringstream ss(line);

        ss >> sep >> id >> temp >> x >> sep >> y >> sep >> width >> sep >> height;

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                int xo = x + i;
                int yo = y + j;

                if (grid[xo][yo] == '.') {
                    grid[xo][yo] = '#';
                } else if (grid[xo][yo] == '#') {
                    grid[xo][yo] = 'X';
                    x_spots++;
                }
            }
        }
    }


    return x_spots;
}

int Day3P2() {
       string line;
    ifstream file(input);

    int size = 1000;
    char grid[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = '.';
        }
    }

    int x_spots = 0;

    while (getline(file, line)) {
        int id, x, y, width, height;
        char sep;
        string temp;

        stringstream ss(line);

        ss >> sep >> id >> temp >> x >> sep >> y >> sep >> width >> sep >> height;

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                int xo = x + i;
                int yo = y + j;

                if (grid[xo][yo] == '.') {
                    grid[xo][yo] = '#';
                } else if (grid[xo][yo] == '#') {
                    grid[xo][yo] = 'X';
                    x_spots++;
                }
            }
        }
    }

    ifstream file2(input);

    while (getline(file2, line)) {
        int id, x, y, width, height;
        char sep;
        string temp;

        stringstream ss(line);

        ss >> sep >> id >> temp >> x >> sep >> y >> sep >> width >> sep >> height;

        bool broken = false;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                int xo = x + i;
                int yo = y + j;

                if (grid[xo][yo] != '#') {
                    broken = true;
                    break;
                }
            }

            if (broken == true) {
                break;
            }
        }

        if (broken == false) {
            return id;
        }
    }

    return -1;
}
int main() {
    cout << Day3P2() << endl;
    return 0;
}