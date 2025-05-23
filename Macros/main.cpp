/*
 * Generic Programming: 
 * Writing code that works with a variety of types as arguments,
 * as long as thise argument types meet specific syntactic and
 * semantic requirements
 * 
 * Macros: 
 * - One way to do generic programming
 * - BEWARE
 * - More relevant in C not C++
 * 
 * Function templates is another way
 * 
 * Class templates is another way
 */

#include <iostream>

// no type is associated the preprocessor will just replace MAX_SIZE with 1000
// Using constants is better
#define MAX_SIZE 100 

// The preprocessor will scan the code and whenever it finds MAX(var1, var2)
// It will replace it with ((var1 > var2)? var1 : var2)
#define MAX(a, b) ((a > b) ? a : b)

#define SQUARE(x) x*x

#define SQUARE2(x) ((x)*(x)) // a better way to do it


using namespace std;

int main()
{
    int res = 100;
    
    cout << MAX('a','b') << endl; // generic programming
    cout << MAX(11,22) << endl; // generic programming
    cout << SQUARE(5) << endl;
    res = 100/SQUARE(5); // returns 100 because 100/5 gives 25 which is them multiplied by 5 to give 100
    cout << res  << endl;
    
    res = 100/SQUARE2(5); // solves the problem
    cout << res  << endl;
    
    res = SQUARE2(MAX(6, 7)); // to see why (()*()) in the macro above
    cout << res  << endl;
    return 0;
}