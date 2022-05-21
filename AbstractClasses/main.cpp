/*
 * Abstract classes cannot be instantiated
 * 
 * They can only be inherited from
 * 
 * For a class to be an Abstract Class it must have at least one PURE VIRTUAL function
 * 
 * Alternatively, a PURE VIRTUAL function is a function used to make a class abstract
 * - It is specified by "=0" after the prototype
 * - No implementation is provided
 * 
 * When a class is derived from an abstract class, it MUST define OVERRIDE ALL PURE VIRTUAL functions to be concerete
 * - Otherwise, the derrived class will still be Abstract
 * 
 * Abstract Classes can be used to force the user to implement an INTERFACE
 */

#include <iostream>

using namespace std;

class Shape {
public:
    Shape() {cout << "Shape Constructor\n";}
    virtual void draw() = 0; // PURE VIRTUAL FUNCTION
    virtual void rotate() = 0; // same
    virtual ~Shape() {cout << "Shape destructor\n";}
  
};

// Still an abstract class because it does not implement the PURE VIRTUAL Functions in Shape
class Line : public Shape {
public:
    double get_length() {return 0;}    
};

class Square : public Shape {
public:
    Square() {cout << "Square Constructor\n";}
    virtual void draw() {cout << "Drawing Square\n";}
    virtual void rotate() {cout << "Rotating Square\n";}
    ~Square() {cout << "Square Destructor\n";}
};

int main()
{
    //Shape sh; // ERROR
    //Line l; // ERROR this is an abstract class too
    Square s;
    s.draw();
    
    Shape * s2 = new Square(); // We can define Shape pointers
    
    s2->rotate(); // dynamically bound to sqaure
    
    delete s2;
    return 0;
}