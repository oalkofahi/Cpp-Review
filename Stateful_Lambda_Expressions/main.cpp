/*
 * Stateful Lambdas look like:
 * 
 *              [captured variables] () ->return_type specifiers {};
 * 
 * Note that the difference is in the captured variables:
 * - variables already defined in scope
 * - No need to pass them
 * 
 * When a lambda is compiled the compiler will generate clouser for it
 * 
 * We are basically defining a constructor with parameters for the lambda
 * - The function object that will be created will have arguments now
 * 
 * All captured values cannot be modified by default
 * - const function object
 * 
 * If we want the lambda to modify the captured variables we need to use "mutable" specifier
 * 
 * In the capture list we can use the following default modifiers:
 * - [=] to capture by value by default
 * - [&] to capture by reference by default
 * - [this] capture by reference all values in the object where the lambda os defined
 * 
 */

#include <iostream>

using namespace std;

int main()
{
    int y = 10;
    
    // This lambda captures the value of y
    // capture by value (const value)
    auto l = [y](int x) {cout << x + y << endl;};
    
    l(5); // cout << 5 + 10
    
    // This way we can modify y inside the function but the original y will not be modified
    auto l2 = [y]() mutable {cout << ++y << endl;};
    
    l2();
    
    cout << y << endl;
    
    // Capture by reference
    auto l3 = [&y]() {cout << ++y << endl;};
    
    l3();
    
    cout << y << endl;
    
    return 0;
}