/*
 * Sets and Maps are associative containers
 * - Associative: fast retrievals using a key
 * - Usually implemented using balanced binary trees (RB-Trees) or hashsets
 * 
 * Sets:
 * - std::set NEEDs #include<set> and does not allow duplicates
 * - std::unordered_set NEEDs #include<unordered_set>
 * - std::multiset
 * - std::unordered_multiset
 * 
 * Sets allow changing elements in-place
 * 
 * Unordered sets DO NOT allow in-place modifications (because of implementation)
 * - elements MUST be erased first then the new (modified) value inserted
 * 
 * Does not allow direct access ==> Cannot use [] and .at()
 * Concept of front() and back() does not apply
 * - push_back, pop_back, push_front, and pop_front does not apply
 * 
 * For ordered set variations the operator< MUST be overloaded
 * 
 * We can use insert() and emplace() to add elements to set
 * - returns a pair<iterator, bool>
 * - the iterator points to the inserted elements or to an existing elements if it has the same value
 * - bool will be true if insertion was successfull
 * 
 * Maps, like Sets, we have:
 * - std::map NEEDs #include<map>
 * - std::unordered_map
 * - std::multimap
 * - std::unoredered_multimap
 * 
 * Maps:
 * - Store key-value pairs (using std::pair)
 * - Ordered by key
 * - No duplicate key values
 * - Direct access using keys
 * 
 * Maps ALLOW direct access ==> we can use [] and .at()
 * - [] can be used to access exisiting members
 * - [] can also be used to add new pairs
 * - at() can only be used to access exisiting pairs. If a key does not exist it will through an error
 * 
 */ 
#include <iostream>
#include <set>
#include <map>

using namespace std;

class Person {
    friend ostream & operator<<(ostream & out, const Person &p);
    int age;
    string name;
public:
    Person() : age{0} , name{"No Name"} {}
    Person(string n, int a): age{a}, name{n} {}
    
    bool operator<(const Person &rhs) const
    {
        return age < rhs.age;
    }
    
    bool operator<(const int &rhs) const
    {
        return age < rhs;
    }
    
    bool operator==(const Person &rhs) const
    {
        return (name == rhs.name && age == rhs.age);
    }
};

ostream & operator<<(ostream & out, const Person &p)
{
    out << p.name << ":" << p.age;
    return out;
}


template<typename T>
void print(const T& s)
{
    for (const auto &e: s)
        cout << e << " ";
}


int main()
{
    set<int> s{1,1,2,3,2,4}; // will automatically remove duplicates of 1 and 2
    
    print(s); cout << endl;
    
    cout << s.size() << endl;
    cout << s.max_size() << endl;
    
    s.insert(-1);
    s.insert(8);
    
    print(s);cout << endl;
    
    s.insert(5);
    
    print(s);cout << endl;
    
    // checking return value of insert
    
    auto p = s.insert(5);//duplicate
    
    cout << "Iterator points to: " << *(p.first) << endl;
    cout << "Insertion was " << (p.second == true ? "successful\n" : "failure\n");
    
    p = s.insert(6);//new value
    
    cout << "Iterator points to: " << *(p.first) << endl;
    cout << "Insertion was " << (p.second == true ? "successful\n" : "failure\n");
    
    auto res = s.erase(6); // returns 1 or 0
    
    print(s);cout << endl;
    
    cout << res << endl;
    
    // Use set.count() to determine membership
    cout << "5 is " << (s.count(5)==1? "in ": "not int ") << "the set\n"; 
    
    // Print using iterators
    auto it = s.begin();
    while(it != s.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    
    // Sets of objects
    
    set<Person> people {{"Ali", 22}, {"John", 20}, {"James", 25}};
    
    print(people);cout << endl;
    
    people.erase(Person("XXXX", 20)); // Will remove John because the set is ordered on age
    
    print(people);cout << endl;
    
    //////////////////////////   MAPS ////////////////////////////////////////
    cout << "\n\n**************** MAPS *********************\n\n";
    
    map<string, int> m {{"Ali", 22}, {"John", 20}, {"James", 25}};
    
    // Note that map is sorted on key which is the name in this example
    // The following will print Ali, then James, then John
    for(auto &p: m)
        cout << p.first << ":" << p.second << " ";
    cout << endl;
    
    // Inserting using functions
    m.insert(pair<string, int>("Bob", 30));
    m.insert(make_pair("Ann",21));
    m.emplace("Zack", 27);
    
    for(auto &p: m)
        cout << p.first << ":" << p.second << " ";
    cout << endl;
    
    // Inserting using subscript
    m["Zoro"] = 31;
    m["Dan"] = 29;
    //m.at("Charlie") = 33; // ERROR: Cannot insert, but can update with at()
    m.at("Dan") = 39; // Update is OK
    
    for(auto &p: m)
        cout << p.first << ":" << p.second << " ";
    cout << endl;
    
    // res defined above
    cout << "Erasing George ==> ";
    res = m.erase("George");
    
    cout << "Erase " << (res==1? "succeeded\n": "failed\n");
    
    cout << "Erasing Ann ==> ";
    res = m.erase("Ann");
    
    cout << "Erase " << (res==1? "succeeded\n": "failed\n");
    
    for(auto &p: m)
        cout << p.first << ":" << p.second << " ";
    cout << endl;
    
    return 0;
}