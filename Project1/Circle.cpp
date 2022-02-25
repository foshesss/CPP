#include "Circle.h"
#include <cmath>

/*
[PRACTICE]
-[Circle.cpp]---------------
    This class is used to create Circles and calculate all relevant information
    to them.

[OBJECT][Circle]:
    [Members]:
        _radius          [int]

    [Methods]:
        Circle::Circle(int radius) - [Circle] - constructor method
            radius:     [int] - [OPTIONAL] - Default value = 1
            @ret:       [Circle]

        Circle::SetRadius(int radius) - [void]
            radius:     [int]
            @ret:       null

        Circle::CalculateArea() - [float] - pi * radius^2
            @ret:       [float]
*/

#define PI 3.14159

Circle::Circle(int radius) {
    Circle::SetRadius(radius);
}

void Circle::SetRadius(int radius) {
    this->radius = radius;
}

float Circle::CalculateArea() {
    return pow(this->radius, 2) * PI;
}