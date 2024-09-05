#include <iostream>
using namespace std;

class Shape {	// Base class with a virtual function
public:
    virtual void area() {
        cout << "Calculating area of shape..." << endl;
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void area() {
        cout << "Rectangle area: " << length * width << endl;
    }
};

int main() {
    Shape* shape;  // Base class pointer
    Rectangle rectangle(4.4, 6.5);  // Derived class object Rectangle

    // Runtime polymorphism using base class pointer
    shape = &rectangle;
    shape->area();  // Calls Rectangle's area

    return 0;
}

