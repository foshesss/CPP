#include <iostream>

using namespace std;

/*
[Project4]

-[proj4.cpp]---------------
    It has become very apparent that it is EXTREMELY difficult to
    work with subclasses, superclasses, etc. I think it's just that I'm not
    used to it, but I am going to try again with this example. The classes
    I intend to set out to make are simple Shape classes.

[HIERARCHY]:
    Shape:
        -> Triangle
        -> Circle
        -> Square

*/

#define PI 3.1415

// Shape super class:
class Shape {
    private:
        string color;
    public:
        Shape(string color) {
            this->color = color;
        };

        virtual float area() {
            cout << "UNIMPLEMENTED - default value - ";
            return 1;
        };

        virtual void print_info() {
            cout << "Color: " << this->color << '\n';
        };
};

class Square : public Shape {
    private:
        int width;
        int length;

    public:
        Square(string color, int width, int length) : Shape(color) {
            this->width = width;
            this->length = length;
        };

        float area() {
            return this->width*this->length;
        }; 

        void print_info() {
            Shape::print_info();
            cout << "Width: " << this->width << '\n';
            cout << "Length: " << this->length << '\n';
            cout << "Area: " << Square::area() << '\n';
        }
};

class Circle : public Shape {
    private:
        int radius;

    public:
        Circle(string color, int radius) : Shape(color) {
            this->radius = radius;
        };

        float area() {
            return PI * radius * radius;
        };

        void print_info() {
             Shape::print_info();
             cout << "Radius: " << this->radius << '\n';
             cout << "Area: " << Circle::area() << '\n';
        }
};

int main() {
    Square s("yellow", 5, 6);
    Circle c("red", 5);

    s.print_info();
    cout << "------\n";
    c.print_info();

    return 0;
}