#include <iostream>

using namespace std;
/*
 * The idea is to create a blueprint
 * The data types get plugged-in later
 * The compiler generates appropriate functions
 * 
 * To define a template, we use a place holder for data type and tell it that this is a template:
 * 
 *      template <typename T>
 *      
 *      T function (T arg1, T arg2) {
 *          // Do something
 *      }
 * 
 * Note that:
 * - "typename" can be replaced with "class"
 * - T is just a name, you can use anything else
 */
 
 // Define a template for a max function
 // Of course this template can be used with ANY type that SUPPORTS operator>
 template <typename T>
 T Max(const T &a, const T &b)
 {
     return (a > b) ? a : b;
 }
 
 // using class instead of typename and X instead of T
 template <class X>
 X Min(const X &a, const X &b)
 {
     return (a < b) ? a : b;
 }
 
 template <typename T1, typename T2>
 void func(const T1 &a, const T2 &b)
 {
     for (int i = 0; i < a; i++)
         cout << b << " ";
     cout << endl; 
 }
 
 template <typename T>
 void func(const int &a, const T &b)
 {
     for (int i = 0; i < a; i++)
         cout << b << " ";
     cout << endl; 
 }
 
 



int main()
{
    cout << Max<int>(1, 3) << endl;
    cout << Max<double>(12.4, 3.5) << endl;
    cout << Min<char>('a', 'b') << endl;
    func<int, char> (10, 's');
    
    return 0;
}