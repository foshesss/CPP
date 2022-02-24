#include <iostream>
#include <cmath>

using namespace std;

/*
-[cpp_proj1.cpp]---------------
    This is sort of my introduction to C++. To be honest, I am only
    really learning because I know it's a super useful language, but alsooo
    I saw that you can embed Lua into it, which looks super interesting.

[OBJECT][Circle]:
    [Members]:
        radius          [int]

    [Methods]:
        set_radius      [void]
            r:          [int]
            @ret:       null

        area()          [float]
            @ret:       radius of circle based on 'radius'

[MAIN]:
    The main method of this file currently creates a Circle object, sets the radius, and
    then prints the radius.
*/

#define PI 3.14159

class Circle {
    int radius;

    public:
        void set_radius(int);
        float area() {
            return PI * pow(radius, 2.0);
        }
};

void Circle::set_radius(int r) {
    radius = r;
}

int main() {
    Circle c;
    c.set_radius(10);

    cout << "(C) Area: " << c.area() << '\n';

    Circle d;
    d.set_radius(7);

    cout << "(C) Area: " << c.area() << '\n';
    cout << "(D) Area: " << d.area() << '\n';
}

// Legacy Code (no longer used):

// int add(int a, int b) {
//     return a + b;
// }