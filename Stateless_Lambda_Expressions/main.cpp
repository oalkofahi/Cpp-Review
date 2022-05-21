/*
 * Remember, a Lambda expression looks like:
 * 
 *          [] () -> return_type specifiers {};
 * 
 * A lambda is stateless if it knows NOTHING about its environment
 * - It only knows its paramaters
 * 
 * Lambdas can be passed as function parameters
 * - NEEDs #include <functional> This is in C++14 
 * - Use std::function
 * - In C++20 we can just use auto
 * 
 * 
 * Lambdas can also be returned
 * - again you can use the same three options above std::function, function pointers, or auto in C++20
 * 
 */ 

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// A function that accepts a Lmbda
// the <> say that the function returns nothing (this is the void) and accepts an int
// The function name is l inside this fun
void fun(function<void(int)> l)
{
    l(5);
}

// We can also do this using funtion pointers
void fun2(void (*l) (int))
{
    l(5);
}

// or in C++20 we can simply write
// But I was using C++14 at the time :(
//void fun3(auto l)
//{
//    l(5);
//}

// Returning lambdas from functions

std::function<void(int)> ret1()
{
    return [] (int x) {cout << x;};
}

// or 

void (*ret2()) (int) 
{
    return [] (int x) {cout << x;};
}

// or 

auto ret3() 
{
    return [] (int x) {cout << x;};
}

int main()
{
    // Example 1
    int x {10}; // (1)
    
    // Defining and calling a lambda
    [] (int x) {cout << x << endl;}(100); // will this use the x from (1) above?
    // No because it is stateless ==> it only sees its parameters
    
    // Example 2
    // Declare an array of size 3
    const int n {3};
    int nums[n] {10, 20, 30};
    // define a lambda function that takes two parameters (array, size) and sums the array
    // This basically creates a function object and stores it in sum
    // Note that even though the parameters have the same names as the variables above
    // There will be no conflicts because the lambda is stateless
    auto sum = [] (int nums[], int n) {
        int sum {0};
        for(int i = 0; i < n; i++)
            sum += nums[i];
        return sum;        
    };
    
    cout << sum(nums, n) << endl;
    
    // Example 3: passing by reference with aliases or pointers
    int score {88};
    
    auto bonus = [] (int &x, int bonus) { x += bonus;  };
    auto bonus2 = [] (int *x, int bonus) {*x += bonus;};
    
    
    bonus(score, 5);
    bonus2(&score, 5);
    cout << "Score after bonus = " << score << endl;
    
    // Example 4: working with objects
    
    vector<int> scores{70, 55, 78, 86};
    
    cout << "\nOriginal scores:\n";
    for(int &i: scores)
        cout << i << " ";
    cout << endl;
    
    auto bonus3 = [] (vector<int> &vec, int bonus) {
        for(int &n: vec)
            n += bonus;        
    };
    
    bonus3(scores, 5);
    
    cout << "Vector score now has:\n";
    for(int &i: scores)
        cout << i << " ";
    cout << endl;
    
    // Example 5: same as 4 but allowing the lambda to work with multiple types
    
    vector<float> fscores{70.5, 55.3, 78.6, 86.9};
    
    cout << "\nOriginal float scores:\n";
    for(float &i: fscores)
        cout << i << " ";
    cout << endl;
    
    auto bonus4 = [] (auto &vec, int bonus) {
        for(auto &n: vec)
            n += bonus;        
    };
    
    bonus4(scores, 1);
    bonus4(fscores, 5);
    
    cout << "Integer Vector score after using generic lambda:\n";
    for(int &i: scores)
        cout << i << " ";
    cout << endl;
    
    cout << "Float Vector scores after using generic lambda:\n";
    for(auto &i: fscores)
        cout << i << " ";
    cout << endl;
    
    
    // Example 6: returning lambdas from functions
    
    auto lam1 = ret1();
    cout << "Trying returned lambda: ";
    lam1(10000);cout << endl;
    
    return 0;
}