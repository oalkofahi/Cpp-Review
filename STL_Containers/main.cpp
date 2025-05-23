/*
 * STL Containers are data structures that can store ALMOST any type
 * - Template-based classes
 * - Some member functions are common to all containers some are not
 * - Each container has a specific header associated with it
 * 
 * Common Methods and Iterators (not all containers support all of the listed iterators):
 * - Default Constructors: to initialize empty containers
 * - Overloaded Constructors: to initiate containers in different ways
 * - Copy and Move constructors
 * - Destructors
 * - Copy and Move assignment
 * - size: returns the number of elements in container
 * - empty: is container empty? returns true or false
 * - insert: insert element into container
 * - operators <, =<, >, >=, ==, and != pair-wise comparison
 * - swap: swaps the elements of 2 containers
 * - erase: erase elemnt(s) 
 * - clear: remove all elements
 * - begin and end: iterators to first and AFTER last elements
 * - cbegin and cend: constant iterators to first and AFTER last
 * - crbegin crend: constant reverse iterators to first and AFTER last
 * 
 * To use STL containers with our classes we MUST:
 * - provide Copy and Move constructors and assignments
 * For associative containers (ordered ones), we MUST also:
 * - Implement comparison operators. At least < and == 
 * 
 * 
 * Iterators abstract a container as a sequence of elements
 * - We don't need to know how the container is implemented
 * - Could be finite or infinite 
 * - By design they are similar to pointers
 * 
 * Declaring iterators:
 * - MUST be decalred based on the container type it will iterate over:
 *  
 *          container_type::iterator_type iterator_name
 *  Examples:
 *  - std::vector<int>::iterator it1; // can ony be used on a vector of integers
 *  - std::map<std::string, std::string>::iterator it2; // can only be sued on a map of straing pairs
 * 
 * Iterators Operations:
 * - post and pre increment ++it, it++ (supported by ALL)
 * - post and pre deccrement --it, it-- (supported by bidirectional iterators (ones that can go back))
 * - assignment it1 = it2 (supported by all)
 * - Dereference *it (like pointers) (supported by input and output iterators)
 * - Arrow it-> (supported by input and output iterators)
 * - Equality and inequality ==, and != (supported by input iterators)
 * - Comparison: >, >=, <, <= (supported by random access iterators)
 * - 
 */

#include <iostream>
#include<vector>
#include<set>
#include<list>
#include<map>

using namespace std;

int main()
{
    vector<int> vec {1,2,3};
    
    vector<int>::iterator it_start = vec.begin();
    //OR more conveniently
    auto it_start2 = vec.begin();
    
    // Note the pointer notation
    while (it_start != vec.end())
    {
        cout << *it_start << " ";
        ++it_start;
    }
    cout << endl;
    // Can this iterator go back?
    it_start-=2; // Yes you can go back
    
    cout << "After decrement: " << *it_start << endl;
    for(;it_start2 != vec.end(); it_start2++)
        cout << *it_start2 << " ";
    cout << endl;
    
    set<char> suits {'C', 'H', 'S', 'D'};
    
    for(auto it = suits.begin(); it != suits.end(); it++)
        cout << *it << " "; // << end;
    cout << endl;
    
    // revers iterator
    vector<int>::reverse_iterator rit = vec.rbegin(); // Note the rbegin
    
    while(rit != vec.rend()) {
        cout << *rit << " ";
        rit++;
    }
    
    cout << endl;
    
    list<int> lst{10,20,30};
    
    // constant reverse it
    auto clst_it = lst.crbegin(); // cannot modify list through this iterator
    
    // reverse it
    auto lst_it = lst.rbegin(); 

    *lst_it = 40;
    //*clst_it = 50; // ERROR: cannot modify list
    
    cout << *lst_it << endl;
    cout << *clst_it << endl;
    
    lst_it++;
    clst_it++;
    
    cout << *lst_it << endl;
    cout << *lst_it << endl;
    
    lst_it--;
    clst_it--;
    
    cout << *lst_it << endl;
    cout << *lst_it << endl;
    
    
    
    // Maps
    map<string, string> fav{
        {"Hello", "Hi"},
        {"Love", "like"},
        {"Hit", "Cry"}
        };
    
    auto map_it = fav.begin();
    
    while (map_it != fav.end())
    {
        // We can use dereferncing or the arrow operator
        // Note that you need to derefernce the iterator first, then use the Dot operator
        cout << (*map_it).first << " is related to "
        << map_it->second << endl;
        advance(map_it, 1); // == map_it++
    }
    
    
    // Last example
    vector<int> last_vec{1,2,3,4,5,6,7,8,9,10};
    auto vec_it1 = last_vec.begin() + 2; // points to 3
    auto vec_it2 = last_vec.end() - 2; // points to 9
    
    while(vec_it1 <= vec_it2)
    {
        cout << *vec_it1 << " ";
        vec_it1++;
    }
    cout << endl;
    
    return 0;
}