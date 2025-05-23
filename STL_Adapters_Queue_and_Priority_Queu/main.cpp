/*
 * Can be implememted using list and deque (anything with a front and a back)
 * - default is deque
 * - elements can be push and popped from front and back
 * 
 * No iterators are supported
 * - Caanot use STL algorithms
 * 
 * Standard methods:
 * - push: add to back of queue
 * - pop: remove from front of queue
 * - front: access front
 * - back: access back
 * - empty and size
 * 
 * To declare a queue:
 * 
 *              std::queue<TYPE, std::CONTAINER<TYPE>> NAME;
 * 
 * Example:
 *              std::queue<int, std::list<int>> q;
 * 
 * 
 * ////////////////////// PRIORITY QUEUE ////////////////////////////
 * 
 * Allows the insertion and removal of elements in order from the front of the container
 * - Elements are inserted in priority order
 * - Largest value at the front alwyas
 * - This is a heap basically (max heap)
 * 
 * Implmeneted using vectors by default
 * 
 * No iterators supported
 * - Cannot use STL algorithms
 * 
 * Needs #include<queue>
 * 
 * Supports standard methods:
 * - push: insert element in order
 * - pop: remove top element (max)
 * - top: acceess top element
 * - empty and size
 * 
 */

#include <iostream>
#include <queue>
#include <list>
#include <tuple>
using namespace std;

// Accepts a copy
// the copy is destroyed to print
void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int, list<int>> q1; // needs #include<list>
    queue<int> q2;
    
    q1.push(1);
    q1.push(2);
    //print(q1); // ERROR: function does not match because q1 is implmeneted using a list
    //print(q1);
    
    // One way to initialize a queue
    for(int i: {10,20,30,40,50,60})
        q2.push(i);
    
    print(q2); // print takes a copy
    print(q2);
    
    
    ////////////////////////// PRIORITY QUEUE ////////////////////////
    
    priority_queue<pair<string, int>> hp;
    
    hp.emplace("Ali",20);
    hp.emplace("Zack",30);
    hp.emplace("Hani", 40);
    
    while(!hp.empty()){
        cout << hp.top().first << ":" << hp.top().second << endl;
        hp.pop();
    }
    
    
    priority_queue<tuple<int, int, int>> hp2;
    
    hp2.emplace(4,5,6);
    hp2.emplace(4,5,5);
    hp2.emplace(4,6,6);
    hp2.emplace(2,5,6);
    
    while(!hp2.empty())
    {
        auto t = hp2.top();
        cout << get<0>(t) << get<1> (t) << get<2>(t) << endl;
        hp2.pop();
    }
    cout << endl;
    
    return 0;
}