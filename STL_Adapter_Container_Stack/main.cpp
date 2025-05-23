/*
 * Stack: LIFO
 * - Implemented as an adapter over STL containers list, deque, or vector (anything with a back)
 * - NEEDs #include<stack>
 * - We can choose which underlying STL container to implement the stack object
 * 
 * To declare a stack:
 *  
 *              std::stack<TYPE, std::CONTAINER<TYPE>> NAME;
 * Example:
 *              std::stack<int, std::vector<int>> s1; //uses a vector
 * 
 * By default, the underlying container will be a deque
 * 
 * Standard stack methods:
 * - push, pop, top (peek), empty, size
 * 
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<int, vector<int>> stk1;
    stack<int> stk2;
    
    stk1.push(10);
    stk2.push(20);
    
    cout << stk1.pop() << endl;
    
    return 0;
}