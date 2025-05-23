/*
 * Creating new classes (derived or child) from other classes (super or parent)
 * - Single inheritance (single parent) vs. multiple inheritance (multiple parents)
 * - A child is a subtype of parent ==> IS-A relationship
 * - For a HAS-A relationship we should go with composition not inheritance
 * 
 * Inheritance has an access-specifier, which can be:
 * - public: Most common
 * --------- Public members of base class remain public in derived class
 * --------- Protected members of base class remain protected in derived class
 * - private: (default)
 * --------- Public and Protected members of base class become private in derived class
 * - protected:
 * --------- Public and Protected members of base class become protected in derived class
 * --------- Note that Protected access allows derived classes to access protected base members, but they cannot be accessed
 * --------- through objects. You can think of protected access as protecting somthing within the family. So a member in the
 * --------- family can access it, but anyone outside cannot access it.
 * - private and protected inheritance establish a child class HAS-A parent class that is different from composition
 * 
 * The derived class DOES NOT inherit:
 * - Base class constructors and destructors (C11 allows this with the "using Base::Base" but there are a lot of rules)
 * - Base class assignment operator
 * - Base class friends
 * 
 * However, the derived class can invoke the base class constructors, destructor, or operator=
 * If the derived class provides copy/move constructors and operator=, it MUST call the base versions explicitly 
*/

#include <iostream>
#include "Account.h"
#include "Saving.h"
using namespace std;

int main()
{
    Saving sa1(1000, 0.04);
    Saving sa2(5000, 0.05);
    cout << sa2.get_balance() << endl;
    sa2 = sa1;
    cout << sa2.get_balance() << endl;
    
    cout << sa2 << endl;
    
    return 0;
}