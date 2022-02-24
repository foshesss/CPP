#include <iostream>
#include "Circle.h"

using namespace std;

/*
[PRACTICE]
-[cpp_proj1.cpp]---------------
    This is sort of my introduction to C++. To be honest, I am only
    really learning because I know it's a super useful language, but alsooo
    I saw that you can embed Lua into it, which looks super interesting.

[MAIN]:
    The main method of this file currently creates a Circle object, sets the radius, and
    then prints the radius.
*/

int main() {
    Circle c;
    cout << c.CalculateArea() << '\n';

    Circle d(10);
    cout << d.CalculateArea() << '\n';

    cout << c.CalculateArea() << '\n';
}

// Legacy Code (no longer used):

// int add(int a, int b) {
//     return a + b;
// }

// class Circle {
//     int radius;
//     public:
//         void set_radius(int);
//         float area() {
//             return PI * pow(radius, 2.0);
//         }
// };

// void Circle::set_radius(int r) {
//     radius = r;
// }