/*
 * Motivation:
 * Lambdas are invinted to replace function objects or function pointers
 * - Function objects were mostly used in the STL
 * - Function pointers were mostly used as callbacks
 * 
 * The problem:
 * - Usually many short functions are written to control algorithms
 * - These short functions ended up encapsulated as function objects in classes
 * - Where these functions are used could be far away from where they were defined, which could hinder modifications, maintenance, and testing
 * - compilers are not good at inlining these functions for efficiency
 * 
 * With Lambdas, the compiler creates a clouser object from the lambda expression
 * - We can gain access to the environment in which the lambda exists
 * 
 * The compiler generates unnamed function objects behind the scenes from the lambda expressions
 * 
 * The structure of a Lambda Expression:
 * 
 *          [] () -> return_type specifiers {};
 * 
 * The []:
 * - The beginning of the lambda
 * - Capture list that allows us to capture the context or the clouser
 * - Important in STATEFUL lambda expressions
 * 
 * The ():
 * - Comma-separated parameter list
 * 
 * The -> return_type:
 * - Specifies the return type
 * - Ignore if void
 * - Can be omitted and the compiler will try to figure it out
 * 
 * The specifiers:
 * - This is optional
 * - Can be: 1) mutable, or 2) constexpr
 * 
 * The {}:
 * - Contains the code
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// An example on function objects
class Multiplier {
private:
  int num{};
public:
  Multiplier(int n) : num {n} {}
  
  // Classes used to initiate function objects MUST overload the () operator
  int operator() (int n) const {
      return num * n;
  }
  
};

// Another example on function objects
template<typename T>
struct Displayer {
    // Note that we still need to overload the () operator
    void operator() (const T &data) {
        std::cout << data << " ";
  }  
};

template<typename T>
void print(const T &V) 
{
    for(const auto &e: V)
        cout << e << " ";
}

int mulby2(int x)
{
    return 2*x;
}

int main()
{
    Multiplier by2(2); // Object from Multiplier
    
    cout << by2(3) << endl; // The object is used as a function ==> Function Object
    
    vector<int> vec {1,2,3,4,5,6};
    cout << "Vec before = "; print(vec); cout << endl;
    // Using function objects to transform elements in vector
    transform(vec.begin(),vec.end(), vec.begin(), by2); 
    cout << "Vec after x2 = "; print(vec); cout << endl;
    // We can also create unnamed function object
    transform(vec.begin(),vec.end(), vec.begin(), Multiplier(10)); 
    cout << "Vec after x10 = "; print(vec); cout << endl;
    // Using function pointers
    transform(vec.begin(),vec.end(), vec.begin(), mulby2); 
    cout << "Vec after x2 = "; print(vec); cout << endl;
    
    string ex {"Example\n"};
    Displayer<string> str_display; // Note that this an object
    str_display(ex); // But we are using it as a function
    
    cout << "\rUsing function objects to display vector elements with std::for_each\n";
    for_each(vec.begin(), vec.end(), Displayer<int>());
    
    cout << "\nUsing Lambdas to display vector elements with std::for_each\n";
    for_each(vec.begin(), vec.end(), [](int x){cout << x << " ";});cout << endl;
    
    ////////////////// Lambda Expressions ////////////////////
    
    // One simple example
    // Note the () at the end is needed to execute this lambda
    // The compiler will use this to create an unnamed function object
    // No context, No parameters
    [](){cout << "This is printed with a lambda expression\n";}(); 
    
    // We can assign lambdas to variables
    
    auto L = [](int x, int y){ cout << x + y << endl;};
    
    L(3,6);// Basically a function object
    
    // Specifying a return type
    // In this example it is OK if "-> int" is omitted
    auto L2 = [](int x, int y) -> int {return x+y;};
    
    cout << "Using lambdas to add 3 and 4 ==> " << L2(3,4) << endl;
    
    return 0;
}