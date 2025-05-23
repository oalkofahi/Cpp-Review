/*
 * Some useful algorithms in STL
 * - Different containers support different algorithms
 * 
 * Iterator Invalidation: 
 * - It is possible for iterators to become invalid during processing
 * - For example: during iterating over a vector, some condition resulted in calling vector.clear()
 * - In this case, the iterator will be pointing to invalid locations
 * - Results in undefined behavior
 */ 

#include <iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<cctype>

void Square_function(int x)
{
    std::cout << x * x << " ";
}

class Person
{
    friend std::ostream & operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
    
public:
    Person() = default; // compiler generated default constructor
    Person(std::string n, int a) : name{n}, age{a} {}
//    Person(Person &&other) : name{other.name}, age{other.age} {}
//    
//    Person & operator=(const Person &other) {
//        name = other.name;
//        age  = other.age;    
//        return *this;
//    }
    
    bool operator<(const Person &rhs)
    {
        // We chose to compare less than based on age
        return this->age < rhs.age; // Note that using "this" pointer is optional
    }
    
    bool operator<(const int &rhs)
    {
        // We chose to compare less than based on age
        return this->age < rhs; // Note that using "this" pointer is optional
    }
    
    bool operator==(const Person &rhs)
    {
        return name == rhs.name && age == rhs.age;
    }
    
    
    
};

std::ostream & operator<<(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << "\nAge: " << p.age << '\n';
    return os;
}

int main()
{
    using namespace std;
    
    vector<int> vec{1,2,3,4,5};
    auto loc = find(vec.begin(), vec.end(), 3);
    ////// find function //////
    // find returns an iterator pointing to the first occurrance of element if it is found
    // If element is not found, the returned iterator will point to the end
    // To use find() on user defined classes, we need to implement the == operator
    if(loc != vec.end())
        cout << *loc << endl;
        
        
    // using find on Person objects
    vector<Person> person_vec{
        Person{"Ali", 22},
        Person{"Hamad", 23},
        Person{"John", 25},
        Person{"Ali", 22},
        Person{"Rami", 20},
        Person{"Hani", 21}
        };
    
    // The following works because operator== is overloaded for Person
    auto loc1 = find(person_vec.begin(), person_vec.end(), Person{"Ali", 22});
    
    if(loc1 != person_vec.end())
        cout << *loc1 << endl;// Works because operator<< is overloaded for Person
    
    
    ////// count ///////
    int Ali_count = count(person_vec.begin(), person_vec.end(), Person{"Ali", 22});
    
    cout << "Found Ali " << Ali_count << " times\n";
    
    
    ///// count_if //////
    int odd_count = count_if(vec.begin(), vec.end(), [] (int x) {return x%2 == 1;});
    cout << "Odd numbers count in vector = " << odd_count << endl;
    
    int younger_than_23_count = count_if(person_vec.begin(), person_vec.end(), [] (Person p) {return p < 23;} );
    cout << "Number of people younger than 23 = " << younger_than_23_count << endl;
    
    
    ///// replace //////
    // print vec
    for(auto n: vec)
        cout << n << " ";
    cout << '\n';
    
    // replace 3 with 9
    replace(vec.begin(), vec.end(), 3, 9);
    
    // print vec
    for(auto n: vec)
        cout << n << " ";
    cout << '\n';
    
    ////// all_of & any_of //////
    if(all_of(vec.begin(), vec.end(), [] (int x){return x < 10;}))
        cout << "All vector elements are < 10\n";
    else
        cout << "Not all vector elements are < 10\n";
        
        
    ///// transform /////
    transform(vec.begin(), vec.end(),vec.begin(), [](int x){return x+3;});
    
    for(auto n: vec)
        cout << n << " ";
    cout << '\n';
    
    ////// for_each /////
    // applies a function to each element in the iterator sequence
    // The applied function MUST be one of the following:
    // - Functor (function object)
    // - Function pointer
    // - Lambda expression
    
    // Exmaple apply square to each element
    struct Square_Functor {
        // Overload the () operator
        void operator() (int x) {
            cout << x * x << " ";
        }        
    };
    
    Square_Functor squ;
    
    for_each(vec.begin(), vec.end(), squ);
    
    cout << '\n';
    
    for_each(vec.begin(), vec.end(), Square_function);
    
    cout << '\n';
    
    for_each(vec.begin(), vec.end(),
     [] (int x) { cout << x*x << " ";}); // lambda expression
    
    cout << '\n';
    
    
    
    
    return 0;
}