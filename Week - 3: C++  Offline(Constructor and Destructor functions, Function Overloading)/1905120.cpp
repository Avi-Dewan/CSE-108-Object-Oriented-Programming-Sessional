#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    // x and y coordinate
    int x, y;

public:
    //Add necessary constructor(s) to initialize x and y
    Point(int a, int b) {
        x = a;
        y = b;
    }

    Point() {

    }

    //Add your set and get functions for x and y

    void setXY(int a, int b) {
        x = a;
        y = b;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }


    void print()
    {
        cout << "Coordinate: "<< x <<", " <<y <<endl;
    }
};

class Circle
{
    Point p;
    int radius;

public:
    // Add necessary constructor(s) to initialize p and radius
    Circle(int a, int b, int c) {
        p.setXY(a, b);
        radius = c;
    }

    Circle() {

    }
    // Overload “update” functions

    void update(int a, int b) {
        p.setXY(p.getX() + a, p.getY()+ b);
    }

    void update(int c) {
        radius += c;
    }


    void update(int a, int b, int c) {
        p.setXY(p.getX() + a, p.getY()+ b);
        radius += c;
    }

    void print()
    {
        cout << "Center ";
        p.print();
        cout << "Radius: " << radius << endl;
    }
};

class Line {
    Point p1, p2;

public:
    Line(int a1, int b1, int a2, int b2) {
        p1.setXY(a1, b1);
        p2.setXY(a2, b2);
    }

    Line() {

    }

    void printLength() {
        cout << "Length : " << sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2)) << endl;
    }
};



int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;
    //First update
    c.update(5, 5);
    cout << "First Update" << endl;
    // call “update” function of Circle class to increase the center’s x coordinate by 5 and y coordinate by 5;
    c.print();
    cout <<endl;
    //Second update
    c.update(6);
    cout << "Second Update" << endl;
    // call “update” function of Circle class to increase the radius by 6;
    c.print();
    cout << endl;
    //Third update
    c.update(2, 2, 2);
    cout << "Third Update" << endl;
    // call “update” function of Circle class to increase the center’s x coordinate by 2 and y coordinate by 2 and the radius by 2;
    c.print();
    cout << endl;

    //Creating a Line Object

    Line al(1, 3, 1, 2);
    cout << "Line length  Display: " << endl;

    al.printLength();

    return 0;
}
