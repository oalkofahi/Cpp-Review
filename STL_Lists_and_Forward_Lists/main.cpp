/*
 * NON CONTIGUOUS MEMORY
 * - No direct access ==> CANNOT use [] or .at()
 * 
 * Efficieint for insertions and removals in the middle once the position is found
 * 
 * For Lists efficient insertion and deleteion from front and back
 * - Can use all push_back, push_front, emplace_back, emplace_from, pop_back, and pop_front
 * 
 * For Forward Lists, insertions and deletions at fron or position in the middle is efficient
 * - back operations are not available
 * 
 * List and Forward lists iterators DO NOT SUPPORT + or -
 * - You can use the advance() function form #include<iterator>
 * - Note that ++ or -- are OK for lists (for forward lists only ++)
 * 
 * Lists are Bidirectional
 * - Doubly linked list
 * 
 * Forward Lists are unidirectional: only forward
 * - reverse iterators are not available
 * 
 * Lists NEED #include<list>
 * 
 * Forward Lists NEED #include<forward_list>
 * 
 * For Forward lists the following is NOT AVAILABLE:
 * - size()
 * - back()
 * - push_back()
 * - pop_back()
 * - emplace_back()
 * 
 * For Forward lists we have:
 * - insert_after()
 * - erase_after()
 * - emplacee_after()
 * 
 */
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <iterator>

using namespace std;

template<class Container>
void print(const Container &lst)
{
    for (const auto &e: lst)
        cout << e << " ";
}


int main()
{
    list<int> lst {1,2,3,4};
    
    vector<int> vec {10,20,30};
    cout << "List is: "; print(lst); cout << endl;
    
    cout << "Vector is: "; print(vec); cout << endl;
    
    
    auto pos = find(lst.begin(), lst.end(), 3);
    
    lst.insert(pos, vec.begin(), vec.end());
    
    cout << "List after inserting vec before 3 = ";
    print(lst); cout << endl;
    
    copy(vec.begin(), vec.end(), back_inserter(lst));
    cout << "List after back inserting vec = ";
    print(lst);cout << endl;
    
    // resize
    
    lst.resize(3);
    
    cout << "List after resizing to 3 = ";print(lst); cout << endl;
    
    lst.resize(5);
    
    cout << "List after resizing to 5 = ";print(lst); cout << endl;
    
    
    // FORWARD LISTS
    
    forward_list<int> flst {1,2,3,4};
    
    auto it = flst.end();
        
    //it--; // ERROR going back is not supported
    
    // ERROR forward list does not have push_back method
    //copy(vec.begin(), vec.end(), back_inserter(flst)); 
    
    copy(vec.rbegin(), vec.rend(), front_inserter(flst));
    cout << "Forward list after copying vec to its front = "; print(flst); cout << endl;
    
    it = find(flst.begin(), flst.end(), 3);
    flst.insert_after(it, vec.begin(), vec.end());
    cout << "Forward list after inserting vec after 3 = "; print(flst); cout << endl;
    
    it = flst.begin();
    
    //it += 2; // ERROR Does not work for lists or forward lists
    // Use the advance function
    advance(it, 2);
    // advance(it, -1); // ERROR YOU CANNOT GO BACK IN A FORWARD LIST
    
    cout << *it << endl;
        
    return 0;
}