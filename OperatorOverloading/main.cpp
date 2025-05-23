#include <iostream>
#include "MyLib.h"
/*
 * 1) The following operators cannot be overloaded:
 *      ::, :?, .*, . , and sizeof
 * 2) Overloading cannot change:
 * - Precedence and associativity
 * - Arity (binary or unary)
 * 3) Cannot overload operators for primitive types (like int or char)
 * 4) Cannot create new operators
 * 5) Operators [], (), ->, and = MUST be decalred as member methods
 * - A default = operator is always supplied by the compiler
 * - This default = operator performs shallow copy
 * 6) Other operators can be either member or global functions
 * 7) Stream insertion and extraction operators should not be member functions
 */
using namespace std;

int main()
{
    
    // Testing equality
    Mystring s1("ABC");
    Mystring s2{s1};
    
    cout << (s1 == s2) << endl;
    Mystring s3 = s1 + s2;
    s3.display();
    
    s3 = s1 + " " + s2; // This works because we have a constructor that takes char *
    s3.display();
    
    Mystring s4("Z");
    Mystring s5("AAAAA");
    
    cout << (s4 > s5) << endl; // The > operator is a global function
    
    Mystring s6 = s4 * 4;
    s6.display();
    
    cout << s6 << endl << "Enter a text: ";
    
    cin >> s6;
    
    cout << s6 << endl;
    
    /*
    // Testing unary
    Mystring s1("HELLO");
    Mystring s2 = -s1;
    s1.display();
    s2.display();
    */
    
    /*
    Mystring s1("Osameh");
    s1 = "Changed"; // Calls Move assignment
    Mystring s2("Kofahi");
    s2 = s1; // Calls copy assignment
     */
     
//    Mystring s("Osameh");
//    s.display();
//    Mystring e{s};    
//    e.display();
//    {
//        Mystring a("AAA");
//        a.display();
//        a = s;
//        a.display();    
//    }
//    s.display();
//    s = "Kofahi";
//    s.display();
    return 0;
}