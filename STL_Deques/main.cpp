/*
 * Deque = Double Ended Queue
 * NEEDS #include<deque>
 * UNLIKE Vectors and Arrays, elements are not stored in contiguous memory locations
 * - Insertion or deletion in linear time
 * CAN grow and shrink in size 
 * MORE EFFICIENT than vectors in insertions and deletions FROM BOTH ENDS
 * - Constant time
 * - Vectors are efficient only if we are inserting or removing from back
 */

#include <iostream>
#include <deque>
#include <vector>

template<typename T>
void print(const std::deque<T> &d)
{
    for(const auto &e: d)
        std::cout << e << " ";
}

int main()
{
    using namespace std;
    
    deque<int> deq {1,2,3};
    
    deq.push_back(4);
    deq.push_front(0);
    print(deq);cout << endl;
    
    
    vector<int> vec{10,20,30};
    
    cout << "Inserting elements from a vector to the back and front of deq\n";
    copy(vec.begin(), vec.end(), back_inserter(deq));
    // vector will be reveresed if we use vec.begin() and vec.end()
    // That is why the reverse iterators
    copy(vec.rbegin(), vec.rend(), front_inserter(deq)); 
    
    print(deq); cout << endl;
    
    return 0;
}