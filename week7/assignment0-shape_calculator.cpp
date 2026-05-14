#include <iostream>
#include <iomanip>
using namespace std;

// Class Rectangle
class Rectangle {
private:
    double length;
    double width;

public:
    // constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // getters
    double getLength() const {return length;}
    double getWidth() const {return width;}

    // setters
    void setLength(double l);    
    void setWidth(double w);
    
    // Overloaded methods
    double area() const;
    void area(double& result) const;

    // resize with method chaining
    Rectangle& resize(double factor); 
};

// Rectangle methods defined outside class
void Rectangle::setLength(double l) {
    if (l > 0) {
        length = l;
    }
}

void Rectangle::setWidth(double w) {
    if (w > 0) {
        width = w;
    }
}

double Rectangle::area() const {
    return length * width;
}

void Rectangle::area(double& result) const {
    result = length * width;
}

Rectangle& Rectangle::resize(double factor) {
    this->length *= factor;
    this->width *= factor;

    return *this;
}

// Class Circle
class Circle {
private:
    double radius;
    const double PI = 3.14159;

public:
    // Constructor
    Circle (double r) : radius(r) {}

    // getters
    double getRadius() const {
        return radius;
    }

    // Setters 
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        }
    }
    
    // const methods
    double area() const; 
    double circumference() const;

    // print circle basic info
    void print() const; 
    
    // overloaded print
    void print(bool detailed) const;

};

// Circle methods defined outside class
double Circle::area() const {
    return PI * radius * radius;
}

double Circle::circumference() const {
    return 2 * PI * radius;
}

void Circle::print() const {
    cout << "\nCircle (Radius: " << radius << ")" << endl;
    cout << "Area: " << area() << endl;
    cout << "Circumference: " << circumference() << endl;        
}

void Circle::print(bool detailed) const {

    if (!detailed) {
            print();
            return;
    }

    cout << "Circle details:" << endl;
    cout << "  Radius:          " << radius << endl;
    cout << "  Area:            pi x " << radius << "^2 = " << area() << endl;
    cout << "  Circumference:   2 x pi x " << radius << " = " << circumference() << endl;  

}
        
// Main Function
int main() {

    cout << fixed << setprecision(2);

    cout << "SHAPE CALCULATOR" << endl;
    cout << "----------------" << endl;

    // Test Rectangle
    Rectangle r(3, 4);

    // Test getters
    cout << "Rectangle (Length: " << r.getLength() << ", Width: " << r.getWidth() << ")" << endl;
   
    // Test overloaded
    cout << "Area: " << r.area() << endl;
    double referenceResult;
    r.area(referenceResult);
    cout << "Area via reference: " << referenceResult << endl;
    
    // Test setters
    r.setLength(10);
    r.setWidth(6);

    cout << "\nAfter setters:" <<endl;
    cout << "Length: " << r.getLength() << ", Width: " << r.getWidth() << endl;
    
    // Test Method chaining
    cout << "\nMethod chaining:" << endl;
    cout << "  Original:   Length = " << r.getLength() << ", Width = " << r.getWidth() << endl;

    r.resize(2.0);

    cout << "  After resize(2.0): Length = " << r.getLength() << ", Width = " << r.getWidth() << endl;

    // Test Circle
    Circle c(5);
    
    // Test overloded
    c.print();
    cout << endl;

    c.print(true);
    cout << endl;

    // Test getter
    cout << "Testing getter:" << endl;
    cout << "Radius is: " << c.getRadius() << endl;

    // Test setter
    cout <<"\nTesting setter:" << endl;
    c.setRadius(7);
    cout << "After setRadius(7): " << c.getRadius() << endl;
    cout << "New Area: " << c.area() << endl;
    cout << "New circumference: " << c.circumference() << endl;

    
    //Test Const Object
    const Circle constCircle(2);

    cout << "\nConst object test(2):" << endl;

    cout << "  Area: " << constCircle.area() << endl;
    cout << "  Circumference: " << constCircle.circumference() << endl;
    
    return 0;

}
