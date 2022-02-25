#ifndef CIRCLE_H
#define CIRCLE_H
 
class Circle {
    private:
        int radius;
    public:
        Circle(int = 1);
        float CalculateArea();
        void SetRadius(int);
};
 
#endif