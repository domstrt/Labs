#include <iostream>
#include <cmath>

using namespace std;

class Circle {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    virtual double area() {
        return M_PI * radius * radius;
    }
    void print() {
        cout << "Радиус круга: " << radius << endl;
        cout << "Площадь круга: " << area() << endl;
    }
};

class Sphere : public Circle {
public:
    Sphere(double r) : Circle(r) {}
    double area() override {
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }
    void print() {
        cout << "Радиус шара: " << radius << endl;
        cout << "Объем шара: " << area() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    Circle c(5);
    c.print();
    
    Sphere s(5);
    s.print();
    
    Circle* ptr = &s;
    ptr->print();
    
    return 0;
}
