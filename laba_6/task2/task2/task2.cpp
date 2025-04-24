#define _USE_MATH_DEFINES    
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Figure {
public:
    virtual double area() const = 0;
    virtual void input() = 0;
    virtual void show() const = 0;
    virtual ~Figure() {
        cout << "Figure object destroyed\n";
    }
};

class Rectangle : public Figure {
    double width, height;
public:
    Rectangle() : width(0), height(0) {
        cout << "Rectangle object created\n";
    }
    void input() override {
        cout << "Enter the width and height of the rectangle: ";
        cin >> width >> height;
    }
    double area() const override {
        return width * height;
    }
    void show() const override {
        cout << "Rectangle: area = " << area() << "\n";
    }
    ~Rectangle() override {
        cout << "Rectangle object destroyed\n";
    }
};

class Circle : public Figure {
    double radius;
public:
    Circle() : radius(0) {
        cout << "Circle object created\n";
    }
    void input() override {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }
    double area() const override {
        return M_PI * radius * radius;
    }
    void show() const override {
        cout << "Circle: area = " << area() << "\n";
    }
    ~Circle() override {
        cout << "Circle object destroyed\n";
    }
};

class RightTriangle : public Figure {
    double base, height;
public:
    RightTriangle() : base(0), height(0) {
        cout << "RightTriangle object created\n";
    }
    void input() override {
        cout << "Enter the base and height of the right triangle: ";
        cin >> base >> height;
    }
    double area() const override {
        return 0.5 * base * height;
    }
    void show() const override {
        cout << "Right Triangle: area = " << area() << "\n";
    }
    ~RightTriangle() override {
        cout << "RightTriangle object destroyed\n";
    }
};

class Trapezoid : public Figure {
    double base1, base2, height;
public:
    Trapezoid() : base1(0), base2(0), height(0) {
        cout << "Trapezoid object created\n";
    }
    void input() override {
        cout << "Enter the bases and height of the trapezoid: ";
        cin >> base1 >> base2 >> height;
    }
    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }
    void show() const override {
        cout << "Trapezoid: area = " << area() << "\n";
    }
    ~Trapezoid() override {
        cout << "Trapezoid object destroyed\n";
    }
};

int main() {
    vector<Figure*> figures;
    figures.reserve(4);

    figures.push_back(new Rectangle());
    figures.push_back(new Circle());
    figures.push_back(new RightTriangle());
    figures.push_back(new Trapezoid());

    for (auto f : figures) {
        f->input();
        f->show();
    }

    for (auto f : figures) delete f;
    return 0;
}
