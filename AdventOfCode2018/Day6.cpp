#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string input = "Inputs/Day6_input.txt";

class Point {

    public:
        pair<int, int> coord;
        int id;
        int area;

        Point(int id, pair<int, int> p) {
            this->id = id;
            coord = p;
            area = 0;
        };

        int get_distance(int x, int y) {
            int x_dist = abs(coord.first - x);
            int y_dist = abs(coord.second -  y);

            return x_dist + y_dist;
        };

        void inc_area() {
            area++;
        };

        void print() {
            cout << "Point #" << id << ';' << endl;
            cout << "Coordinates: (" << coord.first << ',' << coord.second << ')' << endl;
            cout << "Area: " << area << endl;
        }
};

int Day6P1() {
    int startX = 0;
    int startY = 0;
    int endX = 0;
    int endY = 0;

    string line;
    ifstream file(input);

    vector<Point> points;

    bool set_start = false;

    while (getline(file, line)) {
        int x, y;
        char temp;

        stringstream ss(line);

        ss >> x >> temp >> y;

        Point p(points.size(), pair<int, int>(x, y));
        points.push_back(p);

        if (set_start == false) {
            set_start = true;
            startX = x;
            startY = y;
        } else {
            startX = startX > x ? x : startX;
            startY = startY > y ? y : startY;
        }

        endX = endX < x ? x : endX;
        endY = endY < y ? y : endY;
    }

    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            bool set = false;
            int dist = 0;
            int id;
            bool tied = false;

            for (Point p : points) {
                int curr_d = p.get_distance(i, j);

                if (set == false) {
                    set = true;
                    dist = curr_d;
                    id = p.id;
                } else if (curr_d < dist) {
                    dist = curr_d;
                    id = p.id;
                    tied = false;
                } else if (curr_d == dist) {
                    tied = true;
                }
            }

            if (tied == false) {
                Point &temp = points.at(id);

                if (i == startX || i == endX || j == startY || j == endY) {
                    temp.area = -9001;
                } else {
                    temp.inc_area();
                }  
            }
        }
    } 

    int largest_area = 0;

    for (Point &t : points) {
        t.print();
        if (t.area <= 0) { continue; }
        int area = t.area;

        if (largest_area == 0 || largest_area < area) {
            largest_area = area;
        }
    }

    return largest_area;
}

int Day6P2() {
    string line;
    ifstream file(input);

    vector<Point> points;

    while (getline(file, line)) {
        int x, y;
        char temp;

        stringstream ss(line);

        ss >> x >> temp >> y;

        Point p(points.size(), pair<int, int>(x, y));
        points.push_back(p);
    }

    int area = 0;
    int size = 10000;
    int threshold = 10000;

    // O(n^3)
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int dist = 0;

            for (Point p : points) {
                dist += p.get_distance(i, j);

                if (dist >= threshold) {
                    break;
                }
            }

            if (dist < threshold) {
                area++;
            }
        }
    }

    return area;
}

int main() {
    cout << Day6P2() << endl;
    return 0;
}