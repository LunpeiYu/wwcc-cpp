#include <iostream>   // For input/output
#include <cmath>      // For sqrt() function
using namespace std;

// Function calculate distance between two points
double calculateDistance(double x1, double y1, double x2, double y2) {
    // Calculate differences in x and y coordinates
    double dx = x2 - x1;
    double dy = y2 - y1;

    // Apply distance formula
    double distance = sqrt(dx * dx + dy * dy);

    return distance;
}

// Fumction calculate midpoint between two points
void calculateMidpoint(double x1, double y1, double x2, double y2, double &mx, double &my){
    // Midpoint formula
    mx = (x1 + x2) / 2;
    my = (y1 + y2) / 2;
}

int main() {
    double x1, y1, x2, y2;

    // Enter first point
    cout << "Enter the coordinates of the first point:" <<endl;
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;

    // Enter second point
    cout << "Enter the coordinates of the second point:" << endl;
    cout << "x2:";
    cin >> x2;
    cout << "y2:";
    cin >> y2;

    // Call the function calculate distance
    double distance = calculateDistance(x1, y1, x2, y2);

    // Output distance result
    cout << "The distance between (" << x1 << "," << y1 << ") and (" << x2 <<"," << y2<< ") is: " << distance << endl;

    // Calculate midpoint
    double mx, my;
    calculateMidpoint(x1, y1, x2, y2, mx, my);

    // Output midpoint result
    cout << "The midpoint is: (" << mx << "," << my << ")" << endl;

    return 0;
}

